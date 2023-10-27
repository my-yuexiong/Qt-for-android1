#include "widget.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QScreen>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "android_project3_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    QScreen *iScreen = a.primaryScreen();
    QSize rScreenSize = iScreen->size();

    Widget w(&rScreenSize);
    w.show();
    return a.exec();
}
