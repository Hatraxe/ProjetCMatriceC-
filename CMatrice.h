#include <iostream>
#include "CException.h"
#include "string.h"
#include "stdio.h"

#pragma once
using namespace std;

template <class MType> class CMatrice
{
private:
	unsigned int uiMATNbColonnes;
	unsigned int uiMATNbLignes;
	MType** ppMTMATMatrice;

public:
	//Déclaration des constructeurs
	CMatrice<MType>(); // constructeur par défaut
	CMatrice<MType>(unsigned int uiParamLignes, unsigned int iParamColonnes); // constructeur de confort
	CMatrice<MType>(const CMatrice<MType>& MATParam); //constructeur de recopie

	//Déclaration du destrcuteur
	~CMatrice<MType>();


	//Getters

	unsigned int MATLireNbColonnesV2();
	unsigned int MATLireNbLignesV2();
	MType MATLireElementV2(unsigned int uiParamLignes, unsigned int uiParamColonnes);
	MType** MATLireMatriceV2();

	//Setters
	void MATModifierElementV2(unsigned int uiParamLignes, unsigned int uiParamColonnes, MType element);

	//Déclarations des méthodes

	void MATAfficherMatriceV2();


	//Déclaration des surcharges

	CMatrice<MType> operator+(CMatrice<MType> MATParamMatrice)const;

	CMatrice<MType> operator-(CMatrice<MType> MATParamMatrice)const;

	CMatrice<MType> operator*(CMatrice<MType> MATParamMatrice)const;
	CMatrice<MType> operator*(MType MTParam)const;

	CMatrice<MType> operator/(MType MTParam)const;

	MType*& operator[](unsigned int iIndice);

	CMatrice<MType>& operator=(const CMatrice<MType>& MATParam);


};

CMatrice<double> operator*(double mtpParam, CMatrice<double> mtpParamMatrice);



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



template <class MType> CMatrice<MType>::CMatrice()
{
	uiMATNbColonnes = 0;
	uiMATNbLignes = 0;
	ppMTMATMatrice = nullptr;

}

template <class MType> CMatrice<MType>::~CMatrice()
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
	{
		delete[] ppMTMATMatrice[uiBoucle];
	}
	delete(ppMTMATMatrice);
}

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

template <class MType> unsigned int CMatrice<MType>::MATLireNbColonnesV2() {
	return uiMATNbColonnes;
}



template <class MType> unsigned int CMatrice<MType>::MATLireNbLignesV2() {
	return uiMATNbLignes;
}

template <class MType> MType** CMatrice<MType>::MATLireMatriceV2() {
	return ppMTMATMatrice;
}


template <class MType> void CMatrice<MType>::MATAfficherMatriceV2() {
	for (unsigned int uiLigneIterator = 0; uiLigneIterator < uiMATNbLignes; uiLigneIterator++) {
		for (unsigned int uiColonneIterator = 0; uiColonneIterator < uiMATNbColonnes; uiColonneIterator++)
		{
			cout << ppMTMATMatrice[uiLigneIterator][uiColonneIterator] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}


template <class MType> MType CMatrice<MType>::MATLireElementV2(unsigned int uiParamLignes, unsigned int uiParamColonnes) {
	return ppMTMATMatrice[uiParamLignes][uiParamColonnes];
}


template<class MType> CMatrice<MType> CMatrice<MType>::operator+(CMatrice<MType> MATParamMatrice)const
{

	if ((uiMATNbLignes != MATParamMatrice.uiMATNbLignes) || (uiMATNbColonnes != MATParamMatrice.uiMATNbColonnes))
	{

		CException erreurtaille;
		erreurtaille.EXCModifierValeur(2);
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
	if (uiMATNbLignes != MATParamMatrice.MATLireNbLignesV2() || uiMATNbColonnes != MATParamMatrice.MATLireNbColonnesV2())
	{
		CException erreurtaille;
		erreurtaille.EXCModifierValeur(2);
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

	if (uiMATNbColonnes != MATParamMatrice.MATLireNbLignesV2())
	{
		CException erreurtaille;
		erreurtaille.EXCModifierValeur(2);
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

template <class MType> void CMatrice<MType>::MATModifierElementV2(unsigned int uiParamLignes, unsigned int uiParamColonnes, MType element)
{
	ppMTMATMatrice[uiParamLignes][uiParamColonnes] = element;
}