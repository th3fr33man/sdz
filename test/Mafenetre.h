#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>


class MaFenetre : public QWidget
{
    Q_OBJECT
public:
    explicit MaFenetre(QWidget *parent = 0);

private:
    QPushButton *m_boutonReset;
    QLCDNumber *m_lcd;
    QSlider *m_slider;
    QProgressBar *m_bar;


signals:
    void agrandissementMax();

public slots:
    void resetSlider();
    void changerLargeur(int largeur);

};

#endif // MAFENETRE_H
