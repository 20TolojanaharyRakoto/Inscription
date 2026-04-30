#ifndef INSCRIPTION_H
#define INSCRIPTION_H
#include "Personne.h"
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
    void ajouterPersonnes(Personne pers);
    void onButtonClicked();
    void afficherFichierTXT();
    void sauvegarderDansFichier();
    QVector<Personne>::iterator rechercherPersonne(Personne pers);
    void supprimer();

private:
    Ui::Inscription *ui;
    QVector<Personne> personnes;
};
#endif // INSCRIPTION_H
