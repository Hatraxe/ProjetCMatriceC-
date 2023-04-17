#pragma once
#include "CException.h"

#define Ajout_impossible 101
#define Suppression_impossible 102
#define Position_horsliste 103
template <class LType> class CListe
{
	// Cette classe repr�sente une ou plusieurs listes d��l�ments

		// Attributs :
private:
	unsigned int uiLISTaille; //Cet attribut contient le nombre d��l�ments de la liste
	LType* pLTLISListe; //sigle LT signifie l'appartenance au type LType

	// Primitives :
public:

	CListe();
	/* Constructeur par d�faut de la classe
	E : n�ant
	n�cessite : n�ant
	S : n�ant
	entra�ne : la liste est initialis�e � vide */


	CListe(const CListe& LISParam);
	/* Constructeur de recopie de la classe
	E : l�objet que l�on recopie dans l�objet en cours
	n�cessite : n�ant
	S : n�ant
	entra�ne : L�objet en cours contient une copie de l�objet pass� en param�tre */

	CListe(unsigned int taille);

	~CListe();
	/* Destructeur de la classe
	E : n�ant
	n�cessite : n�ant
	S : n�ant
	entra�ne : l�exception est d�truite*/

	CListe<LType>& operator=(const CListe<LType>& LISParam);
	/* Surcharge de l�op�rateur d�affectation
	E : l�objet que l�on affecte dans l�objet en cours
	n�cessite : n�ant
	S : L�objet en cours qui a �t� recopi�
	entra�ne : (L�objet en cours contient une copie de l�objet pass� en param�tre) ou
	(Exception Ajout impossible : pas assez de m�moire libre) */


	void LISAjouterElement(LType element, unsigned int position);
	/* Cette fonction permet d�ajouter un �l�ment dans la liste � la position sp�cifi�e
	E : elem, la valeur � ajouter
	pos, la position d�insertion
	n�cessite : n�ant
	S : n�ant
	entra�ne : (l��l�ment est ajout� � la position requise) ou
	(Exception Ajout impossible : pas assez de m�moire libre) ou
	(Exception Position hors liste : pos>taille) */


	unsigned int LISLireTaille();
	/* Cette fonction permet de conna�tre la taille de la liste
	E : rien
	n�cessite : n�ant
	S : la taille de la liste
	entra�ne : (la taille de la liste est retourn�e) */

	LType LISLireElement(unsigned int position);
	/* Cette fonction permet de lire la valeur d�un �l�ment dans la liste
E : la position de l��l�ment � lire
n�cessite : n�ant
S : la valeur de l��l�ment
entra�ne : (la valeur de l��l�ment est retourn�e) ou
(Exception Position hors liste : pos>=taille) */


	void LISModifierElement(LType element, unsigned int position);
	/* Cette fonction permet de modifier la valeur d�un �l�ment dans la liste
	E : elem, la nouvelle valeur
   pos, la position de l��l�ment � modifier
   n�cessite : n�ant
   S : n�ant
   entra�ne : (L��l�ment est modifi�) ou
   (Exception Position hors liste : pos>=taille) */


	LType& operator[](unsigned int position);
	/* Cette fonction permet d�acc�der � la valeur d�un �l�ment dans la liste
	E : la position de l��l�ment � lire
	n�cessite : n�ant
	S : l��l�ment
	entra�ne : (l��l�ment est accessible) ou
	(Exception Position hors liste : pos>=taille) */


	void LISSupprimerElement(unsigned int position);
	/* Cette fonction permet de supprimer un �l�ment dans la liste � la position sp�cifi�e
	E : pos, la position de suppression
	n�cessite : n�ant
	S : n�ant
	entra�ne : (l��l�ment est supprim� � la position requise) ou
	(Exception Suppression impossible : taille=0) ou
	(Exception Position hors liste : pos>=taille) */
};

//Defintion des methodes

template <class LType> CListe<LType>::CListe()
{
	pLTLISListe = nullptr;
	uiLISTaille = 0;

}

template <class LType> CListe<LType>::~CListe()
{
	delete(pLTLISListe); //Desallocation de la liste

}

