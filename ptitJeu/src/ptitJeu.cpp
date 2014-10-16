//============================================================================
// Name        : ptitJeu.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Personnage.h"
#include <unistd.h>

using namespace std;

void interfaceJoueur(Personnage &joueur1, Personnage &joueur2)
{
	int choix(0);
	cout << joueur1.getNom() << " selectionnez votre action " << endl;
	cout << "1 : attaquer avec l'arme " << endl;
	cout << "2 : attaquer avec le pouvoir " << endl;
	cout << "3 : utiliser une potion " << endl;
	cout << "4 : changer d'arme " << endl;
	cin >> choix;
	switch(choix)
	{
	case 1:
		joueur1.attaquerAvecArme(joueur2);
		break;

	case 2:
		joueur1.attaquerAvecPouvoir(joueur2);
		break;

	case 3:
		joueur1.boirePotionDeVie(10);
		break;

	case 4:
		joueur1.changerArme("Fléau de la mort", 50, 10);
		break;
	}

}


int main()
{

	//Création des personnages
	Personnage goliath("Goliath", "Épée aiguisée", 20, 0);
	Personnage david("David", "Épée aiguisée", 20, 0);

	// pour le switch des perso
	bool bJoueur1(true);

	//Au combat !
	do
	{

//		goliath.attaquer(david);
//		david.boirePotionDeVie(20);
//		goliath.attaquer(david);
//		david.attaquer(goliath);
//		goliath.changerArme("Hache tranchante", 30, 0);
//		goliath.attaquer(david);

		if(bJoueur1)
		{
			interfaceJoueur(david, goliath);
		}
		else
		{
			interfaceJoueur(goliath, david);
		}

		// affichage de la vie
		cout << david.getNom() << endl;
		david.afficherEtat();
		cout << endl << goliath.getNom() << endl;
		goliath.afficherEtat();

		cout << "pause appuyez sur entrée pour continuer " << endl;
		cin.get();

		bJoueur1 = !bJoueur1;

	} while (david.estVivant() && goliath.estVivant());

	cout << "fin" << endl;

	return 0;
}





