#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QGroupBox>
#include <QBoxLayout>
#include <QFormLayout>
#include <QMessageBox>


class FenPrincipale : public QWidget
{
    Q_OBJECT
public:
    explicit FenPrincipale(QWidget *parent = 0);




private:
    // Definition de la classe
    QString m_codeGenereH;
    QString m_codeGenereCPP;
    QPushButton *m_boutonGenere;
    QPushButton *m_boutonQuitter;
    QLineEdit *m_nomClasse;
    QLineEdit *m_nomClasseMere;

    // Options
    QCheckBox *m_chkProtegeHeader;
    QCheckBox *m_chkGenereConstructeur;
    QCheckBox *m_chkGenereDestructeur;

    // Commentaires
    QGroupBox *groupBoxCommentaires;
    QCheckBox *m_ajoutCommentaires;
    QLineEdit *m_auteur;
    QDateEdit *m_date;
    QTextEdit *m_commentaires;




signals:

public slots:
    void genererCode();

};

#endif // FENPRINCIPALE_H
