#include <iostream>
#include "CException.h"
#include "string.h"
#include "stdio.h"
#pragma once
using namespace std;

#define Division_Par_Zero 101
#define Erreur_Taille 102
#define Hors_Tableau 103

template <class MType> class CMatrice
{
private:

	//Attributs

	unsigned int uiMATNbColonnes;  //Nombre entier correspondant au nombre de colonnes de la matrice
	unsigned int uiMATNbLignes;  //Nombre entier correspondant au nombre de lignes de la matrice
	MType** ppMTMATMatrice;  //Pointeur de pointeur sur le type de la classe (MType), permet de creer un tableau à 2 dimensions

public:

	//Déclaration des constructeurs

	/* Constructeur par défaut de la classe
	Entree : neant
	Pre-condition : neant
	Sortie : neant
	Post-condition : La matrice est initialisee à vide et les valeurs de nombre de lignes et de colonnes mis a 0
	*/
	CMatrice<MType>(); 


	/* Constructeur de confort de la classe
	Entree : Le nombre de lignes et le nombre de colonnes
	Pre-condition : neant
	Sortie : neant
	Post-condition : La matrice est initialisee avec les valeurs de nombre de lignes et de colonnes sont remplacées par celles passées en parametre
	*/
	CMatrice<MType>(unsigned int uiParamLignes, unsigned int iParamColonnes); 


	/* Constructeur de recopie de la classe
	Entree : L'objet que l’on recopie dans l’objet en cours
	Pre-condition : neant
	Sortie : neant
	Post-condition : L’objet en cours contient une copie de l’objet passé en paramètre
	*/
	CMatrice<MType>(const CMatrice<MType>& MATParam); //constructeur de recopie


	/* Destructeur de la classe
	Entree : neant
	Pre-condition : neant
	Sortie : neant
	Post-condition : La matrice a ete detruite
	*/
	~CMatrice<MType>(); 


	//Accesseurs de lecture

	/* Accesseur de lecture de l'attribut nombre de colonnes
	Entree : neant
	Pre-condition : neant
	Sortie : le nombre de colonnes
	Post-condition : le nombre de colonnes est retourne
	*/
	unsigned int MATLireNbColonnes();


	/* Accesseur de lecture de l'attribut nombre de lignes
	Entree : neant
	Pre-condition : neant
	Sortie : le nombre de lignes
	Post-condition : le nombre de lignes est retourne
	*/
	unsigned int MATLireNbLignes();


	/* Accesseur de lecture de l'attribut ppMTMATMatrice
	Entree : neant
	Pre-condition : neant
	Sortie : le ppMTMATMatrice de l'objet en cours
	Post-condition : le pointeur de pointeur de MType est retourne
	*/
	MType** MATLireMatrice();


	/* Accesseur de lecture d'un element dans la matrice en focntion d'un indice de ligne et de colonne
	Entree : neant
	Pre-condition : neant
	Sortie : l'element a l'indice de la colonne et de la ligne passe en parametre
	Post-condition : (l'element est retourne) ou (CException horstableau est retourne : (uiParamLignes >= uiMATNbLignes ou  uiParamColonnes >= uiMATNbColonnes))
	*/
	MType MATLireElement(unsigned int uiParamLignes, unsigned int uiParamColonnes);
	

	//Accesseurs en ecriture

	/* Accesseur en ecriture d'un element dans la matrice en focntion d'un indice de ligne et de colonne
	Entree : neant
	Pre-condition : neant
	Sortie : neant
	Post-condition : (l'element a l'indice de ligne et de colonne passe en parametre est modifier et remplacer par element) ou (CException horstableau est retourne : (uiParamLignes >= uiMATNbLignes ou  uiParamColonnes >= uiMATNbColonnes))
	*/
	void MATModifierElement(unsigned int uiParamLignes, unsigned int uiParamColonnes, MType element);


	//Déclaration des surcharges

	CMatrice<MType> operator+(CMatrice<MType> MATParamMatrice)const;

	CMatrice<MType> operator-(CMatrice<MType> MATParamMatrice)const;

	CMatrice<MType> operator*(CMatrice<MType> MATParamMatrice)const;
	CMatrice<MType> operator*(MType MTParam)const;

	CMatrice<MType> operator/(MType MTParam)const;

	MType*& operator[](unsigned int iIndice);

	CMatrice<MType>& operator=(const CMatrice<MType>& MATParam);
};


