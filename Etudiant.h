#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QDebug>

class Etudiant
{
public:
    Etudiant(QString nom,QString prenom,int age,QString niv);
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

#endif // ETUDIANT_H
