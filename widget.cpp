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

    //因为已知总共为一个总经理 固直接生成
    treeItem = new QTreeWidgetItem(ui->treeWidget);
    treeItem->setText(0,m->getName());
    ShowManagerItem(treeItem);

    qDebug()<<m->getMaxID();
}

/**
 * @brief Widget::ShowManagerItem 显示总经理的Item
 * @param pItem
 */
//template<T> //递归模板  //<<<弃用
void Widget::ShowManagerItem(QTreeWidgetItem *pItem)
{
    int i=0;
    while (i<m->getLength())
    {
        //创建一个节点
        QTreeWidgetItem *item;
        if(pItem)
        {
            //如果存在上个节点 那么父亲设置为上个节点
            item = new QTreeWidgetItem(pItem);
        } else
        {
            //否则 则设置到总经理节点上 /<<< 其实这里用不上这句话 因为传进的就是总经理节点
            item = new QTreeWidgetItem(treeItem);
        }

        //设置节点Flags
        item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt:: ItemIsSelectable);
        //设置文本
        item->setText(0, m->getName(i));

        //遍历子节点(部门节点
        ShowCenterItem(i,item);

        if(pItem)
        {
            //如果有父节点就将当前节点归为子节点的方式显示
            pItem->addChild(item);
        } else
        {
            //如果没有就新建一个节点显示 /<<<这里其实执行不到 因为传进来的一直为总经理节点
            ui->treeWidget->addTopLevelItem(item);
        }

        i++;
    }
}

/**
 * @brief Widget::ShowCenterItem 显示中心的Item
 * @param i 用于区分当前为哪个中心下的
 * @param pItem
 */
void Widget::ShowCenterItem(int i,QTreeWidgetItem *pItem)
{
    int num = 0;
    while (num < m->getCenterLength(i))
    {
        //创建一个节点 直接继承 不再使用繁琐的判断以节省内存
        QTreeWidgetItem *item = new QTreeWidgetItem(pItem);

        item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt:: ItemIsSelectable);
        item->setText(0, m->getCenterName(i,num));

        pItem->addChild(item);

        num++;
    }
}