/* Cette focntion permet de multiplier un double par un CMatrice
	Entree : un double, et une matrice 
	Pre-condition : neant
	Sortie : une matrice de double 
	Post-condition : La matrice retourne contient les valeurs correspondant au double * la matrice
	*/
CMatrice<double> operator*(double mtpParam, CMatrice<double> mtpParamMatrice);



/* Constructeur par défaut de la classe
	Entree : neant
	Pre-condition : neant
	Sortie : neant
	Post-condition : La matrice est initialisee à vide et les valeurs de nombre de lignes et de colonnes mis a 0
	*/
template <class MType> CMatrice<MType>::CMatrice()
{
	uiMATNbColonnes = 0;
	uiMATNbLignes = 0;
	ppMTMATMatrice = nullptr;
}


/* Constructeur de confort de la classe
	Entree : Le nombre de lignes et le nombre de colonnes
	Pre-condition : neant
	Sortie : neant
	Post-condition : La matrice est initialisee avec les valeurs de nombre de lignes et de colonnes sont remplacées par celles passées en parametre
	*/
template <class MType> CMatrice<MType>::CMatrice(unsigned int uiParamLignes, unsigned int uiParamColonnes)
{
	uiMATNbColonnes = uiParamColonnes;
	uiMATNbLignes = uiParamLignes;
	ppMTMATMatrice = new MType * [uiMATNbLignes];

	for (unsigned int uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
	{
		ppMTMATMatrice[uiBoucle] = new MType[uiMATNbColonnes];
	}
}


/* Constructeur de recopie de la classe
	Entree : L'objet que l’on recopie dans l’objet en cours
	Pre-condition : neant
	Sortie : neant
	Post-condition : L’objet en cours contient une copie de l’objet passé en paramètre
	*/
template <class MType> CMatrice<MType>::CMatrice(const CMatrice<MType>& MATParam)
{
	uiMATNbColonnes = MATParam.uiMATNbColonnes;
	uiMATNbLignes = MATParam.uiMATNbLignes;
	ppMTMATMatrice = new MType * [uiMATNbLignes];

	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < uiMATNbLignes; uiBoucleLignes++)
	{
		ppMTMATMatrice[uiBoucleLignes] = new MType[uiMATNbColonnes];
		for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < uiMATNbColonnes; uiBoucleColonnes++)
		{
			ppMTMATMatrice[uiBoucleLignes][uiBoucleColonnes] = MATParam.ppMTMATMatrice[uiBoucleLignes][uiBoucleColonnes];
		}
	}
}


/* Destructeur de la classe
Entree : neant
Pre-condition : neant
Sortie : neant
Post-condition : La matrice a ete detruite
*/
template <class MType> CMatrice<MType>::~CMatrice()
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
	{
		delete[] ppMTMATMatrice[uiBoucle];
	}
	delete(ppMTMATMatrice);
}



/* Accesseur de lecture de l'attribut nombre de colonnes
Entree : neant
Pre-condition : neant
Sortie : le nombre de colonnes
Post-condition : le nombre de colonnes est retourne
*/
template <class MType> unsigned int CMatrice<MType>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
}


/* Accesseur de lecture de l'attribut nombre de lignes
	Entree : neant
	Pre-condition : neant
	Sortie : le nombre de lignes
	Post-condition : le nombre de lignes est retourne
	*/
template <class MType> unsigned int CMatrice<MType>::MATLireNbLignes() 
{
	return uiMATNbLignes;
}


