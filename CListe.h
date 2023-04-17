#pragma once
#include "CException.h"

#define Ajout_impossible 101
#define Suppression_impossible 102
#define Position_horsliste 103
template <class LType> class CListe
{
	// Cette classe représente une ou plusieurs listes d’éléments

		// Attributs :
private:
	unsigned int uiLISTaille; //Cet attribut contient le nombre d’éléments de la liste
	LType* pLTLISListe; //sigle LT signifie l'appartenance au type LType

	// Primitives :
public:

	CListe();
	/* Constructeur par défaut de la classe
	E : néant
	nécessite : néant
	S : néant
	entraîne : la liste est initialisée à vide */


	CListe(const CListe& LISParam);
	/* Constructeur de recopie de la classe
	E : l’objet que l’on recopie dans l’objet en cours
	nécessite : néant
	S : néant
	entraîne : L’objet en cours contient une copie de l’objet passé en paramètre */

	CListe(unsigned int taille);

	~CListe();
	/* Destructeur de la classe
	E : néant
	nécessite : néant
	S : néant
	entraîne : l’exception est détruite*/

	CListe<LType>& operator=(const CListe<LType>& LISParam);
	/* Surcharge de l’opérateur d’affectation
	E : l’objet que l’on affecte dans l’objet en cours
	nécessite : néant
	S : L’objet en cours qui a été recopié
	entraîne : (L’objet en cours contient une copie de l’objet passé en paramètre) ou
	(Exception Ajout impossible : pas assez de mémoire libre) */


	void LISAjouterElement(LType element, unsigned int position);
	/* Cette fonction permet d’ajouter un élément dans la liste à la position spécifiée
	E : elem, la valeur à ajouter
	pos, la position d’insertion
	nécessite : néant
	S : néant
	entraîne : (l’élément est ajouté à la position requise) ou
	(Exception Ajout impossible : pas assez de mémoire libre) ou
	(Exception Position hors liste : pos>taille) */


	unsigned int LISLireTaille();
	/* Cette fonction permet de connaître la taille de la liste
	E : rien
	nécessite : néant
	S : la taille de la liste
	entraîne : (la taille de la liste est retournée) */

	LType LISLireElement(unsigned int position);
	/* Cette fonction permet de lire la valeur d’un élément dans la liste
E : la position de l’élément à lire
nécessite : néant
S : la valeur de l’élément
entraîne : (la valeur de l’élément est retournée) ou
(Exception Position hors liste : pos>=taille) */


	void LISModifierElement(LType element, unsigned int position);
	/* Cette fonction permet de modifier la valeur d’un élément dans la liste
	E : elem, la nouvelle valeur
   pos, la position de l’élément à modifier
   nécessite : néant
   S : néant
   entraîne : (L’élément est modifié) ou
   (Exception Position hors liste : pos>=taille) */


	LType& operator[](unsigned int position);
	/* Cette fonction permet d’accéder à la valeur d’un élément dans la liste
	E : la position de l’élément à lire
	nécessite : néant
	S : l’élément
	entraîne : (l’élément est accessible) ou
	(Exception Position hors liste : pos>=taille) */


	void LISSupprimerElement(unsigned int position);
	/* Cette fonction permet de supprimer un élément dans la liste à la position spécifiée
	E : pos, la position de suppression
	nécessite : néant
	S : néant
	entraîne : (l’élément est supprimé à la position requise) ou
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
	//pLTLISListe pointe sur une zone mémoire allouée mais “vide”
	for (iBoucle = 0; iBoucle < uiLISTaille; iBoucle++)
		pLTLISListe[iBoucle] = LISParam.pLTLISListe[iBoucle];
	// la liste objet est recopiée dans l’objet en cours
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
	// la liste objet est recopiée dans l’objet en cours
	return *this;
}


template <class LType> void CListe<LType>::LISAjouterElement(LType element, unsigned int position)
{
	LType* pLTtempo;
	
	int iBoucle;

	if (position > uiLISTaille)
	{ // L’insertionalieu hors tableau : levée d’une exception
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
	// L’élément est inséré dans la liste à la position demandée
}

template <class LType> unsigned int CListe<LType>::LISLireTaille()
{
	return (uiLISTaille);
}


template <class LType> LType CListe<LType>::LISLireElement(unsigned int position)
{
	if (position >= uiLISTaille)
	{ // L’insertion a lieu hors tableau : levée d’une exception
		CException horstableau;
		horstableau.EXCModifierValeur(Position_horsliste);
		throw(horstableau);
	}

	// La position est dans le tableau : on retourne l’élément demandé
	return pLTLISListe[position];
}

template <class LType> void CListe<LType>::LISModifierElement(LType element, unsigned int position)
{
	if (position >= uiLISTaille)
	{
		// L’insertionalieu hors tableau : levée d’une exception
		CException horstableau;
		horstableau.EXCModifierValeur(Position_horsliste);
		throw(horstableau);
	}

	// La position est dans le tableau : on modifie l’élément demandé
	pLTLISListe[position] = element;
}

template <class LType> LType& CListe<LType>::operator[](unsigned int position)
{
	if (position >= uiLISTaille)
	{ // L’insertionalieu hors tableau : levée d’une exception
		CException horstableau;
		horstableau.EXCModifierValeur(Position_horsliste);
		throw(horstableau);
	}

	// La position est dans le tableau : on accède à l’élément demandé
	return(pLTLISListe[position]);
}

template <class LType> void CListe<LType>::LISSupprimerElement(unsigned int position)
{
	int iBoucle;

	if (position >= uiLISTaille)
	{ // L’insertionalieu hors tableau : levée d’une exception
		CException horstableau;
		horstableau.EXCModifierValeur(Position_horsliste);
		throw(horstableau);
	}

	for (iBoucle = position; iBoucle < uiLISTaille - 1; iBoucle++)
		pLTLISListe[iBoucle] = pLTLISListe[iBoucle + 1];
	uiLISTaille--;

	// L’élément est supprimé
}
