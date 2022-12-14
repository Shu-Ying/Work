#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QTreeWidgetItem>
#include <QDomDocument>
#include <QDomElement>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

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

};
#endif // WIDGET_H
