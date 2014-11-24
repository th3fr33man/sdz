#include "FenPrincipale.h"
#include "Fencodegenerator.h"

FenPrincipale::FenPrincipale(QWidget *parent) :
    QWidget(parent)
{


    setFixedSize(400, 600);
    QVBoxLayout *vboxGlobal = new QVBoxLayout;


    //definition de la classe
    QGroupBox *groupBoxDefinitionDeClass = new QGroupBox(tr("Definition de la classe"));
    QFormLayout *formBoxDefinitionClass = new QFormLayout;
    m_nomClasse = new QLineEdit;
    m_nomClasseMere = new QLineEdit;
    formBoxDefinitionClass->addRow("Nom de la classe", m_nomClasse);
    formBoxDefinitionClass->addRow("Nom de la classe mère", m_nomClasseMere);
    groupBoxDefinitionDeClass->setLayout(formBoxDefinitionClass);


    // Options
    QGroupBox *groupBoxOption = new QGroupBox(tr("Options"));
    QVBoxLayout *vBoxLayoutOption = new QVBoxLayout;
    m_chkProtegeHeader = new QCheckBox("Protèger le header contre les inclusions multiples", this);
    m_chkGenereConstructeur = new QCheckBox("Générer un constructeur par défaut", this);
    m_chkGenereDestructeur = new QCheckBox("Générer le destructeur de la classe", this);
    vBoxLayoutOption->addWidget(m_chkProtegeHeader);
    vBoxLayoutOption->addWidget(m_chkGenereConstructeur);
    vBoxLayoutOption->addWidget(m_chkGenereDestructeur);
    groupBoxOption->setLayout(vBoxLayoutOption);


    // Commentaires
    groupBoxCommentaires = new QGroupBox(tr("Commentaires"));
    groupBoxCommentaires->setCheckable(true);
    QFormLayout *formBoxCommentaires = new QFormLayout;
    m_auteur = new QLineEdit;
    m_date = new QDateEdit(QDate::currentDate());
    m_commentaires = new QTextEdit;
    formBoxCommentaires->addRow("Auteur", m_auteur);
    formBoxCommentaires->addRow("Date de création", m_date);
    formBoxCommentaires->addRow("Rôle de la classe", m_commentaires);
    groupBoxCommentaires->setLayout(formBoxCommentaires);


    // Les boutons
    QGroupBox *groupBoxBoutons = new QGroupBox();
    QHBoxLayout *hLayoutBoutons = new QHBoxLayout;
    m_boutonGenere = new QPushButton("Générer", this);
    m_boutonQuitter = new QPushButton("Quitter", this);
    hLayoutBoutons->addWidget(m_boutonGenere);
    hLayoutBoutons->addWidget(m_boutonQuitter);
    groupBoxBoutons->setLayout(hLayoutBoutons);


    //Connection des signaux avec les slots
    QObject::connect(m_boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(m_boutonGenere, SIGNAL(clicked()), this, SLOT(genererCode()));


    // Ajout des layouts secondire dans le layout global
    vboxGlobal->addWidget(groupBoxDefinitionDeClass);
    vboxGlobal->addWidget(groupBoxOption);
    vboxGlobal->addWidget(groupBoxCommentaires);
    vboxGlobal->addWidget(groupBoxBoutons);

    // Application du lyout global à la fenêtre
    setLayout(vboxGlobal);
}

/**
 * @brief FenPrincipale::genererCode
 * slot pour la génération du code en fonction des options et des valeurs remplis dans la fenêtre principale
 */
void FenPrincipale::genererCode()
{
    if (m_nomClasse->text().isEmpty())
    {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer au moins un nom de classe");
        return; // Arrêt de la méthode
    }

    // Création du texte du fichier .h et le cpp
    m_codeGenereH = "";
    m_codeGenereCPP = "";
    //Insertion des commentaires
    if(groupBoxCommentaires->isChecked())
    {
        m_codeGenereH += "/*";
        m_codeGenereH += "Auteur : " + m_auteur->text() + "<br>";
        m_codeGenereH += "Date de création : " + m_date->text() + "<br>";
        m_codeGenereH += "Rôle : <br>" + m_commentaires->toPlainText() + "<br>";
        m_codeGenereH += "*/<br><br><br>";
    }

    // insertion protection contre les inclusions multiples
    if(m_chkProtegeHeader->isChecked())
    {
        m_codeGenereH += "#ifindef HEADER_" + m_nomClasse->text().toUpper() + "<br>";
        m_codeGenereH += "#define HEADER_" + m_nomClasse->text().toUpper() + "<br>";
    }
    // début de la classe
    m_codeGenereH += "class " + m_nomClasse->text() + (m_nomClasseMere->text().isEmpty() ? " " : " : " + m_nomClasseMere->text()) + "<br>";
    m_codeGenereH += "{<br><br>";
    m_codeGenereH += "public:<br>";
    // le .cpp
    m_codeGenereCPP += "class " + m_nomClasse->text() + (m_nomClasseMere->text().isEmpty() ? " " : " : " + m_nomClasseMere->text()) + "<br>";
    m_codeGenereCPP += "{<br>";
    m_codeGenereCPP += "}<br><br>";
    if(m_chkGenereConstructeur->isChecked())
    {
        m_codeGenereH += m_nomClasse->text() + "();<br><br>";
        // le cpp
        m_codeGenereCPP += m_nomClasse->text() + "();<br>";
        m_codeGenereCPP += "{<br>";
        m_codeGenereCPP += "}<br><br>";
    }
    if(m_chkGenereDestructeur->isChecked())
    {
        m_codeGenereH += "~" + m_nomClasse->text() + "();<br><br>";
        // le cpp
        m_codeGenereCPP += "~" + m_nomClasse->text() + "();<br>";
        m_codeGenereCPP += "{<br>";
        m_codeGenereCPP += "}<br><br>";
    }
    m_codeGenereH += "protected:<br>";
    m_codeGenereH += "private:<br>";
    // fin de la class
    m_codeGenereH += "}<br>";
    m_codeGenereCPP += "}<br>";




    // Création de la fenêtre
    FenCodeGenerator *fenCodeGenere = new FenCodeGenerator(m_nomClasse->text(), m_codeGenereH, m_codeGenereCPP, this);
    fenCodeGenere->show();
}

//void FenPrincipale::ouvrirFenetre()
//{
//    FenCodeGenerator *fenCodeGenere = new FenCodeGenerator(genererCode(), this);
//    fenCodeGenere->show();
//}


