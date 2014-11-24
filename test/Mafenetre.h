#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include <QMessageBox>
#include <QInputDialog>
#include <QLayout> // on inclus ici tous les layouts juste pour pouvoir les tester sans devoir changer l'include à chaque fois
#include <QFormLayout>

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
    QPushButton *m_boutonDialogue;
    QPushButton *m_boutonQuitter;
    QPushButton *m_boutonPseudo;
    QString pseudo;

signals:
    void agrandissementMax();
    void fermeture();

public slots:
    void resetSlider();
    void changerLargeur(int largeur);
    void ouvrirDialogue();
    void ouvrirAlerte();
    void confirmation();
    void demanderPseudo();

};

#endif // MAFENETRE_H
