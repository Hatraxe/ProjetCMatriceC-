#pragma once
#include "CListe.h"
#include <iostream>
#include "CException.h"
#include "string.h"
#include "stdio.h"

using namespace std;
template <class MType> class CMatrice
{
private:
	//Attributs
	int iMATNbrColonnes;
	int iMATNbrLignes;
	CListe<MType>* pLISMATMatrice;
public:
	//Déclaration des constructeurs
	CMatrice<MType>(); // constructeur par défaut
	CMatrice<MType>(int iParamLignes, int iParamColonnes); // constructeur de confort
	CMatrice<MType>(const CMatrice<MType>& MATParam); //constructeur de recopie

	//Déclaration du destrcuteur
	~CMatrice<MType>();



	//Getters

	int MATLireNbrColonnes();
	int MATLireNbrLignes();
	CListe<MType>* MATLireMatrice();

	//Setters

	void MATModifierNbrColonnes(int iColonnes);
	void MATModifierNbrLignes(int iLignes);
	void MATModifierMatrice(int iParamLignes, int iParamColonnes, CListe<MType>* LISParamMatrice);

	//Déclarations des méthodes

	void MATAfficherMatrice();
	void MATModifierElement2D(int iParamLignes, int iParamColonnes, MType MTParamElement);
	void MATModifierElement1D(int iIndice, MType MTParamElement);
	MType MATLireTableau(int iParamIndice);
	CMatrice<MType> MATTransposer();

	//Déclaration des surcharges

	CMatrice<MType> operator+(CMatrice<MType> MTParamMatrice)const;

	CMatrice<MType> operator-(CMatrice<MType> MTParamMatrice)const;

	CMatrice<MType> operator*(CMatrice<MType> MTParamMatrice)const;
	CMatrice<MType> operator*(MType mtpParam)const;
	//friend CMatrice<MType> operator*(MType mtparam , CMatrice<double> MTParamMatrice);

	CMatrice<MType> operator/(CMatrice<MType> MATDivision)const;
	CMatrice<MType> operator/(MType MTParamMatrice)const;
	//friend CMatrice<MType> operator/(MType mtparam, CMatrice<double> MTParamMatrice);

	MType& operator[](const int iIndice);
	CMatrice<MType>& operator=(CMatrice<MType> MATParam);
};

CMatrice<double> operator*(double mtpParam, CMatrice<double> MTParamMatrice);
CMatrice<double> operator/(double mtpParam, CMatrice<double> MTParamMatrice);

/*************************************************************************************************************
* Resume : Constructeur de confort
* Entrees : int iParamLignes, int iParamColonnes
* Preconditions : {(iParamLignes && iParamColonnes )>= 0}
* Sorties :
* Postconditions : {Creation d'un objet CMatrice avec le nombre souhaité de colonnes et de lignes}
***************************************************************************************************************/

template <class MType> CMatrice<MType>::CMatrice(int iParamLignes, int iParamColonnes) {
	iMATNbrColonnes = iParamColonnes;
	iMATNbrLignes = iParamLignes;
	pLISMATMatrice = new MType[iMATNbrColonnes * iMATNbrLignes];
}

/*************************************************************************************************************
* Resume : Constructeur par default
* Entrees:
* Preconditions: {}
* Sorties:
* Postconditions: {Creation d'un objet CMatrice}
***************************************************************************************************************/

template <class MType> CMatrice<MType>::CMatrice() {
	iMATNbrColonnes = 1;
	iMATNbrLignes = 1;
//	pLISMATMatrice = new MType[iMATNbrColonnes * iMATNbrLignes];

}

/*************************************************************************************************************
* Resume : Constructeur de recoîe
* Entrees: const CMatrice<MType> &MATParam
* Preconditions: {}
* Sorties:
* Postconditions: {Recopie de la CMatrice MATParam}
***************************************************************************************************************/
template <class MType> CMatrice<MType>::CMatrice(const CMatrice<MType>& MATParam) {
/*	iMATNbrColonnes = MATParam.iMATNbrColonnes;
	iMATNbrLignes = MATParam.iMATNbrLignes;

	pLISMATMatrice = new MType[iMATNbrColonnes * iMATNbrLignes];
	for (int iIterator = 0; iIterator < iMATNbrColonnes * iMATNbrLignes; iIterator++) {
		pLISMATMatrice[iIterator] = MATParam.pLISMATMatrice[iIterator];
	}*/
}

/*************************************************************************************************************
* Resume :Destructeur
* Entrees:
* Preconditions: {}
* Sorties:
* Postconditions: {Destruction de l'objet CMatrice}
***************************************************************************************************************/

