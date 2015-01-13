#ifndef POLYGONENTITY_H
#define POLYGONENTITY_H

#include "mapentity.h"
#include <QString>
#include <QJsonArray>
#include <QGraphicsObject>

class PolygonEntity : public MapEntity
{
    Q_OBJECT
public:
    PolygonEntity(QGraphicsItem *parent = 0);
    PolygonEntity(const QString & name, QGraphicsItem *parent = 0);
    PolygonEntity( const QString & name, int id);
    PolygonEntity( const QString & name, int id, QPolygon poly, double area = -1);

    //copy the data from @polygon, used in subclasses
    void copy(PolygonEntity &polygon);
    //setters and getters
    const QPolygon & outline() const;
    void setOutline(const QVector<QPoint> & points);
    double area();
    void setArea(const double area);

    //add a point to tail
    void addPoint(const QPoint & p);

    //move the point at @id by @vector
    void movePoint(const int id, const QPoint & vector);

    //move the point at @id to @point
    void movePointTo(const int id, const QPoint & point);

    //insert a @point at @id
    void insertPoint(const int id, const QPoint & p);

    //remove the point at @id
    void removePoint(const int id);

    int PointNum() const;

    const QPointF & computeCenter();
    double computeArea();

    //QGraphicsItem functions
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //io
    virtual bool load(const QJsonObject & jsonObject);
    virtual bool save(QJsonObject & jsonObject) const;
protected:



    QPolygon m_outline;
    QColor m_color;
    double m_area;
};

#endif // POLYGONENTITY_H