/* Accesseur de lecture d'un element dans la matrice en focntion d'un indice de ligne et de colonne
	Entree : neant
	Pre-condition : neant
	Sortie : l'element a l'indice de la colonne et de la ligne passe en parametre
	Post-condition : (l'element est retourne) ou (CException horstableau est retourne : (uiParamLignes >= uiMATNbLignes ou  uiParamColonnes >= uiMATNbColonnes))
	*/
template <class MType> MType CMatrice<MType>::MATLireElement(unsigned int uiParamLignes, unsigned int uiParamColonnes)
{
	if (uiParamLignes > uiMATNbLignes || uiParamColonnes > uiParamColonnes)
	{
		CException horstableau;
		horstableau.EXCModifierValeur(Hors_Tableau);
		throw (horstableau);
	}
	return ppMTMATMatrice[uiParamLignes][uiParamColonnes];
}


/* Accesseur de lecture de l'attribut ppMTMATMatrice
Entree : neant
Pre-condition : neant
Sortie : le ppMTMATMatrice de l'objet en cours
Post-condition : le pointeur de pointeur de MType est retourne
*/
template <class MType> MType** CMatrice<MType>::MATLireMatrice()
{
	return ppMTMATMatrice;
}



/* Accesseur en ecriture d'un element dans la matrice en focntion d'un indice de ligne et de colonne
	Entree : neant
	Pre-condition : neant
	Sortie : neant
	Post-condition : (l'element a l'indice de ligne et de colonne passe en parametre est modifier et remplacer par element) ou (CException horstableau est retourne : (uiParamLignes >= uiMATNbLignes ou  uiParamColonnes >= uiMATNbColonnes))
	*/
template <class MType> void CMatrice<MType>::MATModifierElement(unsigned int uiParamLignes, unsigned int uiParamColonnes, MType element)
{
	if (uiParamLignes > uiMATNbLignes || uiParamColonnes > uiParamColonnes)
	{
		CException horstableau;
		horstableau.EXCModifierValeur(Hors_Tableau);
		throw (horstableau);
	}

	ppMTMATMatrice[uiParamLignes][uiParamColonnes] = element;
}


template<class MType> CMatrice<MType> CMatrice<MType>::operator+(CMatrice<MType> MATParamMatrice)const
{
	if ((uiMATNbLignes != MATParamMatrice.uiMATNbLignes) || (uiMATNbColonnes != MATParamMatrice.uiMATNbColonnes))
	{
		CException erreurtaille;
		erreurtaille.EXCModifierValeur(Erreur_Taille);
		throw (erreurtaille);
	}
	CMatrice<MType> MATAddition(uiMATNbLignes, uiMATNbColonnes);
	// Additionner les éléments des deux matrices et les stocker dans la nouvelle matrice
	for (unsigned int uiLignes = 0; uiLignes < uiMATNbLignes; uiLignes++)
	{
		for (unsigned int uiColonnes = 0; uiColonnes < uiMATNbColonnes; uiColonnes++)
		{
			MATAddition.ppMTMATMatrice[uiLignes][uiColonnes] = ppMTMATMatrice[uiLignes][uiColonnes] + MATParamMatrice.ppMTMATMatrice[uiLignes][uiColonnes];
		}
	}
	// Retourner la nouvelle matrice résultante
	return MATAddition;
}


template<class MType> CMatrice<MType> CMatrice<MType>::operator-(CMatrice<MType> MATParamMatrice) const
{
	if (uiMATNbLignes != MATParamMatrice.MATLireNbLignes() || uiMATNbColonnes != MATParamMatrice.MATLireNbColonnes())
	{
		CException erreurtaille;
		erreurtaille.EXCModifierValeur(Erreur_Taille);
		throw (erreurtaille);
	}
	CMatrice<MType> MATResSoustraction(uiMATNbLignes, uiMATNbColonnes);
	// Effectuer la soustraction des deux matrices
	for (unsigned int uiLignes = 0; uiLignes < uiMATNbLignes; uiLignes++)
	{
		for (unsigned int uiColonnes = 0; uiColonnes < uiMATNbColonnes; uiColonnes++)
		{

			MATResSoustraction.ppMTMATMatrice[uiLignes][uiColonnes] = ppMTMATMatrice[uiLignes][uiColonnes] - MATParamMatrice[uiLignes][uiColonnes];
		}
	}
	return MATResSoustraction;
}


