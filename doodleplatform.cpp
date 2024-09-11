#include "doodleplatform.h"


DoodlePlatform::DoodlePlatform(PlatformType platType)
{
    setupPlatform(platType);
}

void DoodlePlatform::setupPlatform(PlatformType type)
{
    switch (type) {
        case PT_Normal: setupPlatformNormal(); break;
        case PT_SingleHit: setupPlatformSingleHit(); break;
        case PT_Small: setupPlatformSmall(); break;

        default: break;
    }
}

void DoodlePlatform::setupPlatformNormal()
{
    setObjectRect(QRect(0, 0, 70, 20));
    setImagePath(QString("qrc:/content/data/platform_normal.png"));
}

void DoodlePlatform::setupPlatformSingleHit()
{
    setObjectRect(QRect(0, 0, 70, 20));
    setImagePath(QString("qrc:/content/data/platform_normal.png"));
}

void DoodlePlatform::setupPlatformSmall()
{
    setObjectRect(QRect(0, 0, 70, 20));
    setImagePath(QString("qrc:/content/data/platform_normal.png"));
}
