#ifndef MYBODY_H
#define MYBODY_H

#include <QObject>
#include <QGraphicsItem>

//物体主体
class MyBody : public QGraphicsItem
{
public:
    explicit MyBody(QGraphicsItem *parent = nullptr);

    int type() const override;

    void setColor(const QColor &color);

protected:
    QRectF boundingRect() const override;
    //painter : 此参数用于绘图；
    //option : 提供了item的风格，比如item的状态，曝光度以及详细的信息；
    //widget : 参数可选。如果提供的话，它指向正在绘制的小部件。否则为0。对于缓存的绘画，小部件始终为0。
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QPainterPath shape() const override;

private:
    QColor color{Qt::darkBlue};
};

#endif // MYBODY_H
