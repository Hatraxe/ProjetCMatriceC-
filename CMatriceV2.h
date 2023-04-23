#include <iostream>
#include "CException.h"
#include "string.h"
#include "stdio.h"

#pragma once
using namespace std;
template <class MType> class CMatriceV2
{
private:
	unsigned int uiMATNbColonnes;
	unsigned int uiMATNbLignes;
	MType** ppMTMATMatrice;

public:
	//Déclaration des constructeurs
	CMatriceV2<MType>(); // constructeur par défaut
	CMatriceV2<MType>(unsigned int uiParamLignes, unsigned int iParamColonnes); // constructeur de confort
	CMatriceV2<MType>(const CMatriceV2<MType>& MATParam); //constructeur de recopie

	//Déclaration du destrcuteur
	~CMatriceV2<MType>();


	//Getters

	unsigned int MATLireNbColonnesV2();
	unsigned int MATLireNbLignesV2();
	MType MATLireElementV2(unsigned int uiParamLignes, unsigned int uiParamColonnes);
	MType** MATLireMatriceV2();

	//Setters
	void MATModifierElementV2(unsigned int uiParamLignes, unsigned int uiParamColonnes, MType element);
	
	

	//Déclarations des méthodes
	
	void MATAfficherMatriceV2();
	

	
	CMatriceV2<MType> MATTransposerV2();

	//Déclaration des surcharges

	CMatriceV2<MType> operator+(CMatriceV2<MType> MATParamMatrice)const;

	CMatriceV2<MType> operator-(CMatriceV2<MType> MATParamMatrice)const;

	CMatriceV2<MType> operator*(CMatriceV2<MType> MATParamMatrice)const;
	CMatriceV2<MType> operator*(MType MTParam)const;
	
	CMatriceV2<MType> operator/(MType MTParam)const;
	
	

	MType*& operator[]( unsigned int iIndice);
	CMatriceV2<MType>& operator=(const CMatriceV2<MType>& MATParam);
	
	
};

 CMatriceV2<double> operator*(double mtpParam, CMatriceV2<double> mtpParamMatrice);



template <class MType> CMatriceV2<MType>::CMatriceV2(unsigned int uiParamLignes, unsigned int uiParamColonnes) 
{
	uiMATNbColonnes = uiParamColonnes;
	uiMATNbLignes = uiParamLignes;
	ppMTMATMatrice = new MType * [uiMATNbLignes];
	for (unsigned int uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
	{

		ppMTMATMatrice[uiBoucle] = new MType [uiMATNbColonnes];

	}
}



template <class MType> CMatriceV2<MType>::CMatriceV2() 
{
	uiMATNbColonnes = 0;
	uiMATNbLignes = 0;
	ppMTMATMatrice=nullptr; 

}

template <class MType> CMatriceV2<MType>::~CMatriceV2() 
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++) 
	{
		delete[] ppMTMATMatrice[uiBoucle];
	}
	delete(ppMTMATMatrice);
}

template <class MType> CMatriceV2<MType>::CMatriceV2(const CMatriceV2<MType>& MATParam)
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

template <class MType> unsigned int CMatriceV2<MType>::MATLireNbColonnesV2() {
	return uiMATNbColonnes;
}



template <class MType> unsigned int CMatriceV2<MType>::MATLireNbLignesV2() {
	return uiMATNbLignes;
}



template <class MType> MType** CMatriceV2<MType>::MATLireMatriceV2() {
	return ppMTMATMatrice;
}






template <class MType> void CMatriceV2<MType>::MATAfficherMatriceV2() {
	for (unsigned int uiLigneIterator = 0; uiLigneIterator < uiMATNbLignes; uiLigneIterator++) {
		for (unsigned int uiColonneIterator = 0; uiColonneIterator < uiMATNbColonnes; uiColonneIterator++)
		{
			cout << ppMTMATMatrice[uiLigneIterator][uiColonneIterator] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}





template <class MType> MType CMatriceV2<MType>::MATLireElementV2(unsigned int uiParamLignes, unsigned int uiParamColonnes) {
	return ppMTMATMatrice[uiParamLignes][uiParamColonnes];
}




template <class MType>  CMatriceV2<MType> CMatriceV2<MType>::MATTransposerV2()
{
	
	CMatriceV2<MType> ppMTTransposer(uiMATNbColonnes, uiMATNbLignes); //Creation d'une matrice des tailles de ligne = this.colonnes et colonne = this.lignes

	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < uiMATNbLignes; uiBoucleLignes++) 
	{
		for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < uiMATNbColonnes; uiBoucleColonnes++)
		{
			ppMTTransposer.ppMTMATMatrice[uiBoucleColonnes][uiBoucleLignes] = ppMTMATMatrice[uiBoucleLignes][uiBoucleColonnes];
		}
	}

	return ppMTTransposer;
}