template <class MType> CMatrice<MType>::~CMatrice() {
	delete(pLISMATMatrice);
}

/*************************************************************************************************************
* Resume : Accesseur permettant de recuperer le nombre de colonnes de l'objet CMatrice
* Entrees:
* Preconditions: {}
* Sorties: int
* Postconditions: {L'entier renvoye est egale au nombre de colonnes de l'objet CMatrice}
***************************************************************************************************************/

template <class MType> int CMatrice<MType>::MATLireNbrColonnes() {
	return iMATNbrColonnes;
}

/*************************************************************************************************************
* Resume : Accesseur permettant de recuperer le nombre de lignes de l'objet CMatrice
* Entrees:
* Preconditions: {}
* Sorties: int
* Postconditions: {L'entier renvoye est egale au nombre de lignes de l'objet CMatrice}
***************************************************************************************************************/

template <class MType> int CMatrice<MType>::MATLireNbrLignes() {
	return iMATNbrLignes;
}

/*************************************************************************************************************
* Resume : Accesseur permettant de recuperer le pointeur sur le tableau
* Entrees:
* Preconditions: {}
* Sorties: MType* CMatrice
* Postconditions: {Le pointeur retourne pointe sur le tableau de l'objet CMatrice}
***************************************************************************************************************/

template <class MType> CListe<MType>* CMatrice<MType>::MATLireMatrice() {
	return pLISMATMatrice;
}

/*************************************************************************************************************
* Resume : Fonction permettant de modifier  le nombre de colonnes d'un objet CMatrice
* Entrees: int iColonnes
* Preconditions: {iColonnes >= 0}
* Sorties:
* Postconditions: {iMATNbrColonnes == iColonnes}
***************************************************************************************************************/

template <class MType> void CMatrice<MType>::MATModifierNbrColonnes(int iColonnes) {

	if (iColonnes < 0) {
		//CException CException(1);
		//throw CException;
	}

	if (iColonnes != iMATNbrColonnes) {
		MType* MatriceTemp = new MType[iColonnes * iMATNbrLignes];

		if (iColonnes < iMATNbrColonnes) {
			for (int iLigneIterator = 0; iLigneIterator < iMATNbrLignes; iLigneIterator++) {
				for (int iColonneIterator = 0; iColonneIterator < iColonnes; iColonneIterator++) {
//					MatriceTemp[iLigneIterator * iColonnes + iColonneIterator] = pLISMATMatrice[iLigneIterator * iMATNbrColonnes + iColonneIterator];
				}
			}
		}

		if (iColonnes > iMATNbrColonnes) {
			for (int iLigneIterator = 0; iLigneIterator < iMATNbrLignes; iLigneIterator++) {
				for (int iColonneIterator = 0; iColonneIterator < iMATNbrColonnes; iColonneIterator++) {
//					MatriceTemp[iLigneIterator * iColonnes + iColonneIterator] = pLISMATMatrice[iLigneIterator * iMATNbrColonnes + iColonneIterator];
				}
			}
		}

		delete(pLISMATMatrice);
//		pLISMATMatrice = MatriceTemp;
		iMATNbrColonnes = iColonnes;
	}

}

/*************************************************************************************************************
* Resume : Fonction permettant de modifier  le nombre de lignes d'un objet CMatrice
* Entrees: int iLignes
* Preconditions: {iLignes >= 0}
* Sorties:
* Postconditions: {iMATNbrLignes == iLignes}
***************************************************************************************************************/

template <class MType> void CMatrice<MType>::MATModifierNbrLignes(int iLignes) {

	if (iLignes < 0) {
//		CException CException(1);
		//throw CException;
	}

	if (iLignes != iMATNbrLignes) {
		MType* MatriceTemp = new MType[iMATNbrColonnes * iLignes];

		if (iLignes < iMATNbrLignes) {
			for (int iLigneIterator = 0; iLigneIterator < iLignes; iLigneIterator++) {
				for (int iColonneIterator = 0; iColonneIterator < iMATNbrColonnes; iColonneIterator++) {
//					MatriceTemp[iLigneIterator * iMATNbrColonnes + iColonneIterator] = pLISMATMatrice[iLigneIterator * iMATNbrColonnes + iColonneIterator];
				}
			}
		}

		if (iLignes > iMATNbrLignes) {
			for (int iLigneIterator = 0; iLigneIterator < iMATNbrLignes; iLigneIterator++) {
				for (int iColonneIterator = 0; iColonneIterator < iMATNbrColonnes; iColonneIterator++) {
//					MatriceTemp[iLigneIterator * iMATNbrColonnes + iColonneIterator] = pLISMATMatrice[iLigneIterator * iMATNbrColonnes + iColonneIterator];
				}
			}
		}

		delete(pLISMATMatrice);
//		pLISMATMatrice = MatriceTemp;
		iMATNbrLignes = iLignes;
	}
}

