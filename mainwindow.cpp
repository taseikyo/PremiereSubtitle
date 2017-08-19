#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//module button click
void MainWindow::on_module_btn_clicked(){
    modulePath = QFileDialog::getOpenFileName(this, "Open Module File", "F:/PR/录制/PrSubtitle", "*.prtl");
    if(modulePath.isEmpty()){
        return;
    }
    ui->module_edit->setText(modulePath);
}

//word button click
void MainWindow::on_word_btn_clicked(){
    wordPath = QFileDialog::getOpenFileName(this, "Open Module File", "F:/PR/录制/PrSubtitle", "*.txt");
    if(wordPath.isEmpty()){
        return;
     }
    ui->word_edit->setText(wordPath);
}

//out button click
void MainWindow::on_out_btn_clicked(){
    outPath = QFileDialog::getExistingDirectory(this, "Open Out Files Directory", "F:/PR/录制/PrSubtitle");
    if(outPath.isEmpty()){
        return;
     }
    ui->out_edit->setText(outPath);
}

//module edit change
void MainWindow::on_module_edit_textChanged(const QString &arg1){
    modulePath = arg1;
}

//word edit change
void MainWindow::on_word_edit_textChanged(const QString &arg1){
    wordPath = arg1;
}

//out dir edit change
void MainWindow::on_out_edit_textChanged(const QString &arg1){
    outPath = arg1;
}

//open out dir button click
void MainWindow::on_open_clicked(){
    if(!outPath.isEmpty()){
        QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(outPath)));
    }
}

//start button click
void MainWindow::on_start_clicked(){
    if(modulePath.isEmpty() || wordPath.isEmpty() || outPath.isEmpty()){
        return;
    }
    QFileInfo file;
    file.setFile(modulePath);
    if(!file.isFile() || file.suffix().compare("prtl")){
        return;
    }
    file.setFile(wordPath);
    if(!file.isFile() || file.suffix().compare("txt")){
        return;
    }
    QFile m(modulePath);
    if (!m.open(QIODevice::ReadOnly | QIODevice::Text)){
            return;
    }
    QFile w(wordPath);
    if (!w.open(QIODevice::ReadOnly | QIODevice::Text)){
            return;
    }
    QTextStream word(&w);
    QTextStream module(&m);
    QString s = module.readAll();
//    qDebug()<<s.length();
    int i = 0;
    while (!word.atEnd()) {
        QString line = word.readLine();
        qDebug()<<line;
        QString rep1 = QString("<TRString>%1</TRString>").arg(line);
        QString rep2 = QString("RunCount=\"%1\" StyleRef").arg(line.length()+1);
        QString out = QString::fromUtf8("%1").arg(s.replace(QRegExp("<TRString>.*</TRString>"), rep1).replace(QRegExp("RunCount=\".*\" StyleRef"), rep2));
        //write file
        QString name = QString("%1/字幕%2.prtl").arg(outPath).arg(i);
        QFile outFile(name);
        if (!outFile.open(QIODevice::WriteOnly|QIODevice::Text)) {
            QMessageBox::critical(NULL, "提示", "无法创建文件");
            return;
        }
        QTextStream outTS(&outFile);
        outTS.setCodec(QTextCodec::codecForName("UTF-8"));
        outTS<<out<<endl;
        outTS.setGenerateByteOrderMark(true);
        outTS.flush();
        outFile.close();
        i++;
    }
}
