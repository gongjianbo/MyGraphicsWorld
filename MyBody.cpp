#include "MyBody.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QStyle>
#include <QWidget>

MyBody::MyBody(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    setAcceptDrops(true);
    setFlags(ItemIsSelectable | ItemIsMovable);
}

int MyBody::type() const
{
    return QGraphicsItem::UserType+0;
}

void MyBody::setColor(const QColor &color)
{
    this->color=color;
    update();
}

QRectF MyBody::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void MyBody::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget)
    const QRect rect=boundingRect().toRect();
    painter->fillRect(rect,color);
    if (option->state & QStyle::State_Selected){
        painter->setPen(QColor(Qt::red));
        painter->drawRect(rect);
    }
}

QPainterPath MyBody::shape() const
{
    QPainterPath path;
    path.addRect(0,0,100,100);
    return path;
}