/*************************************************************************************************************
* Resume : Fonction permettant de modifier tout les attributs de l'objet CMatrice
* Entrees : int iParamLignes, int iParamColonnes, MType* MTParamMatrice
* Preconditions : {(iParamLignes && iParamColonnes) >=0}
* Sorties :
* Postconditions : {Nombre de lignes de l'objet CMatrice =iParamLignes ,son nombre de colonnes = iParamColonnes et son tableau est MTParamMatrice}
***************************************************************************************************************/

template <class MType> void CMatrice<MType>::MATModifierMatrice(int iParamLignes, int iParamColonnes, CListe<MType>* LISParamMatrice) {
	delete(pLISMATMatrice);

	MATModifierNbrColonnes(iParamColonnes);
	MATModifierNbrLignes(iParamLignes);
	pLISMATMatrice = LISParamMatrice;

}

/*************************************************************************************************************
* Resume : Affiche la matrice representant l'objet CMatrice sur le terminal
* Entrees:
* Preconditions: {}
* Sorties:
* Postconditions: {Affiche la matrice issus de l'objet CMatrice}
***************************************************************************************************************/

template <class MType> void CMatrice<MType>::MATAfficherMatrice() {
	for (int iLigneIterator = 0; iLigneIterator < iMATNbrLignes; iLigneIterator++) {
		for (int iColonneIterator = 0; iColonneIterator < iMATNbrColonnes; iColonneIterator++)
		{
			std::cout << pLISMATMatrice[iLigneIterator * iMATNbrColonnes + iColonneIterator] << "  ";
		}
		std::cout << std::endl;
	}

}

/*************************************************************************************************************
* Resume : Fonction modifiant l'element du tableau à partir de coordonnees(lignes, colonnes)
* Entrees: int iParamLignes, int iParamColonnes, MType MTParamElement
* Preconditions: { (iParamLignes && iParamColonne) <=0}
* Sorties:
* Postconditions: {Element aux coordonnees iParamLignes et iParamColonnes est egale a MTParamElement}
***************************************************************************************************************/

template <class MType> void CMatrice<MType>::MATModifierElement2D(int iParamLignes, int iParamColonnes, MType MTParamElement) {
	pLISMATMatrice[iParamLignes * iMATNbrColonnes + iParamColonnes] = MTParamElement;
}

/*************************************************************************************************************
* Resume : Fonction modifiant l'element du tableau en focntion de son indice
* Entrees: int iIndice, MType MTParamElement
* Preconditions: {iIndice >=0}
* Sorties:
* Postconditions: {pLISMATMatrice[iIndice] = MTParamElement}
***************************************************************************************************************/

template <class MType> void CMatrice<MType>::MATModifierElement1D(int iIndice, MType MTParamElement) {
	pLISMATMatrice[iIndice] = MTParamElement;
}

/*************************************************************************************************************
* Resume : Accesseur pour l'attribut tableau en fonction d'un indice
* Entrees: int iParamIndice
* Preconditions: {iParamIndice >=0}
* Sorties:MType CMatrice
* Postconditions: {Renvoie l'element du tableau a l'indice iParamIndice}
***************************************************************************************************************/

template <class MType> MType CMatrice<MType>::MATLireTableau(int iParamIndice) {
	return pLISMATMatrice[iParamIndice];
}

/*************************************************************************************************************
* Resume : Fonction renvoyant un objet CMatrice etant la transpose
* Entrees:
* Preconditions: {}
* Sorties: CMatric<MType>
* Postconditions: {L'objet CMatrice renvoye est la transpose de l'objet CMatrice }
***************************************************************************************************************/


template <class MType>  CMatrice<MType> CMatrice<MType>::MATTransposer() {
	CMatrice<MType> newMatrice(iMATNbrColonnes, iMATNbrLignes);

	int iBoucle = 0;
	for (int iLigneIterator = 0; iLigneIterator < iMATNbrLignes; iLigneIterator++) {
		for (int iColonneIterator = 0; iColonneIterator < iMATNbrColonnes; iColonneIterator++) {

			newMatrice.MATModifierElement2D(iColonneIterator, iLigneIterator, pLISMATMatrice[iBoucle]);
			iBoucle++;
		}
	}

	return newMatrice;
}

