#include "doodleunit.h"

DoodleUnit::DoodleUnit() :
    m_qpObjectPosition(QPoint(0, 0))
{
    setObjectRect( QRect(200, 300, 60, 60) );
    setImagePath( QString("qrc:/content/data/doodle.png") );
}

DoodleUnit::DoodleUnit(QPoint &position) :
    m_qpObjectPosition(position)
{

}

QPoint DoodleUnit::getObjectPosition()
{
   return objectRect().topLeft();
}


