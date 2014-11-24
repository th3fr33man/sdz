
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "Mafenetre.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);


    MaFenetre fenetre;
    fenetre.show();

    return app.exec();
}





//================test============
// Création d'un widget qui servira de fenêtre
//QWidget fenetre;
//fenetre.setFixedSize(300, 150);

//// Création du bouton, ayant pour parent la "fenêtre"
//QPushButton bouton("Pimp mon bouton !", &fenetre);
//// Personnalisation du bouton
//bouton.setFont(QFont("Comic Sans MS", 14));
//bouton.setCursor(Qt::PointingHandCursor);
//bouton.setIcon(QIcon("smile.png"));

//// Affichage de la fenêtre
//fenetre.show();
