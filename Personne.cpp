#include "Personne.h"

Personne::Personne(QString nom,QString prenom,int age,QString niv)
{
    this->nom = nom;
    this->prenoms = prenom;
    this->age = age;
    this->niveau = niv;
}
void Personne::setNom(QString n)
{
    nom = n;
}

void Personne::setPrenoms(QString p)
{
    prenoms = p;
}
void Personne::setAge(int a)
{
    age = a;
}
QString Personne::getNom()
{
    return nom;
}

QString Personne::getPrenoms()
{
    return prenoms;
}

int Personne::getAge()
{
    return age;
}
QString Personne::getNiveau()
{
    return niveau;
}
void Personne::afficherPersonne()
{
    qDebug() << "Nom : " << nom ;
    qDebug() << "Prenoms : " << prenoms;
    qDebug() << "Age : " << age ;
    qDebug() << "Niveau : " << niveau;
}
