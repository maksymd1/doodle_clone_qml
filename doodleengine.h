#ifndef DOODLEENGINE_H
#define DOODLEENGINE_H

#include <QTimer>
#include <QObject>
#include <QVector>
#include <QQmlListProperty>

#include "doodleplatform.h"
#include "doodleunit.h"
#include "highscores.h"

class DoodleEngine : public QObject
{
    Q_OBJECT

public:
    DoodleEngine(QObject *parent = nullptr);
    ~DoodleEngine();

    Q_PROPERTY(QQmlListProperty <DoodleObject> doodleObjects READ doodleObjects NOTIFY doodleObjectsChanged)
    QQmlListProperty <DoodleObject> doodleObjects();

    Q_PROPERTY(QQmlListProperty <DoodlePlatform> doodlePlatforms READ doodlePlatforms NOTIFY doodlePlatformsChanged)
    QQmlListProperty <DoodlePlatform> doodlePlatforms();

    Q_PROPERTY(DoodleUnit* doodleUnit READ doodleUnit)

    Q_PROPERTY(int gameScore READ gameScore WRITE setGameScore NOTIFY gameScoreChanged)
    int getGameScore() { return m_gameScore; }

    Q_PROPERTY(bool timerRunning READ timerRunning WRITE setTimerRunning NOTIFY timerRunningChanged)
    bool timerRunning() { return m_timerRunning; }

    Q_PROPERTY(QStringList  highScoresList READ highScoresList WRITE setHighScoresList NOTIFY highScoresListChanged)
    QStringList highScoresList() { return m_scoresModel; }

private:
    QTimer *m_GameTimer;
    DoodleUnit *m_Doodle;
    HighScores *ScoresRW;
    QStringList m_scoresModel;

    int m_gameScore;
    bool m_timerRunning;

    QList<DoodlePlatform* > list_Platforms;
    QList<DoodleObject* > list_AllUnits;
    QList<DoodleUnit* > list_Units;

signals:
    // PROPERTY SIGNALS
    void doodleObjectsChanged();
    void doodlePlatformsChanged();
    void doodleUnitsChanged();
    void gameScoreChanged();
    void timerRunningChanged();
    void highScoresListChanged();

    // COMMON SIGNALS
    void signalPlayerDead();

private slots:
    void gameUpdate();
    void generatePlatfroms();

public slots:
    // PROPERTY SLOTS
    void setGameScore(int value);
    void setTimerRunning(bool running);
    void setHighScoresList(QStringList scores_list);

    void addScore(int value);
    int gameScore() { return m_gameScore; }

    DoodleUnit *doodleUnit() const { return m_Doodle; }

    void addDoodleInstance(DoodleUnit *player) { m_Doodle = player; }

    // COMMON SLOTS
    bool startTimer();
    bool stopTimer();

    void startNewGame();
    void quitGame();
    void endGame();
};

#endif // DOODLEENGINE_H