template <class LType> CListe<LType>::CListe(const CListe& LISParam)
{
	int iBoucle;

	uiLISTaille = LISParam.uiLISTaille;
	pLTLISListe = new LType[uiLISTaille];
	//pLTLISListe pointe sur une zone m�moire allou�e mais �vide�
	for (iBoucle = 0; iBoucle < uiLISTaille; iBoucle++)
		pLTLISListe[iBoucle] = LISParam.pLTLISListe[iBoucle];
	// la liste objet est recopi�e dans l�objet en cours
}

template <class LType> CListe<LType>::CListe(unsigned int taille)
{
	uiLISTaille = taille;
	pLTLISListe = new LType[uiLISTaille];
}
template <class LType> CListe<LType>& CListe<LType>::operator=(const CListe<LType>& LISParam)
{
	int iBoucle;

	if (uiLISTaille != 0)
	{ // Il faut vider la liste en cours
		uiLISTaille = 0;
		free(pLTLISListe);
	}

	uiLISTaille = LISParam.uiLISTaille;
	pLTLISListe = new LType[uiLISTaille];
	

	for (iBoucle = 0; iBoucle < uiLISTaille; iBoucle++)
		pLTLISListe[iBoucle] = LISParam.pLTLISListe[iBoucle];
	// la liste objet est recopi�e dans l�objet en cours
	return *this;
}


template <class LType> void CListe<LType>::LISAjouterElement(LType element, unsigned int position)
{
	LType* pLTtempo;
	
	int iBoucle;

	if (position > uiLISTaille)
	{ // L�insertionalieu hors tableau : lev�e d�une exception
		CException horstableau;
		horstableau.EXCModifierValeur(Position_horsliste);
		throw(horstableau);
	}

	pLTtempo = new LType[uiLISTaille+1];
	pLTtempo = pLTLISListe;
	uiLISTaille++;
	
	for (iBoucle = uiLISTaille; iBoucle > position; iBoucle--)
		pLTLISListe[iBoucle] = pLTLISListe[iBoucle - 1];
	pLTLISListe[position] = element;
	// L��l�ment est ins�r� dans la liste � la position demand�e
}

template <class LType> unsigned int CListe<LType>::LISLireTaille()
{
	return (uiLISTaille);
}


template <class LType> LType CListe<LType>::LISLireElement(unsigned int position)
{
	if (position >= uiLISTaille)
	{ // L�insertion a lieu hors tableau : lev�e d�une exception
		CException horstableau;
		horstableau.EXCModifierValeur(Position_horsliste);
		throw(horstableau);
	}

	// La position est dans le tableau : on retourne l��l�ment demand�
	return pLTLISListe[position];
}

template <class LType> void CListe<LType>::LISModifierElement(LType element, unsigned int position)
{
	if (position >= uiLISTaille)
	{
		// L�insertionalieu hors tableau : lev�e d�une exception
		CException horstableau;
		horstableau.EXCModifierValeur(Position_horsliste);
		throw(horstableau);
	}

	// La position est dans le tableau : on modifie l��l�ment demand�
	pLTLISListe[position] = element;
}

template <class LType> LType& CListe<LType>::operator[](unsigned int position)
{
	if (position >= uiLISTaille)
	{ // L�insertionalieu hors tableau : lev�e d�une exception
		CException horstableau;
		horstableau.EXCModifierValeur(Position_horsliste);
		throw(horstableau);
	}

	// La position est dans le tableau : on acc�de � l��l�ment demand�
	return(pLTLISListe[position]);
}

template <class LType> void CListe<LType>::LISSupprimerElement(unsigned int position)
{
	int iBoucle;

	if (position >= uiLISTaille)
	{ // L�insertionalieu hors tableau : lev�e d�une exception
		CException horstableau;
		horstableau.EXCModifierValeur(Position_horsliste);
		throw(horstableau);
	}

	for (iBoucle = position; iBoucle < uiLISTaille - 1; iBoucle++)
		pLTLISListe[iBoucle] = pLTLISListe[iBoucle + 1];
	uiLISTaille--;

	// L��l�ment est supprim�
}
