#include "Mafenetre.h"



MaFenetre::MaFenetre(QWidget *parent) : QWidget(parent)
{

    setFixedSize(300, 300);
    pseudo = "";

//    m_lcd = new QLCDNumber(this);
//    m_lcd->setSegmentStyle(QLCDNumber::Flat);
//    m_lcd->move(100, 20);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 60, 150, 20);
    m_slider->setRange(200, 600);
//    m_slider->move(50,50);

    m_boutonReset = new QPushButton("Reset !", this);
    m_boutonReset->setCursor(Qt::PointingHandCursor);
//    m_boutonReset->move(100,100);

    m_boutonDialogue = new QPushButton("Dialogue !", this);
    m_boutonDialogue->setCursor(Qt::PointingHandCursor);
//    m_boutonDialogue->move(200,100);

    m_boutonQuitter = new QPushButton("quitter !", this);
    m_boutonQuitter->setCursor(Qt::PointingHandCursor);
//    m_boutonQuitter->move(400,100);

    m_boutonPseudo = new QPushButton("pseudo", this);
    m_boutonPseudo->setCursor(Qt::PointingHandCursor);
//    m_boutonPseudo->move(300,100);

    m_bar = new QProgressBar (this);
    m_bar->setGeometry(10,60,150,20);
//    m_bar->move(50,10);





    //==============connection des signaux/slots=====================================
//    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int))) ;
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_bar, SLOT(setValue(int))) ;
    QObject::connect(m_boutonReset, SIGNAL(clicked()), m_bar, SLOT(reset ())) ;
    QObject::connect(m_boutonReset, SIGNAL(clicked()), this, SLOT(resetSlider())) ;
//    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int)));
    QObject::connect(this, SIGNAL(agrandissementMax()), this, SLOT(ouvrirAlerte()));
    QObject::connect(m_boutonDialogue, SIGNAL(clicked()), this, SLOT(ouvrirDialogue())) ;
    QObject::connect(m_boutonQuitter, SIGNAL(clicked()), this, SLOT(confirmation())) ;
    QObject::connect(this, SIGNAL(fermeture()), qApp, SLOT(quit())) ;
    QObject::connect(m_boutonPseudo, SIGNAL(clicked()), this, SLOT(demanderPseudo())) ;

//    setFixedSize(300, 150);
//    // Construction du bouton
//    m_bouton = new QPushButton("Quitter !", this);
//    m_bouton->setFont(QFont("Comic Sans MS", 14));
//    m_bouton->setCursor(Qt::PointingHandCursor);
//    m_bouton->setIcon(QIcon("smile.png"));
//    m_bouton->move(60, 50);
//    QObject::connect(m_bouton, SIGNAL(clicked()), qApp, SLOT(quit()));


//////=== Les layouts ===
    // layouts vert et horiz
/*
    QVBoxLayout *layoutV = new QVBoxLayout;
    layoutV->addWidget(m_bar);
    layoutV->addWidget(m_slider);
    QHBoxLayout *layoutH = new QHBoxLayout;
    layoutH->addWidget(m_boutonReset);
    layoutH->addWidget(m_boutonDialogue);
    layoutH->addWidget(m_boutonQuitter);
    layoutH->addWidget(m_boutonPseudo);
    layoutV->addLayout(layoutH);
    setLayout(layoutV);
*/

    //Gridlayout

    QGridLayout *layoutG = new QGridLayout;
    layoutG->addWidget(m_bar, 0, 0, 1, 4);
    layoutG->addWidget(m_slider, 1, 0, 1, 4);
    layoutG->addWidget(m_boutonReset, 2, 0);
    layoutG->addWidget(m_boutonDialogue, 2, 1);
    layoutG->addWidget(m_boutonQuitter, 2, 2);
    layoutG->addWidget(m_boutonPseudo, 2, 3);


    //formlayout

    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;
    QFormLayout *layoutF = new QFormLayout;
    layoutF->addRow("Votre &nom", nom);         // ajout du & pour associer une lettre raccourcis(celle qui suit le &) pour les champs avec la touche alt
    layoutF->addRow("Votre &prénom", prenom);
    layoutF->addRow("Votre â&ge", age);


    layoutG->addLayout(layoutF, 3 , 0, 1, 4);

    setLayout(layoutG);

}

void MaFenetre::resetSlider()
{
    m_slider->setValue(0);
    pseudo = "";
}


void MaFenetre::changerLargeur(int largeur)
{
    setFixedSize(largeur, 150);
    if (largeur == 600)
    {
        emit agrandissementMax();
    }
}

void MaFenetre::ouvrirDialogue()
{
    QMessageBox::information(this, "Information " + pseudo, "Bonjour et vive c++!");
}

void MaFenetre::ouvrirAlerte()
{
    QMessageBox::warning(this, "Attention " + pseudo, "Attention dépassement de la taille maximum!");
}

void MaFenetre::confirmation()
{
    int reponse = QMessageBox::question(this,"Confirmation " + pseudo,"Etes-vous sur de vouloir quitter?", QMessageBox::Yes, QMessageBox::No);
    if(reponse == QMessageBox::Yes)
    {
        emit fermeture();
    }

}

void MaFenetre::demanderPseudo()
{
    bool bok = false;
    QString pseudoTemp = "";
    if(pseudo.isEmpty())
    {
        pseudoTemp = QInputDialog::getText(this, "Pseudo", "Choisissez un pseudo! ", QLineEdit::Normal, QString(), &bok);
    }
    else
    {
        pseudoTemp = QInputDialog::getText(this, "Pseudo " + pseudo, pseudo + " Quel nouveau pseudo voulez-vous?", QLineEdit::Normal, QString(), &bok);
    }


    if (bok && !pseudoTemp.isEmpty())
    {
        pseudo = pseudoTemp;
        QMessageBox::information(this, "Pseudo " + pseudo, "Bonjour " + pseudo + ", ça va ?");
    }
    else if(!bok && !pseudo.isEmpty())
    {
        QMessageBox::information(this, "Pseudo " + pseudo, "Vous n'avez pas changé de pseudo! ");
    }
    else
    {
        QMessageBox::critical(this, "Pseudo", "Vous n'avez pas voulu donner votre nom… snif.");
    }

}