template<class MType> CMatriceV2<MType> CMatriceV2<MType>::operator+(CMatriceV2<MType> MATParamMatrice)const 
{
	
	if ((uiMATNbLignes != MATParamMatrice.uiMATNbLignes) || (uiMATNbColonnes != MATParamMatrice.uiMATNbColonnes))
	{

		CException erreurtaille;
		erreurtaille.EXCModifierValeur(2);
		throw (erreurtaille);
	}

	CMatriceV2<MType> MATAddition(uiMATNbLignes, uiMATNbColonnes);
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



template<class MType> CMatriceV2<MType> CMatriceV2<MType>::operator-(CMatriceV2<MType> MATParamMatrice) const 
{
	if ((uiMATNbLignes != MATParamMatrice.uiMATNbLignes) || (uiMATNbColonnes != MATParamMatrice.uiMATNbColonnes))
	{
		CException erreurtaille;
		erreurtaille.EXCModifierValeur(2);
		throw (erreurtaille);
	}

	CMatriceV2<MType> MATSoustraction(uiMATNbLignes, uiMATNbColonnes);
	// Effectuer la soustraction des deux matrices
	for (unsigned int uiLignes = 0; uiLignes < uiMATNbLignes; uiLignes++)
	{
		for (unsigned int uiColonnes = 0; uiColonnes < uiMATNbColonnes; uiColonnes++)
		{
			MATSoustraction.ppMTMATMatrice[uiLignes][uiColonnes] = ppMTMATMatrice[uiLignes][uiColonnes] - MATParamMatrice.ppMTMATMatrice[uiLignes][uiColonnes];
		}
	}

	return MATSoustraction;
}


template<class MType> CMatriceV2<MType> CMatriceV2<MType>::operator*(CMatriceV2<MType> MATParamMatrice)const 
{

	if (uiMATNbColonnes != MATParamMatrice.MATLireNbLignesV2())
	{
		CException erreurtaille;
		erreurtaille.EXCModifierValeur(2);
		throw (erreurtaille);
	}

	CMatriceV2<MType> MATResMultiplication(uiMATNbLignes, MATParamMatrice.uiMATNbColonnes);

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


template<class MType> CMatriceV2<MType> CMatriceV2<MType>::operator*(MType MTParam)const 
{

	CMatriceV2<MType> MATResMultiplication(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int uiLignes = 0; uiLignes < uiMATNbLignes; uiLignes++) 
	{
		for (unsigned int uiColonnes = 0; uiColonnes < uiMATNbColonnes; uiColonnes++) 
		{
			MATResMultiplication.ppMTMATMatrice[uiLignes][uiColonnes] = MTParam * ppMTMATMatrice[uiLignes][uiColonnes];
		}
	}
	return MATResMultiplication;
}

template<class MType> CMatriceV2<MType> CMatriceV2<MType>::operator/(MType MTParam)const
{
	CMatriceV2<MType> MATResDivision(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int uiLignes = 0; uiLignes < uiMATNbLignes; uiLignes++)
	{
		for (unsigned int uiColonnes = 0; uiColonnes < uiMATNbColonnes; uiColonnes++)
		{
			MATResDivision.ppMTMATMatrice[uiLignes][uiColonnes] = ppMTMATMatrice[uiLignes][uiColonnes] / MTParam;
		}
	}
	return MATResDivision;

}

template<class MType> MType*& CMatriceV2<MType>::operator[](unsigned int uiIndice)
{
	return ppMTMATMatrice[uiIndice];
}



template<class MType> CMatriceV2<MType>& CMatriceV2<MType>::operator=(const CMatriceV2<MType>& MATParam) 
{

	for (unsigned int uiBoucle =0; uiBoucle < uiMATNbLignes; uiBoucle++)
	{
		delete(ppMTMATMatrice[uiBoucle]);
	}

	delete(ppMTMATMatrice);

	uiMATNbColonnes = MATParam.uiMATNbColonnes;
	uiMATNbLignes = MATParam.uiMATNbLignes;
	ppMTMATMatrice = new MType *[uiMATNbLignes];

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

template <class MType> void CMatriceV2<MType>::MATModifierElementV2(unsigned int uiParamLignes, unsigned int uiParamColonnes, MType element) 
{
	ppMTMATMatrice[uiParamLignes][uiParamColonnes] = element;
}





