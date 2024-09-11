#include "doodleengine.h"
#include <QDebug>
#include <QtWidgets/QApplication>
#include <QKeyEvent>

#define GAME_TIMER_MS 30
#define PLATFORMS_COUNT 8
#define JUMP_HEIGHT 300 // iJumpHeight = (iHeight / 2 - 20 );

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 700

DoodleEngine::DoodleEngine(QObject *parent) : QObject(parent),
    m_gameScore(0),
    m_timerRunning(false)
{
    m_GameTimer = new QTimer;
    ScoresRW = new HighScores;

    setHighScoresList( ScoresRW->getScoresData() );

    connect(m_GameTimer, SIGNAL(timeout()), this, SLOT( gameUpdate() ));
}

void DoodleEngine::startNewGame()
{
    setGameScore(0);
    generatePlatfroms();
    startTimer();
}

void DoodleEngine::quitGame()
{
    QApplication::quit();
}

void DoodleEngine::endGame()
{
    emit signalPlayerDead();
    stopTimer();
    list_AllUnits.clear();
    list_Platforms.clear();
    list_Units.clear();

    emit doodleUnitsChanged();
    emit doodleObjectsChanged();
    emit doodlePlatformsChanged();
}

DoodleEngine::~DoodleEngine()
{
    stopTimer();
    delete m_GameTimer;
}

void DoodleEngine::generatePlatfroms()
{
    int tempX = 0;
    int tempY = 0;

    if(!m_Doodle) {
        qDebug() << "ERROR";
        return;
    }

    m_Doodle->setObjectPos( QPoint(SCREEN_WIDTH/2, (SCREEN_HEIGHT/2 - 50) ) );
    m_Doodle->setSpeedXA(0);
    m_Doodle->setSpeedYA(0);

    if(!list_Units.contains(m_Doodle)) {
        list_Units.append(m_Doodle);
    }

    for (int i = 1; i <= PLATFORMS_COUNT; i++) {
        DoodlePlatform *platform = new DoodlePlatform();

        tempX = rand() % (SCREEN_WIDTH - 70);
        tempY = 100 * (i - 1) + rand() % (100 * i - 100 * (i - 1) );

        qDebug() << tempX << tempY;

        platform->setObjectPos(QPoint(tempX, tempY));

        list_AllUnits << platform;
        list_Platforms << platform;
    }

    foreach(DoodleUnit *unit, list_Units) {
         list_AllUnits.append(unit);
    }

    emit doodleUnitsChanged();
    emit doodleObjectsChanged();
    emit doodlePlatformsChanged();
}

bool DoodleEngine::stopTimer()
{
    bool bStopTimerResult = false;

    if(m_GameTimer) {
        if(m_GameTimer->isActive()) {
            m_GameTimer->stop();
            bStopTimerResult = true;
        }
    }
    setTimerRunning(false);
    return bStopTimerResult;
}

bool DoodleEngine::startTimer()
{
    bool bStartTimerResult = false;

    if(m_GameTimer) {
        if(m_GameTimer->isActive()) {
            bStartTimerResult = true;
        } else {
            m_GameTimer->start(GAME_TIMER_MS);
            bStartTimerResult = true;
        }
    }
    setTimerRunning(true);
    return bStartTimerResult;
}

void DoodleEngine::setTimerRunning(bool running)
{
    m_timerRunning = running;

    emit timerRunningChanged();
}

void DoodleEngine::gameUpdate()
{
//    foreach(DoodleObject *object, list_AllUnits) {
//         object->moveObject();
//    }

    m_Doodle->setSpeedYA(m_Doodle->getSpeedYA() + 1);

    /* END GAME CONDITION
       DOODLE FELL DOWN   */
    if (m_Doodle->getObjectPosition().y() > SCREEN_HEIGHT) {
        endGame();
    }

    if ( m_Doodle->getObjectPosition().y() < JUMP_HEIGHT ) {
        m_Doodle->setY(JUMP_HEIGHT); // MOVE DOWN THIS

        foreach(DoodlePlatform *platform, list_Platforms) {

            platform->setY(platform->objectRect().y() - m_Doodle->getSpeedYA());

            if (platform->objectRect().y() > (SCREEN_HEIGHT + 100)) {
                int tempY = rand() % 100 - 100; // Value between -100 and 0
                platform->setY(tempY);
                platform->setX(rand() % (SCREEN_WIDTH - 100) );
            }
        }
    }

    // Check if Doodle over platform

    foreach(DoodlePlatform *platform, list_Platforms) {
        if ( (( m_Doodle->objectRect().x() + m_Doodle->objectRect().width() ) > platform->objectRect().x())
                && (( m_Doodle->objectRect().x()) < (platform->objectRect().x() + platform->objectRect().width())) &&
                (( m_Doodle->objectRect().y() + m_Doodle->objectRect().height() ) > platform->objectRect().y())
                && ((m_Doodle->objectRect().y() + m_Doodle->objectRect().height()) < (platform->objectRect().y() + platform->objectRect().height()))
                && (m_Doodle->getSpeedYA() > 0) )
        {
            m_Doodle->setSpeedYA(-25);

            addScore(SCREEN_HEIGHT - platform->objectRect().y());
        }
    }

    m_Doodle->moveObject();

    // qDebug() << m_Doodle->getSpeedYA() << m_Doodle->objectRect().x() << m_Doodle->objectRect().y();
}


QQmlListProperty <DoodleObject> DoodleEngine::doodleObjects()
{
    return QQmlListProperty<DoodleObject>(this, list_AllUnits);
}

QQmlListProperty <DoodlePlatform> DoodleEngine::doodlePlatforms()
{
    return QQmlListProperty<DoodlePlatform>(this, list_Platforms);
}

void DoodleEngine::setGameScore(int value)
{
    m_gameScore = value;

    emit gameScoreChanged();
}

void DoodleEngine::addScore(int value)
{
    setGameScore(getGameScore() + abs(value));
}

void DoodleEngine::setHighScoresList(QStringList scores_list)
{
    m_scoresModel = scores_list;

    emit highScoresListChanged();
}