/*************************************************************************************************************
* Resume : Surchage de l'operateur +
* Entrees: CMatrice<MType> MATParamMatrice
* Preconditions: {les deux matrices sont de meme taille}
* Sorties: CMatrice<MType>
* Postconditions: {l'operation CMatrice + CMatrice est possible}
***************************************************************************************************************/

template<class MType> CMatrice<MType> CMatrice<MType>::operator+(CMatrice<MType> MATParamMatrice)const {
	int iNbrLignes2 = MATParamMatrice.MATLireNbrLignes();
	int iNbrColonnes2 = MATParamMatrice.MATLireNbrColonnes();

	if ((iMATNbrLignes == iNbrColonnes2) && (iNbrLignes2 == iMATNbrColonnes))
	{

		int iTailleMat = iMATNbrLignes * iMATNbrColonnes;

		CMatrice<MType> newMatrice(iMATNbrColonnes, iMATNbrLignes);
		for (int iBoucle = 0; iBoucle < iTailleMat; iBoucle++)
		{
			newMatrice.MATModifierElement1D(iBoucle, pLISMATMatrice[iBoucle] + MATParamMatrice[iBoucle]);

		}
		return newMatrice;
	}
	else {
		CException Exception(1);
		throw Exception;
	}
}

/*************************************************************************************************************
* Resume : Surchager de l'operateur -
* Entrees:CMatrice<MType> MATParamMatrice
* Preconditions: {Les deux matrices sont de meme taille}
* Sorties: CMatrice<MType>
* Postconditions: {L'operation CMatrice - Cmatrice est possible}
***************************************************************************************************************/

template<class MType> CMatrice<MType> CMatrice<MType>::operator-(CMatrice<MType> MATParamMatrice)const {
	int iNbrLignes2 = MATParamMatrice.MATLireNbrLignes();
	int iNbrColonnes2 = MATParamMatrice.MATLireNbrColonnes();

	if ((iMATNbrLignes == iNbrColonnes2) && (iNbrLignes2 == iMATNbrColonnes))
	{

		int iTailleMat1 = iMATNbrLignes * iMATNbrColonnes;

		CMatrice<MType> newMatrice(iMATNbrColonnes, iMATNbrLignes);
		for (int iBoucle = 0; iBoucle < iTailleMat1; iBoucle++)
		{
			newMatrice.MATModifierElement1D(iBoucle, pLISMATMatrice[iBoucle] - MATParamMatrice[iBoucle]);

		}
		return newMatrice;
	}
	else {
		CException Exception(1);
		throw Exception;
	}
}

/*************************************************************************************************************
* Resume : Surcharge de l'operateur *
* Entrees: CMatrice<MType> MATParamMatrice
* Preconditions: {nombre de lignes de la Cmatrice de gauche = nombre de colonnes de la CMatrice de droite}
* Sorties: CMatrice<MType>
* Postconditions: {L'operation CMatrice * CMatrice est possible}
***************************************************************************************************************/

template<class MType> CMatrice<MType> CMatrice<MType>::operator*(CMatrice<MType> MATParamMatrice)const {
	int iNbrLignes2 = MATParamMatrice.MATLireNbrLignes();
	int iNbrColonnes2 = MATParamMatrice.MATLireNbrColonnes();


	if ((iMATNbrLignes == iNbrColonnes2) && (iNbrLignes2 == iMATNbrColonnes))
	{
		CMatrice<MType> newMatrice(iMATNbrLignes, iNbrColonnes2);
		MType mtpValeur;

		for (int iLigneIterator = 0; iLigneIterator < iMATNbrLignes; iLigneIterator++) {
			for (int iColonneIterator = 0; iColonneIterator < iNbrColonnes2; iColonneIterator++) {
				mtpValeur = 0;
				for (int iSommeProduit = 0; iSommeProduit < iMATNbrLignes; iSommeProduit++) {
					mtpValeur = mtpValeur + pLISMATMatrice[iLigneIterator * iMATNbrColonnes + iSommeProduit] * MATParamMatrice[iSommeProduit * iNbrColonnes2 + iColonneIterator];
				}
				newMatrice.MATModifierElement2D(iLigneIterator, iColonneIterator, mtpValeur);

			}
		}
		return newMatrice;
	}
	else {
		CException Exception(1);
		throw Exception;
	}
}

/*************************************************************************************************************
* Resume : Surcharge de l'operateur *
* Entrees:MType mtpParam
* Preconditions: {}
* Sorties:CMatrice<MType>
* Postconditions: {L'operation Mtype CMatrice *mtpParam }
***************************************************************************************************************/

