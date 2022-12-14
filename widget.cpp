#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    UiInit(); //初始化UI

    OpenXML();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::UiInit()
{
    ui->treeWidget->setHeaderLabel("名称"); //treeWidget表头

    QStringList header;
    header<<"ID"<<"名称"<<"上级部门"<<"部门负责人";

    ui->tableWidget->setRowCount(254); //设置行数
    ui->tableWidget->setColumnCount(4); //设置表头
    ui->tableWidget->setHorizontalHeaderLabels(header); //tabWidget表头
}

void Widget::OpenXML()
{
    QFile file("../2022-12-14_Work/res/party.xml");
    if(file.open(QIODevice::ReadOnly))
    {
        QDomDocument dom("Diuse");
        if (dom.setContent(&file))
        {
            QDomElement docElem = dom.documentElement();
            Manager m(docElem);
        }
    }
    file.close();
}

