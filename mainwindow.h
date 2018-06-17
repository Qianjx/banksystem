#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QString>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>
#include <QTextEdit>
#include <QMessageBox>


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

    void on_ClientQuerypushButton_clicked();

    void on_LoanquerypushButton_clicked();

    void on_AccountquerypushButton_clicked();

    void on_ClerkquerypushButton_clicked();

    void on_ClientaddpushButton_clicked();

    void on_ClientSubmitpushButton_clicked();

    void on_DeletepushButton_clicked();

    void on_StasticpushButton_clicked();

    void on_delete1pushButton_clicked();

    void on_delete2pushButton_clicked();

    void on_delete3pushButton_clicked();

    void on_SelectcitycomboBox_currentIndexChanged(int index);

    void on_SelectcitycomboBox_currentIndexChanged(const QString &arg1);

    void on_NewLoanPushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_NewAccontpushButton_clicked();

    void on_NewClerkpushButton_clicked();

private:
    Ui::MainWindow *ui;

    bool createConnection();//建立数据库连接
    QSqlDatabase db;
    QSqlQuery query;
    QSqlTableModel *model;
    QWidget* paint_window;

    QString currentcity;
    int currentline;

};

#endif // MAINWINDOW_H
