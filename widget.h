#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QTreeWidgetItem>
#include <QDomDocument>
#include <QDomElement>

#include "manager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//class Manager;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    Manager *m;
private:
    QTreeWidgetItem *treeItem; //主Item

    int centerNum = 0;
private:
    Ui::Widget *ui;

    /**
     * @brief UiInit Ui初始化
     */
    void UiInit();

    /**
     * @brief OpenXML 打开XML
     */
    void OpenXML();

    /**
     * @brief ShowManagerItem 显示总经理的Item
     * @param pItem
     */
    void ShowManagerItem(QTreeWidgetItem *pItem);

    /**
     * @brief ShowCenterItem 显示中心的Item
     * @param i 用于区分当前为哪个中心下的
     * @param pItem
     */
    void ShowCenterItem(int i,QTreeWidgetItem *pItem);
};
#endif // WIDGET_H
