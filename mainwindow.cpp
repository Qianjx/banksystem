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
    db.removeDatabase("mybms");
    delete ui;
}

bool MainWindow::createConnection()
{

    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("bank_system");
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
    model->setTable("client");
    model->select();
}

void MainWindow::on_LoanquerypushButton_clicked()
{
    model->setTable("loan");
    model->setFilter(QString("bankname='%1'").arg(currentcity));
    model->select();
}

void MainWindow::on_AccountquerypushButton_clicked()
{
    model->setTable("storeaccont");
    model->setFilter(QString("bankname='%1'").arg(currentcity));
    model->select();
}

void MainWindow::on_ClerkquerypushButton_clicked()
{
    model->setTable("staff");
    model->setFilter(QString("bankname='%1'").arg(currentcity));
    model->select();
}

void MainWindow::on_ClientaddpushButton_clicked()
{
    model->setTable("client");
    model->select();
    int row_num=model->rowCount();
    QString book_id;
    model->insertRow(row_num);
    model->setData(model->index(row_num,0),book_id);
    model->submitAll();
}

void MainWindow::on_NewLoanPushButton_clicked()
{
    model->setTable("loan");
    model->select();
    int row_num=model->rowCount();
    QString book_id;
    model->insertRow(row_num);
    model->setData(model->index(row_num,0),book_id);
    model->submitAll();
}

void MainWindow::on_NewAccontpushButton_clicked()
{
    model->setTable("storeaccount");
    model->select();
    int row_num=model->rowCount();
    QString book_id;
    model->insertRow(row_num);
    model->setData(model->index(row_num,0),book_id);
    model->submitAll();
}

void MainWindow::on_NewClerkpushButton_clicked()
{
    model->setTable("clerk");
    model->select();
    int row_num=model->rowCount();
    QString book_id;
    model->insertRow(row_num);
    model->setData(model->index(row_num,0),book_id);
    model->submitAll();
}



void MainWindow::on_ClientSubmitpushButton_clicked()
{
    model->database().transaction();
    if(model->submitAll())
    {
        if(model->database().commit())

            QMessageBox::information(this,tr("数据库反馈"),tr("书籍入库成功"));
            QMessageBox::about(0,"mybms",tr("提交修改成功！"));

    }
    else{
        model->database().rollback();
        QMessageBox::warning(this,tr("数据库反馈"),
                             tr("发生错误:%1").arg(model->lastError().text()),
                             QMessageBox::Ok);
    }
}

void MainWindow::on_DeletepushButton_clicked()
{
    int cur_row=ui->show_tableView->currentIndex().row();
    int ok=QMessageBox::warning(this,tr("删除这个表项"),tr("您确定删除当前行吗？"),
                                QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::Yes){
        model->removeRow(cur_row);
        model->submitAll();
    }
    else
        return;
}

void MainWindow::on_StasticpushButton_clicked()
{

    paint_window->show();

}

void MainWindow::on_delete1pushButton_clicked()
{
    int cur_row=ui->show_tableView->currentIndex().row();
    int ok=QMessageBox::warning(this,tr("删除这个表项"),tr("您确定删除当前行吗？"),
                                QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::Yes){
        model->removeRow(cur_row);
        model->submitAll();
    }
    else
        return;
}

void MainWindow::on_delete2pushButton_clicked()
{
    int cur_row=ui->show_tableView->currentIndex().row();
    int ok=QMessageBox::warning(this,tr("删除这个表项"),tr("您确定删除当前行吗？"),
                                QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::Yes){
        model->removeRow(cur_row);
        model->submitAll();
    }
    else
        return;
}

void MainWindow::on_delete3pushButton_clicked()
{
    int cur_row=ui->show_tableView->currentIndex().row();
    int ok=QMessageBox::warning(this,tr("删除这个表项"),tr("您确定删除当前行吗？"),
                                QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::Yes){
        model->removeRow(cur_row);
        model->submitAll();
    }
    else
        return;
}

void MainWindow::on_SelectcitycomboBox_currentIndexChanged(int index)
{
    currentline=index;
}

void MainWindow::on_SelectcitycomboBox_currentIndexChanged(const QString &arg1)
{
    currentcity=arg1;
}

