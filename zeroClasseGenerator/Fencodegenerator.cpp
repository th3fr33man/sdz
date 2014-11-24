#include "fencodegenerator.h"

FenCodeGenerator::FenCodeGenerator(QString nomClass, QString codeGenereH, QString codeGenereCPP, QWidget *parent) :
    QDialog(parent)
{
    setFixedSize(300, 400);
    QVBoxLayout *vBoxFenCode = new QVBoxLayout;

    m_codeGenereHeader = new QTextEdit(codeGenereH, this);
    m_codeGenereCPP = new QTextEdit(codeGenereCPP, this);
    m_BoutonFermer = new QPushButton("Fermer", this);
    m_BoutonSauver = new QPushButton("Sauvegarder", this);
    QTabWidget *tab = new QTabWidget(this);
    tab->addTab(m_codeGenereHeader, nomClass + ".h");
    tab->addTab(m_codeGenereCPP, nomClass + ".cpp");
    vBoxFenCode->addWidget(tab);

    QHBoxLayout *hBox = new QHBoxLayout;

    hBox->addWidget(m_BoutonFermer);
    hBox->addWidget(m_BoutonSauver);
    QGroupBox *gBox = new QGroupBox;
    gBox->setLayout(hBox);
    vBoxFenCode->addWidget(gBox);

    QObject::connect(m_BoutonFermer, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(m_BoutonSauver, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));

    setLayout(vBoxFenCode);

}



void FenCodeGenerator::ouvrirDialogue()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString());
    QFile file(fichier);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    // Utilistion d'un sream pour l'enregistrement du texte dans un fichier
    QTextStream out(&file);
    out << m_codeGenereHeader->toPlainText() << "\n";

    // message de
    QMessageBox::information(this, "Fichier", "Vous avez enregistré le fichier :\n" + fichier);
}
