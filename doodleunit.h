#ifndef DOODLEUNIT_H
#define DOODLEUNIT_H

#include <QObject>
#include <QPoint>

#include "doodleobject.h"


class DoodleUnit : public DoodleObject
{
    Q_OBJECT

public:
    DoodleUnit();
    DoodleUnit(QPoint &position);

public slots:
    bool checkAdjoin() { return false; }
    QPoint getObjectPosition();

signals:

private:
    QPoint m_qpObjectPosition;
};

#endif // DOODLEUNIT_H