template<class MType> CMatrice<MType> CMatrice<MType>::operator*(MType mtpParam)const {

	int iTailleMat = iMATNbrLignes * iMATNbrColonnes;
	CMatrice<MType> newMatrice(iMATNbrColonnes, iMATNbrLignes);
	for (int iIterateur = 0; iIterateur < iTailleMat; iIterateur++) {
		newMatrice.MATModifierElement1D(iIterateur, pLISMATMatrice[iIterateur] * mtpParam);
	}
	return newMatrice;
}

/*************************************************************************************************************
* Resume : Surcharge de l'operateur /
* Entrees: CMatrice<MType> MATParamMatrice
* Preconditions: {nombre de lignes de la Cmatrice de gauche = nombre de colonnes de la CMatrice de droite et on ne doit pas diviser par 0 }
* Sorties: CMatrice<MType>
* Postconditions: {L'operation CMatrice / CMatrice est possible}
***************************************************************************************************************/

template<class MType> CMatrice<MType> CMatrice<MType>::operator/(CMatrice<MType> MATParamMatrice)const {
	int iNbrLignes2 = MATParamMatrice.MATLireNbrLignes();
	int iNbrColonnes2 = MATParamMatrice.MATLireNbrColonnes();
	int iTaille1 = iMATNbrColonnes * iMATNbrLignes;


	if ((iMATNbrLignes == iNbrColonnes2) && (iNbrLignes2 == iMATNbrColonnes))
	{
		CMatrice<MType> newMatrice(iMATNbrLignes, iNbrColonnes2);
		MType mtpValeur;

		for (int iLigneIterator = 0; iLigneIterator < iMATNbrLignes; iLigneIterator++) {
			for (int iColonneIterator = 0; iColonneIterator < iNbrColonnes2; iColonneIterator++) {
				mtpValeur = 0;
				for (int iSommeProduit = 0; iSommeProduit < iMATNbrLignes; iSommeProduit++) {
					if (MATParamMatrice[iSommeProduit * iNbrColonnes2 + iColonneIterator] != 0) {

						mtpValeur = mtpValeur + (pLISMATMatrice[iLigneIterator * iMATNbrColonnes + iSommeProduit] * (1 / MATParamMatrice[iSommeProduit * iNbrColonnes2 + iColonneIterator]));
					}
					else {
						CException CException(1);
						throw CException;
					}
				}
				newMatrice.MATModifierElement2D(iLigneIterator, iColonneIterator, mtpValeur);
			}
		}
		return newMatrice;
	}
	else {
		CException Exception(1);
		throw Exception;
	}
}

/*************************************************************************************************************
* Resume : Surcharge de l'operateur /
* Entrees: CMatrice<MType> MATParamMatrice
* Preconditions: {nombre de lignes de la Cmatrice de gauche = nombre de colonnes de la CMatrice de droite mtpParam != 0}
* Sorties: CMatrice<MType>
* Postconditions: {L'operation CMatrice / MType mtpParam est possible}
***************************************************************************************************************/

template<class MType> CMatrice<MType> CMatrice<MType>::operator/(MType mtpParam)const {
	CException Exception(1);
	if (mtpParam == 0)
	{
		throw Exception;
	}
	else
	{
		return operator*(1 / mtpParam);

	}
}

/*************************************************************************************************************
* Resume : Surcharge del'operateur []
* Entrees:const int Indice
* Preconditions: {iIndice >=0}
* Sorties:MType & CMatrice
* Postconditions: {Cmatrice[iIndice] renvoie l'elemetn du tableau a l'indice iIndice}
***************************************************************************************************************/

template<class MType> MType& CMatrice<MType>::operator[](const int iIndice) {
	return pLISMATMatrice[iIndice];
}

/*************************************************************************************************************
* Resume : surcharge de l'operateur =
* Entrees: CMatrice<MType> MATParam
* Preconditions: {}
* Sorties:CMatrice<MType>
* Postconditions: {permet de recopier dans un autre objet CMatrice}
***************************************************************************************************************/

template<class MType> CMatrice<MType>& CMatrice<MType>::operator=(CMatrice<MType> MATParam) {
	iMATNbrColonnes = MATParam.iMATNbrColonnes;
	iMATNbrLignes = MATParam.iMATNbrLignes;

	pLISMATMatrice = new MType[iMATNbrColonnes * iMATNbrLignes];
	for (int iIterator = 0; iIterator < iMATNbrColonnes * iMATNbrLignes; iIterator++) {
		pLISMATMatrice[iIterator] = MATParam.pLISMATMatrice[iIterator];
	}
	return *this;
}

