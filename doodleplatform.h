#ifndef DOODLEPLATFORM_H
#define DOODLEPLATFORM_H



#include "doodleobject.h"

class DoodlePlatform : public DoodleObject
{
    Q_OBJECT

public:    
    enum PlatformType {
        PT_Normal,
        PT_SingleHit,
        PT_Small,
    };

    DoodlePlatform(PlatformType = PT_Normal);

public slots:
    bool checkAdjoin() { return false; }

private:
    QPoint qpObjectPosition;

    void setupPlatform(PlatformType type);
    void setupPlatformNormal();
    void setupPlatformSingleHit();
    void setupPlatformSmall();
};

#endif // DOODLEPLATFORM_H
