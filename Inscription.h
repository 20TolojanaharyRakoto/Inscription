#ifndef INSCRIPTION_H
#define INSCRIPTION_H
#include "Etudiant.h"
#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class Inscription;
}
QT_END_NAMESPACE

class Inscription : public QMainWindow
{
    Q_OBJECT

public:
    Inscription(QWidget *parent = nullptr);
    ~Inscription();
private slots:
    void ajouterEtudiant(Etudiant pers);
    void onButtonClicked();
    void afficherEtudiants();
    QVector<Etudiant>::iterator rechercherEtudiant(Etudiant pers);
    void supprimer();
    void onAppliquerModification();
    void preparerModification();
    void passerSuivant();
    void sauvegarderEnCSV();
    void viderChampsSaisie();

private:
    Ui::Inscription *ui;
    QVector<Etudiant> personnes;
};
#endif
