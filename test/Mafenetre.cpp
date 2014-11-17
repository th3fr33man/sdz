#include "Mafenetre.h"

MaFenetre::MaFenetre(QWidget *parent) : QWidget(parent)
{

    setFixedSize(300, 150);

//    m_lcd = new QLCDNumber(this);
//    m_lcd->setSegmentStyle(QLCDNumber::Flat);
//    m_lcd->move(100, 20);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 60, 150, 20);
    m_slider->setRange(200, 600);
    m_slider->move(50,50);

    m_boutonReset = new QPushButton("Reset !", this);
    m_boutonReset->setCursor(Qt::PointingHandCursor);
    m_boutonReset->move(100,100);

    m_bar = new QProgressBar (this);
    m_bar->setGeometry(10,60,150,20);
    m_bar->move(50,10);

    //connection des signaux/slots
//    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int))) ;
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_bar, SLOT(setValue(int))) ;
    QObject::connect(m_boutonReset, SIGNAL(clicked()), m_bar, SLOT(reset ())) ;
    QObject::connect(m_boutonReset, SIGNAL(clicked()), this, SLOT(resetSlider())) ;
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int)));
    QObject::connect(this, SIGNAL(agrandissementMax()), qApp, SLOT(quit()));

//    setFixedSize(300, 150);

//    // Construction du bouton
//    m_bouton = new QPushButton("Quitter !", this);

//    m_bouton->setFont(QFont("Comic Sans MS", 14));
//    m_bouton->setCursor(Qt::PointingHandCursor);
//    m_bouton->setIcon(QIcon("smile.png"));
//    m_bouton->move(60, 50);

//    QObject::connect(m_bouton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MaFenetre::resetSlider()
{
    m_slider->setValue(0);
}


void MaFenetre::changerLargeur(int largeur)
{
    setFixedSize(largeur, 150);
    if (largeur == 600)
    {
        emit agrandissementMax();
    }
}
