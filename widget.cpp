#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    UiInit(); //初始化UI

    OpenXML(); //打开XML
}

Widget::~Widget()
{
    delete m;
    delete ui;
}

/**
 * @brief Widget::UiInit 初始化UI
 */
void Widget::UiInit()
{
    ui->treeWidget->setHeaderLabel("名称"); //treeWidget表头

    QStringList header;
    header<<"ID"<<"名称"<<"上级部门"<<"部门负责人";

    ui->tableWidget->setRowCount(254); //设置行数
    ui->tableWidget->setColumnCount(4); //设置表头
    ui->tableWidget->setHorizontalHeaderLabels(header); //tabWidget表头
}

/**
 * @brief Widget::OpenXML 打开XML
 */
void Widget::OpenXML()
{
    QFile file("../Work-main/res/party.xml");

    if(file.open(QIODevice::ReadOnly))
    {
        QDomDocument dom("Diuse");
        if (dom.setContent(&file))
        {
            QDomElement docElem = dom.documentElement();
            m = new Manager;
            m->parseXML(docElem);
        }
    }

    file.close();

    treeItem = new QTreeWidgetItem(ui->treeWidget);
    treeItem->setText(0,m->getName());
    ShowManagerItem(treeItem);
}

/**
 * @brief Widget::ShowItem 格式固定 索性不用递归 但是还是递归思路
 * @param pItem
 */
//template<T> //递归模板  //<<<弃用
void Widget::ShowManagerItem(QTreeWidgetItem *pItem)
{
    int i=0;
    while (i<m->getLength())
    {
        QTreeWidgetItem *item;
        if(pItem)
        {
            item = new QTreeWidgetItem(pItem);
        } else
        {
            item = new QTreeWidgetItem(treeItem);
        }

        item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt:: ItemIsSelectable);
        item->setText(0, m->getName(i));

        ShowCenterItem(item);

        if(pItem)
        {
            pItem->addChild(item);
        } else
        {
            ui->treeWidget->addTopLevelItem(item);
        }

        i++;
    }
}

void Widget::ShowCenterItem(QTreeWidgetItem *pItem)
{
    int i=0;
    while (i<m->getCenterLength())
    {
        QTreeWidgetItem *item;
        if(pItem)
        {
            item = new QTreeWidgetItem(pItem);
        } else
        {
            item = new QTreeWidgetItem(treeItem);
        }

        item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt:: ItemIsSelectable);
        item->setText(0, m->getCenterName(i));

        if(pItem)
        {
            pItem->addChild(item);
        } else
        {
            ui->treeWidget->addTopLevelItem(item);
        }

        i++;
    }
}
