
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtCore>
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QtWebKitWidgets/QWebView>
#include <QtXml/QDomElement>
#include <QThread>
#include <QWebFrame>
#include <QWebElement>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkCookieJar>
#include <QNetworkCookie>

//#include <QFileDialog>
//#include <QtXml/QDomDocument>
//#include <QtXml/QDomNode>
//#include <QFile>
//#include <QHeaderView>
//#include <QLabel>
//#include <QUrl>
//#include <QDebug>
//#include <QXmlStreamReader>
//#include <QTableWidget>
//#include <QTableWidgetItem>
//#include <QObject>
//#include <QProcess>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSettings *settings;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void scanoutput();
    void crackoutput();
    void xmlRead(QDomElement raiz, QString tag, QString atributo, int coluna);
    void on_pushButton_3_clicked();
    void scanfinished();
    void crackfinished();
    void reverseIP(QString ip);
    void whois(QString ip);
    void on_comboBox_3_currentIndexChanged(int index);
    void exploit();
    void on_pushButton_5_clicked();
    void on_webView_urlChanged();
    void on_webView_3_urlChanged();
    void on_pushButton_4_clicked();
    void on_webView_2_urlChanged();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_comboBox_5_currentIndexChanged(int index);
    void createMenus();
    void openDialog();

private:
    QMenu *configMenu;
    QMenu *exitMenu;
    Ui::MainWindow *ui;
    QProcess *scanprocess; //nmap process
    QProcess *crackprocess; //ncrack process
    QFile *xmlFile;
    QXmlStreamReader *xmlReader;


};

#endif // MAINWINDOW_H
