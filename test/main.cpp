
#include <QApplication>
#include "Mafenetre.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

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