template<class MType> CMatrice<MType> CMatrice<MType>::operator*(CMatrice<MType> MATParamMatrice)const
{
	if (uiMATNbColonnes != MATParamMatrice.MATLireNbLignes())
	{
		CException erreurtaille;
		erreurtaille.EXCModifierValeur(Erreur_Taille);
		throw (erreurtaille);
	}
	CMatrice<MType> MATResMultiplication(uiMATNbLignes, MATParamMatrice.uiMATNbColonnes);
	// Effectuer la multiplication
	for (unsigned int uiLignes = 0; uiLignes < uiMATNbLignes; uiLignes++)
	{
		for (unsigned int uiColonnes = 0; uiColonnes < MATParamMatrice.uiMATNbColonnes; uiColonnes++)
		{
			MType MTSomme = 0;

			for (unsigned int uiBoucle = 0; uiBoucle < uiMATNbColonnes; uiBoucle++)
			{
				MTSomme += ppMTMATMatrice[uiLignes][uiBoucle] * MATParamMatrice.ppMTMATMatrice[uiBoucle][uiColonnes];
			}

			MATResMultiplication.ppMTMATMatrice[uiLignes][uiColonnes] = MTSomme;
		}
	}
	return MATResMultiplication;
}


template<class MType> CMatrice<MType> CMatrice<MType>::operator*(MType MTParam)const
{
	CMatrice<MType> MATResMultiplication(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int uiLignes = 0; uiLignes < uiMATNbLignes; uiLignes++)
	{
		for (unsigned int uiColonnes = 0; uiColonnes < uiMATNbColonnes; uiColonnes++)
		{
			MATResMultiplication.ppMTMATMatrice[uiLignes][uiColonnes] = MTParam * ppMTMATMatrice[uiLignes][uiColonnes];
		}
	}
	return MATResMultiplication;
}


template<class MType> CMatrice<MType> CMatrice<MType>::operator/(MType MTParam)const
{
	if (MTParam == 0)
	{
		CException divisionzero;
		divisionzero.EXCModifierValeur(Division_Par_Zero);
		throw (divisionzero);
	}
	CMatrice<MType> MATResDivision(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int uiLignes = 0; uiLignes < uiMATNbLignes; uiLignes++)
	{
		for (unsigned int uiColonnes = 0; uiColonnes < uiMATNbColonnes; uiColonnes++)
		{
			MATResDivision.ppMTMATMatrice[uiLignes][uiColonnes] = ppMTMATMatrice[uiLignes][uiColonnes] / MTParam;
		}
	}
	return MATResDivision;
}

template<class MType> MType*& CMatrice<MType>::operator[](unsigned int uiIndice)
{
	return ppMTMATMatrice[uiIndice];
}


template<class MType> CMatrice<MType>& CMatrice<MType>::operator=(const CMatrice<MType>& MATParam)
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
	{
		delete(ppMTMATMatrice[uiBoucle]);
	}

	delete(ppMTMATMatrice);
	uiMATNbColonnes = MATParam.uiMATNbColonnes;
	uiMATNbLignes = MATParam.uiMATNbLignes;
	ppMTMATMatrice = new MType * [uiMATNbLignes];

	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < uiMATNbLignes; uiBoucleLignes++)
	{
		ppMTMATMatrice[uiBoucleLignes] = new MType[uiMATNbColonnes];

		for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < uiMATNbColonnes; uiBoucleColonnes++)
		{
			ppMTMATMatrice[uiBoucleLignes][uiBoucleColonnes] = MATParam.ppMTMATMatrice[uiBoucleLignes][uiBoucleColonnes];
		}
	}
	return *this;
}