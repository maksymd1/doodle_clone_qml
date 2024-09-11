#include "doodleobject.h"
#include <QDebug>

DoodleObject::DoodleObject(QObject *parent) : QObject(parent),
    m_imagePath(""),
    m_objectRect(QRect()),
    m_speedXA(0),
    m_speedYA(0)
{

}

QRect DoodleObject::objectRect()
{
    return m_objectRect;
}

void DoodleObject::setObjectRect(const QRect &objRect)
{
    m_objectRect = objRect;

    emit objectRectChanged();
}

void DoodleObject::setObjectPos(const QPoint &objPos)
{
    m_objectRect.moveTo(objPos);
    emit objectRectChanged();
}

QString DoodleObject::imagePath()
{
    return m_imagePath;
}

void DoodleObject::setImagePath(const QString &fullImagePath)
{
    if(m_imagePath == fullImagePath)
        return;

    m_imagePath = fullImagePath;
    emit imagePathChanged();
}

void DoodleObject::moveObject()
{
    int xpos = m_objectRect.x();
    int ypos = m_objectRect.y();

//    if( (m_speedXA != 0) || (m_speedYA != 0) )
//    {
        m_objectRect.moveTo((xpos + m_speedXA), (ypos + m_speedYA ));

        emit objectRectChanged();
//    }
}

void DoodleObject::setX(int xpos)
{
    m_objectRect.moveLeft(xpos);

    emit objectRectChanged();
}
void DoodleObject::setY(int ypos)
{
    m_objectRect.moveTop(ypos);

    emit objectRectChanged();
}

