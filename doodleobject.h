#ifndef DOODLEOBJECT_H
#define DOODLEOBJECT_H

#include <QObject>
#include <QPoint>
#include <QRect>
#include <QString>


class DoodleObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString imagePath READ imagePath WRITE setImagePath NOTIFY imagePathChanged)
    QString imagePath();

    Q_PROPERTY(QRect objectRect READ objectRect WRITE setObjectRect NOTIFY objectRectChanged)

    Q_PROPERTY(int getSpeedXA READ getSpeedXA WRITE setSpeedXA) // X axis

    Q_PROPERTY(int getSpeedYA READ getSpeedYA WRITE setSpeedYA) // Y axis

public:
    explicit DoodleObject(QObject *parent = nullptr);
    virtual ~DoodleObject() { }

signals:
    void imagePathChanged();
    void objectRectChanged();

public slots:
    virtual bool checkAdjoin() = 0;

    void moveObject();
    QRect objectRect();

    void setSpeedXA(int speedXA) { m_speedXA = speedXA; }
    void setSpeedYA(int speedYA) { m_speedYA = speedYA; }

    int getSpeedXA() { return m_speedXA; }
    int getSpeedYA() { return m_speedYA; }

    void setImagePath(const QString &fullImagePath);

    void setObjectRect(const QRect &objRect);
    void setObjectPos(const QPoint &objPos);

    void setX(int xpos);
    void setY(int ypos);

private:
    QString m_imagePath;
    QRect m_objectRect;

    int m_speedXA;
    int m_speedYA;

};

#endif // DOODLEOBJECT_H
