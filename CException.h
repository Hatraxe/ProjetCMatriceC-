#pragma once
#define DEFAUT 0
#define DIVISION_PAR_ZERO 101
#define ERREUR_TAILLE 102
#define HORS_TABLEAU 103
#define ERREUR_TYPE 104
#define ERREUR_FORMAT 105
#define ERREUR_FICHIER 106


class CException
{
		//Attributs :

private:
	unsigned int uiEXCValeur; //Cette variable contient la valeur de l’exception

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

	//Accesseur en ecriture
	void EXCModifierValeur(unsigned int valeur);
	/* Cette fonction permet de modifier la valeur de l’exception
	E : nouvelle valeur
	nécessite : néant
	S : néant
	entraîne : la valeur de l’exception est modifiée*/

	//Acceseur en lecture

	unsigned int EXCLireValeur();
	/* Cette fonction permet de consulter la valeur de l’exception
	E : néant
	nécessite : néant
	S : valeur de l’exception
	entraîne : la valeur de l’exception est retournée*/
};