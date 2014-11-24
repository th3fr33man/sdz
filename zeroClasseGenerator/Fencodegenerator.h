#ifndef FENCODEGENERATOR_H
#define FENCODEGENERATOR_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QGroupBox>
#include <QTextStream>

class FenCodeGenerator : public QDialog
{
    Q_OBJECT
public:
    //explicit FenCodeGenerator(QWidget *parent = 0);
    FenCodeGenerator(QString nomClass, QString codeGenereH, QString codeGenereCPP, QWidget *parent = 0);

private:
    QTextEdit *m_codeGenereHeader;
    QTextEdit *m_codeGenereCPP;
    QPushButton *m_BoutonFermer;
    QPushButton *m_BoutonSauver;

signals:

public slots:
    void ouvrirDialogue();

};

#endif // FENCODEGENERATOR_H
