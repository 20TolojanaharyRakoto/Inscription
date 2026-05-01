#include "Inscription.h"
#include "ui_inscription.h"
#include "Etudiant.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

Inscription::Inscription(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inscription)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(2);
    ui->lineAjoutNom->setPlaceholderText("Nom");
    ui->lineAjoutPrenoms->setPlaceholderText("Prénoms");
    ui->lineAjoutNiveau->setPlaceholderText("Niveau");
    ui->lineSupprNom->setPlaceholderText("Nom");
    ui->lineSupprPrenoms->setPlaceholderText("Prénoms");
    ui->lineSupprNiveau->setPlaceholderText("Niveau");

    ui->lineAncienNom->setPlaceholderText("Nom");
    ui->lineAncienPrenom->setPlaceholderText("Prénoms");
    ui->lineNouveauNom->setPlaceholderText("Nouveau Nom");
    ui->lineNouveauPrenoms->setPlaceholderText("Nouveau Prénoms");

    connect(ui->ButtonInscrire, &QPushButton::clicked, [=]() { ui->stackedWidget->setCurrentIndex(0); });
    connect(ui->ButtonAjout, &QPushButton::clicked, this, &Inscription::onButtonClicked);
    connect(ui->ButtonRetour1, &QPushButton::clicked, [=]() { ui->stackedWidget->setCurrentIndex(2); });

    connect(ui->ButtonDesabonner, &QPushButton::clicked, [=]() { ui->stackedWidget->setCurrentIndex(1); });
    connect(ui->ButtonSuppr, &QPushButton::clicked, this, &Inscription::supprimer);
    connect(ui->ButtonRetour2, &QPushButton::clicked, [=]() { ui->stackedWidget->setCurrentIndex(2); });

    connect(ui->ButtonModifier, &QPushButton::clicked, this, &Inscription::preparerModification);
    connect(ui->ButtonSuivant,&QPushButton::clicked,this,&Inscription::passerSuivant);
    connect(ui->ButtonPrecedent,&QPushButton::clicked,[=]() {ui->stackedWidget->setCurrentIndex(3);});
    connect(ui->ButtonAppliquer, &QPushButton::clicked, this, &Inscription::onAppliquerModification);
    connect(ui->ButtonRetour3, &QPushButton::clicked, [=]() {  ui->stackedWidget->setCurrentIndex(2); });
    connect(ui->ButtonRetour3_2, &QPushButton::clicked, [=]() {  ui->stackedWidget->setCurrentIndex(2); });


    connect(ui->ButtonSauvegarder, &QPushButton::clicked, this, &Inscription::sauvegarderEnCSV);
}

Inscription::~Inscription()
{
    delete ui;
}

void Inscription::viderChampsSaisie()
{
    ui->lineAjoutNom->clear();
    ui->lineAjoutPrenoms->clear();
    ui->spinBox->setValue(0);
    ui->lineAjoutNiveau->clear();
}

void Inscription::onButtonClicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    Etudiant pers(ui->lineAjoutNom->text(),ui->lineAjoutPrenoms->text(),ui->spinBox->value(),ui->lineAjoutNiveau->text());
    ajouterEtudiant(pers);
    QMessageBox::information(this,"Succès","Etudiant ajouter avec succès");
    viderChampsSaisie();
    afficherEtudiants();
}

void Inscription::ajouterEtudiant(Etudiant pers)
{
    personnes.append(pers);
}

void Inscription::sauvegarderEnCSV()
{
    QFile fichier("etudiants.csv");
    if (fichier.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream flux(&fichier);
        for (auto p : personnes)
        {
            flux << p.getNom() << ";"
                 << p.getPrenoms() << ";"
                 << p.getAge() << ";"
                 << p.getNiveau() << "\n";
        }
        fichier.close();
        QMessageBox::information(this, "Sauvegarde", "Données exportées en CSV avec succès !");
    }
}

void Inscription::afficherEtudiants()
{
    if (personnes.isEmpty())
    {
        ui->textEdit->setPlainText("Aucun étudiant enregistré pour le moment.");
        return;
    }

    QString contenu;
    for (auto p : personnes)
    {
        contenu += "Nom : " + p.getNom() + "\n";
        contenu += "Prenoms : " + p.getPrenoms() + "\n";
        contenu += "Age : " + QString::number(p.getAge()) + "\n";
        contenu += "Niveau : " + p.getNiveau() + "\n";
        contenu += "------------------------\n";
    }

    ui->textEdit->setPlainText(contenu);
}

QVector<Etudiant>::iterator Inscription::rechercherEtudiant(Etudiant pers)
{
    for(QVector<Etudiant>:: iterator it=personnes .begin();it != personnes.end();++it)
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
    ui->stackedWidget->setCurrentIndex(1);
    Etudiant pers(ui->lineSupprNom->text(),ui->lineSupprPrenoms->text(),ui->spinBox_2->value(),ui->lineSupprNiveau->text());
    auto it = rechercherEtudiant(pers);
    if (it != personnes.end())
    {
        personnes.erase(it);
         QMessageBox::information(this,"Succès","Personne supprimée avec succès!");
    }
    else
    {
        QMessageBox::warning(this,"Error", "Personne non trouvée!");
    }
    afficherEtudiants();
}

void Inscription::onAppliquerModification()
{
    QString nomActuel = ui->lineAncienNom->text();
    QString prenomActuel = ui->lineAncienPrenom->text();
    int ageActuel = ui->spinBoxAncienAge->value();

    Etudiant recherche(nomActuel, prenomActuel, ageActuel, "");

    auto it = rechercherEtudiant(recherche);

    if (it != personnes.end())
    {

        it->setNom(ui->lineNouveauNom->text());
        it->setPrenoms(ui->lineNouveauPrenoms->text());
        it->setAge(ui->spinBoxNouveauAge->value());

        QMessageBox::information(this, "Succès", "L'étudiant a été mis à jour !");

        afficherEtudiants();
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        QMessageBox::warning(this, "Erreur", "Aucun étudiant trouvé avec ce nom et ce prénom.");
    }
}

void Inscription::preparerModification()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Inscription::passerSuivant()
{
    ui->stackedWidget->setCurrentIndex(4);
}
