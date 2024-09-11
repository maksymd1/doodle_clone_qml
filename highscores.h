#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include <QString>
#include <QObject>

class HighScores : public QObject
{
public:
    HighScores(QObject *parent = 0) : QObject(parent) { }

    QStringList getScoresData();

    void writeScoresData(const QString &score);

private:
    QString filename = "scores.ini";

};


#endif // HIGHSCORES_H
