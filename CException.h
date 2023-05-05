// Définition de la valeur initiale d’une exception
#pragma once
#define DEFAUT 0
#define Division_Par_Zero 101
#define Erreur_Taille 102
#define Hors_Tableau 103
#define Erreur_Type 104
#define Erreur_Type 104


class CException
{
	// Cette classe représente une ou plusieurs exceptions levées
		// par le programme

		//Attributs :

private:
	unsigned int uiEXCValeur; //Cette variable contient la valeur de l’exception

	//Par defaut uiEXCValeur = FAUX
		

	//Primitives :
public:

	CException();
	/* Constructeur par défaut de la classe
	E : néant
	 nécessite : néant
	S : néant
	entraîne : l’exception est initialisé à DEFAUT */


	~CException() {}
	/* Destructeur de la classe
	E : néant
	nécessite : néant
	S : néant
	entraîne : l’exception est détruite*/


	void EXCModifierValeur(unsigned int valeur);
	/* Cette fonction permet de modifier la valeur de l’exception
	E : nouvelle valeur
	nécessite : néant
	S : néant
	entraîne : la valeur de l’exception est modifiée*/


	unsigned int EXCLireValeur();
	/* Cette fonction permet de consulter la valeur de l’exception
	E : néant
	nécessite : néant
	S : valeur de l’exception
	entraîne : la valeur de l’exception est retournée*/
};