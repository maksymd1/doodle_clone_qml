#include "highscores.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>
#include <QDir>

QStringList HighScores::getScoresData()
{
    QFile file(filename);

    QStringList strlst;
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream reader(&file);
        while(!reader.atEnd()) {
            strlst << reader.readLine();
        }
    } else {
        QFileInfo fi(file);
        qDebug() << file.exists();
        qDebug() << "ERROR";

        qDebug() << "Working directory : " << fi.absoluteFilePath();
    }
    file.close();
    return strlst;
}


void HighScores::writeScoresData(const QString &score)
{
    QFile file(filename);
    if (file.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream stream(&file);
        stream << score << endl;
    }
    file.close();
}
