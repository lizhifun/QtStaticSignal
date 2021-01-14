#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_toola(new ToolA)//初始化ToolA对象
{
    ui->setupUi(this);
    connect(m_toola,&ToolA::SigDeliverMess,this,&MainWindow::SlotDeliverMess);//关联ToolA的信号和MainWindow的槽

    //调用ToolA中静态方法
    m_toola->Funcoo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotDeliverMess()
{
    //收到ToolA发出的信号
    qDebug() << "MainWindow received DeliverMess";
}

