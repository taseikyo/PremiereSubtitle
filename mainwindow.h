#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QDesktopServices>
#include <QRegExp>
#include <QMessageBox>
#include <QTextCodec>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_module_btn_clicked();

    void on_word_btn_clicked();

    void on_out_btn_clicked();

    void on_open_clicked();

    void on_start_clicked();

    void on_module_edit_textChanged(const QString &arg1);

    void on_word_edit_textChanged(const QString &arg1);

    void on_out_edit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QString modulePath;//module path
    QString wordPath;//subtitle path
    QString outPath;//out files directory
};

#endif // MAINWINDOW_H
