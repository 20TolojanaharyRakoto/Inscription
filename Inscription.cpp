#include "Inscription.h"
#include "ui_inscription.h"
#include "Personne.h"
#include <QFile>
#include <QTextStream>

Inscription::Inscription(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inscription)
{
    ui->setupUi(this);
    ui->lineAjoutNom->setPlaceholderText("Nom");
    ui->lineAjoutPrenoms->setPlaceholderText("Prénoms");
    ui->lineAjoutNiveau->setPlaceholderText("Niveau");
    connect(ui->ButtonAjout,&QPushButton::clicked,this,&Inscription::onButtonClicked);
    connect(ui->ButtonSuppr,&QPushButton::clicked,this,&Inscription::supprimer);
}

Inscription::~Inscription()
{
    delete ui;
}
void Inscription::onButtonClicked()
{
    Personne pers(ui->lineAjoutNom->text(),ui->lineAjoutPrenoms->text(),ui->doubleSpinBox->value(),ui->lineAjoutNiveau->text());
    ajouterPersonnes(pers);
    sauvegarderDansFichier();
    afficherFichierTXT();
}
void Inscription::ajouterPersonnes(Personne pers)
{
    personnes.append(pers);
}
void Inscription::sauvegarderDansFichier()
{
    QFile fichier("etudiants.txt");
    if (fichier.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QTextStream flux(&fichier);
        Personne p = personnes.last();
        flux << "Nom : " << p.getNom() << "\n";
        flux << "Prenoms : " << p.getPrenoms() << "\n";
        flux << "Age : " << p.getAge() << "\n";
        flux << "Niveau : " << p.getNiveau() << "\n";
        flux << "------------------------\n";
        fichier.close();
    }
}
void Inscription::afficherFichierTXT()
{
    if (personnes.isEmpty()) {
        ui->textEdit->setPlainText("Aucun étudiant enregistré pour le moment.");
        return;
    }

    QString contenu;
    for (auto p : personnes) {
        contenu += "Nom : " + p.getNom() + "\n";
        contenu += "Prenoms : " + p.getPrenoms() + "\n";
        contenu += "Age : " + QString::number(p.getAge()) + "\n";
        contenu += "Niveau : " + p.getNiveau() + "\n";
        contenu += "------------------------\n";
    }

    ui->textEdit->setPlainText(contenu);
}
QVector<Personne>::iterator Inscription::rechercherPersonne(Personne pers)
{
    for(QVector<Personne>:: iterator it=personnes .begin();it != personnes.end();++it)
    {
        if(it->getNom() == pers.getNom() && it->getPrenoms() == pers.getPrenoms() && it->getAge() == pers.getAge())
        {
            return it;
        }
    }
    return personnes.end();
}
void Inscription::supprimer()
{
    Personne pers(ui->lineSupprNoms->text(),ui->lineSupprPrenoms->text(),ui->doubleSpinBox_2->value(),ui->lineSupprNiveau->text());
    auto it = rechercherPersonne(pers);
    if (it != personnes.end())
    {
        personnes.erase(it);
        qDebug() << "Personne supprimée avec succès!";
    }
    else
    {
        qDebug() << "Personne non trouvée!";
    }
    afficherFichierTXT();
}
