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
#include <QPainter>

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

private:
    Ui::MainWindow *ui;

    bool createConnection();//建立数据库连接
    QSqlDatabase db;
    QSqlQuery query;
    QSqlTableModel *model;
    QWidget* paint_window;
    QPainter paint;
    void paintEvent(QPaintEvent* event);
};

#endif // MAINWINDOW_H
