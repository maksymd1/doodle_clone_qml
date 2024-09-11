#include <QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlContext>
#include <QDateTime>

#include "doodleengine.h"
#include "doodleobject.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    // This is for different randoms
    qsrand(QDateTime::currentDateTime().toTime_t());

    qmlRegisterType<DoodleObject>();
    //qmlRegisterType<DoodleUnit>();
    qmlRegisterType<DoodlePlatform>();
    qmlRegisterType<DoodleUnit>("io.qt.doodle", 1, 0, "Doodle");

    DoodleEngine *Engine = new DoodleEngine;
    QQuickView *qv_View = new QQuickView;

    qv_View->rootContext()->setContextProperty("Engine", Engine);
    qv_View->setResizeMode(QQuickView::SizeRootObjectToView);
    qv_View->setSource( QUrl("qrc:/qml/main.qml") );
    qv_View->show();
    return a.exec();
}
