#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createConnection();

    model=new QSqlTableModel(this);
    ui->show_tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::createConnection()
{

    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mybms");
    db.setUserName("root");
    db.setPassword("740832Qjx");
    db.setPort(3306);

    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("error"),db.lastError().text());
        return false;
    }
    return true;
}
//创建mysql连接

void MainWindow::on_ClientQuerypushButton_clicked()
{
    model->setTable("book");
    model->select();
}

void MainWindow::on_LoanquerypushButton_clicked()
{
    model->setTable("book");
    model->select();
}

void MainWindow::on_AccountquerypushButton_clicked()
{
    model->setTable("book");
    model->select();
}

void MainWindow::on_ClerkquerypushButton_clicked()
{
    model->setTable("book");
    model->select();
}
