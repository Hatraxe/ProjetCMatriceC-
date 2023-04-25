// D�finition de la valeur initiale d�une exception
#pragma once
#define DEFAUT 0
#define DIVISIONZERO 1
#define ERREURTAILLE 2

class CException
{
	// Cette classe repr�sente une ou plusieurs exceptions lev�es
		// par le programme

		//Attributs :

private:
	unsigned int uiEXCValeur; //Cette variable contient la valeur de l�exception

	//Par defaut uiEXCValeur = FAUX
		

	//Primitives :
public:

	CException();
	/* Constructeur par d�faut de la classe
	E : n�ant
	 n�cessite : n�ant
	S : n�ant
	entra�ne : l�exception est initialis� � FAUX */


	~CException() {}
	/* Destructeur de la classe
	E : n�ant
	n�cessite : n�ant
	S : n�ant
	entra�ne : l�exception est d�truite*/


	void EXCModifierValeur(unsigned int valeur);
	/* Cette fonction permet de modifier la valeur de l�exception
	E : nouvelle valeur
	n�cessite : n�ant
	S : n�ant
	entra�ne : la valeur de l�exception est modifi�e*/


	unsigned int EXCLireValeur();
	/* Cette fonction permet de consulter la valeur de l�exception
	E : n�ant
	n�cessite : n�ant
	S : valeur de l�exception
	entra�ne : la valeur de l�exception est retourn�e*/
};