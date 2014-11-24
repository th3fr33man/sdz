
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <FenPrincipale.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Pour la traduction des menus contextuels
    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);

    FenPrincipale fenPrincipale;
    fenPrincipale.show();
    return app.exec();
}
