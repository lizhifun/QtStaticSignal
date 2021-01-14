#include "toola.h"
#include <QDebug>

ToolA *ToolA::mytoola = nullptr;//静态ToolA类 mytoola

ToolA::ToolA(QObject *parent) : QObject(parent)
{
    mytoola=this;
    connect(this,&ToolA::SigDeliverMessStatic,this,&ToolA::SlotDeliverMessStatic);//关联内部信号与槽
}

void ToolA::Funcoo()
{
    //静态函数需要发出信号
    qDebug() << "ToolA sent DeliverMess";
    emit mytoola->SigDeliverMessStatic();//发射内部信号
}

void ToolA::SlotDeliverMessStatic()
{
    emit mytoola->SigDeliverMess();//发射出去信号
}
