#ifndef PERSONNE_H
#define PERSONNE_H
#include <QString>
#include <QDebug>

class Personne
{
public:
    Personne(QString nom,QString prenom,int age,QString niv);
    void afficherPersonne();
    QString getNom();
    void setNom(QString n);
    QString getPrenoms();
    void setPrenoms(QString p);
    int getAge();
    void setAge(int a);
    QString getNiveau();
private:
    QString nom;
    QString prenoms;
    int age;
    QString niveau;
};

#endif // PERSONNE_H
