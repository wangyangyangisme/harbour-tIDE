#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include <QQuickView>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QDebug>
//#include <QTextEdit>
#include <QString>
#include "documenthandler.h"
#include "iconprovider.h"


int main(int argc, char *argv[])
{

    QGuiApplication *app = SailfishApp::application(argc, argv);
    QQuickView *view = SailfishApp::createView();
    view->setSource(SailfishApp::pathTo("qml/harbour-sailorcreator.qml"));
    qmlRegisterType<DocumentHandler>("eekkelund.sailorcreator.documenthandler", 1, 0, "DocumentHandler");
    QQmlEngine *engine = view->engine();
    engine->addImageProvider(QLatin1String("ownIcons"), new IconProvider);
    view->showFullScreen();

    return app->exec();

}

