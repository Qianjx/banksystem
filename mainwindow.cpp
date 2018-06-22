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
    model->setTable("storeaccount");
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
    model->setTable("staff");
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

void MainWindow::on_StasticpushButton_clicked()
{
    static_window=new QTableWidget(4,3);
    QTableWidgetItem *Item12 = new QTableWidgetItem(tr("存款总量"));
    static_window->setItem(0, 1, Item12);
    QTableWidgetItem *Item13 = new QTableWidgetItem(tr("贷款总量"));
    static_window->setItem(0, 2, Item13);
    QTableWidgetItem *Item21 = new QTableWidgetItem(tr("Beijing"));
    static_window->setItem(1, 0, Item21);
    QTableWidgetItem *Item31 = new QTableWidgetItem(tr("Hefei"));
    static_window->setItem(2, 0, Item31);
    QTableWidgetItem *Item41 = new QTableWidgetItem(tr("Shanghai"));
    static_window->setItem(3, 0, Item41);


    QSqlQuery query=QSqlQuery(db);
    query.exec("select sum(total) as sum from loan group by bankname");

    QSqlRecord rec = query.record();
    int nameCol = rec.indexOf("sum");
    query.next();
    QTableWidgetItem *Item23 = new QTableWidgetItem((query.value(nameCol).toString()));
    static_window->setItem(1, 2, Item23);
    query.next();
    QTableWidgetItem *Item33 = new QTableWidgetItem((query.value(nameCol).toString()));
    static_window->setItem(2, 2, Item33);
    query.next();
    QTableWidgetItem *Item43 = new QTableWidgetItem((query.value(nameCol).toString()));
    static_window->setItem(3, 2, Item43);

    query.exec("select sum(rest) as sum from storeaccount group by bankname");
    nameCol = rec.indexOf("sum");
    query.next();
    QTableWidgetItem *Item22 = new QTableWidgetItem((query.value(nameCol).toString()));
    static_window->setItem(1, 1, Item22);
    query.next();
    QTableWidgetItem *Item32 = new QTableWidgetItem((query.value(nameCol).toString()));
    static_window->setItem(2, 1, Item32);
    query.next();
    QTableWidgetItem *Item42 = new QTableWidgetItem((query.value(nameCol).toString()));
    static_window->setItem(3, 1, Item42);

    static_window->show();
}

void MainWindow::on_SelectcitycomboBox_currentIndexChanged(int index)
{
    currentline=index;
}

void MainWindow::on_SelectcitycomboBox_currentIndexChanged(const QString &arg1)
{
    currentcity=arg1;
}

