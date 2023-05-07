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
	unsigned int uiEXCValeur; //Cette variable contient la valeur de l�exception

public:

	CException();
	/* Constructeur par d�faut de la classe
	E : n�ant
	 n�cessite : n�ant
	S : n�ant
	entra�ne : l�exception est initialis� � DEFAUT */


	~CException() {}
	/* Destructeur de la classe
	E : n�ant
	n�cessite : n�ant
	S : n�ant
	entra�ne : l�exception est d�truite*/

	//Accesseur en ecriture
	void EXCModifierValeur(unsigned int valeur);
	/* Cette fonction permet de modifier la valeur de l�exception
	E : nouvelle valeur
	n�cessite : n�ant
	S : n�ant
	entra�ne : la valeur de l�exception est modifi�e*/

	//Acceseur en lecture

	unsigned int EXCLireValeur();
	/* Cette fonction permet de consulter la valeur de l�exception
	E : n�ant
	n�cessite : n�ant
	S : valeur de l�exception
	entra�ne : la valeur de l�exception est retourn�e*/
};