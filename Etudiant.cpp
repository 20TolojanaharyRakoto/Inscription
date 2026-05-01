#include "Etudiant.h"

Etudiant::Etudiant(QString nom,QString prenom,int age,QString niv)
{
    this->nom = nom;
    this->prenoms = prenom;
    this->age = age;
    this->niveau = niv;
}
void Etudiant::setNom(QString n)
{
    nom = n;
}

void Etudiant::setPrenoms(QString p)
{
    prenoms = p;
}
void Etudiant::setAge(int a)
{
    age = a;
}
QString Etudiant::getNom()
{
    return nom;
}

QString Etudiant::getPrenoms()
{
    return prenoms;
}

int Etudiant::getAge()
{
    return age;
}
QString Etudiant::getNiveau()
{
    return niveau;
}
void Etudiant::afficherPersonne()
{
    qDebug() << "Nom : " << nom ;
    qDebug() << "Prenoms : " << prenoms;
    qDebug() << "Age : " << age ;
    qDebug() << "Niveau : " << niveau;
}
