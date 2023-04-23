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
	unsigned int uiMATNbColonnes;
	unsigned int uiMATNbLignes;
	CListe<CListe<MType>>* pLISMATMatrice;
public:
	//Déclaration des constructeurs
	CMatrice<MType>(); // constructeur par défaut
	CMatrice<MType>(unsigned int uiParamLignes, unsigned int iParamColonnes); // constructeur de confort
	CMatrice<MType>(const CMatrice<MType>& MATParam); //constructeur de recopie

	//Déclaration du destrcuteur
	~CMatrice<MType>();



	//Getters

	unsigned int MATLireNbColonnes();
	unsigned int MATLireNbLignes();
	CListe<CListe<MType>>* MATLireMatrice();

	//Setters

	void MATModifierNbColonnes(unsigned int iColonnes);
	void MATModifierNbLignes(unsigned int iLignes);
	void MATModifierMatrice(unsigned int uiParamLignes, unsigned int uiParamColonnes, CListe<CListe<MType>>* LISParamMatrice);

	//Déclarations des méthodes

	void MATAfficherMatrice();
	void MATModifierElement2D(unsigned int uiParamLignes, unsigned int iParamColonnes, MType MTParamElement);
	void MATModifierElement1D(unsigned int iIndice, MType MTParamElement);
	MType MATLireTableau(unsigned int uiParamIndice);
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

	MType& operator[](const unsigned int iIndice);
	CMatrice<MType>& operator=(CMatrice<MType> MATParam);
	
};

CMatrice<double> operator*(double mtpParam, CMatrice<double> MTParamMatrice);
CMatrice<double> operator/(double mtpParam, CMatrice<double> MTParamMatrice);

/*************************************************************************************************************
* Resume : Constructeur de confort
* Entrees : int uiParamLignes, int iParamColonnes
* Preconditions : {(uiParamLignes && iParamColonnes )>= 0}
* Sorties :
* Postconditions : {Creation d'un objet CMatrice avec le nombre souhaité de colonnes et de lignes}
***************************************************************************************************************/

template <class MType> CMatrice<MType>::CMatrice(unsigned int uiParamLignes, unsigned int uiParamColonnes) {
	uiMATNbColonnes = uiParamColonnes;
	uiMATNbLignes = uiParamLignes;
	pLISMATMatrice = new CListe<CListe<MType>>(uiParamColonnes);
	for (unsigned int uiBoucle = 0; uiBoucle < uiMATNbColonnes; uiBoucle++)
	{
		 
		 pLISMATMatrice->LISAjouterElement = new CListe<MType>(uiParamLignes);
		 
	}
}

/*************************************************************************************************************
* Resume : Constructeur par default
* Entrees:
* Preconditions: {}
* Sorties:
* Postconditions: {Creation d'un objet CMatrice}
***************************************************************************************************************/

template <class MType> CMatrice<MType>::CMatrice() {
	uiMATNbColonnes = 0;
	uiMATNbLignes = 0;
	pLISMATMatrice = new CListe<CListe<MType>>();

}

/*************************************************************************************************************
* Resume : Constructeur de recoîe
* Entrees: const CMatrice<MType> &MATParam
* Preconditions: {}
* Sorties:
* Postconditions: {Recopie de la CMatrice MATParam}
***************************************************************************************************************/
template <class MType> CMatrice<MType>::CMatrice(const CMatrice<MType>& MATParam) {
/*	uiMATNbColonnes = MATParam.uiMATNbColonnes;
	uiMATNbLignes = MATParam.uiMATNbLignes;

	pLISMATMatrice = new MType[uiMATNbColonnes * uiMATNbLignes];
	for (int iIterator = 0; iIterator < uiMATNbColonnes * uiMATNbLignes; iIterator++) {
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

template <class MType> unsigned int CMatrice<MType>::MATLireNbColonnes() {
	return uiMATNbColonnes;
}

/*************************************************************************************************************
* Resume : Accesseur permettant de recuperer le nombre de lignes de l'objet CMatrice
* Entrees:
* Preconditions: {}
* Sorties: int
* Postconditions: {L'entier renvoye est egale au nombre de lignes de l'objet CMatrice}
***************************************************************************************************************/

template <class MType> unsigned int CMatrice<MType>::MATLireNbLignes() {
	return uiMATNbLignes;
}

/*************************************************************************************************************
* Resume : Accesseur permettant de recuperer le pointeur sur le tableau
* Entrees:
* Preconditions: {}
* Sorties: MType* CMatrice
* Postconditions: {Le pointeur retourne pointe sur le tableau de l'objet CMatrice}
***************************************************************************************************************/

template <class MType> CListe<CListe<MType>>* CMatrice<MType>::MATLireMatrice() {
	return pLISMATMatrice;
}

/*************************************************************************************************************
* Resume : Fonction permettant de modifier  le nombre de colonnes d'un objet CMatrice
* Entrees: int iColonnes
* Preconditions: {iColonnes >= 0}
* Sorties:
* Postconditions: {uiMATNbColonnes == iColonnes}
***************************************************************************************************************/

template <class MType> void CMatrice<MType>::MATModifierNbColonnes(unsigned int uiColonnes) {

	

	if (uiColonnes != uiMATNbColonnes) {
		MType* MatriceTemp = new MType[uiColonnes * uiMATNbLignes];

		if (uiColonnes < uiMATNbColonnes) {
			for (unsigned int uiLigneIterator = 0; uiLigneIterator < uiMATNbLignes; uiLigneIterator++) {
				for (unsigned int uiColonneIterator = 0; uiColonneIterator < uiColonnes; uiColonneIterator++) {
//					MatriceTemp[uiLigneIterator * uiColonnes + uiColonneIterator] = pLISMATMatrice[uiLigneIterator * uiMATNbColonnes + uiColonneIterator];
				}
			}
		}

		if (uiColonnes > uiMATNbColonnes) {
			for (unsigned int uiLigneIterator = 0; uiLigneIterator < uiMATNbLignes; uiLigneIterator++) {
				for (unsigned int uiColonneIterator = 0; uiColonneIterator < uiMATNbColonnes; uiColonneIterator++) {
//					MatriceTemp[uiLigneIterator * uiColonnes + uiColonneIterator] = pLISMATMatrice[uiLigneIterator * uiMATNbColonnes + uiColonneIterator];
				}
			}
		}

		delete(pLISMATMatrice);
//		pLISMATMatrice = MatriceTemp;
		uiMATNbColonnes = uiColonnes;
	}

}

/*************************************************************************************************************
* Resume : Fonction permettant de modifier  le nombre de lignes d'un objet CMatrice
* Entrees: int iLignes
* Preconditions: {iLignes >= 0}
* Sorties:
* Postconditions: {uiMATNbLignes == iLignes}
***************************************************************************************************************/

template <class MType> void CMatrice<MType>::MATModifierNbLignes(unsigned int uiLignes) {


	if (uiLignes != uiMATNbLignes) {
		MType* MatriceTemp = new MType[uiMATNbColonnes * uiLignes];

		if (uiLignes < uiMATNbLignes) {
			for (unsigned int uiLigneIterator = 0; uiLigneIterator < uiLignes; uiLigneIterator++) {
				for (unsigned int uiColonneIterator = 0; uiColonneIterator < uiMATNbColonnes; uiColonneIterator++) {
//					MatriceTemp[uiLigneIterator * uiMATNbColonnes + uiColonneIterator] = pLISMATMatrice[uiLigneIterator * uiMATNbColonnes + uiColonneIterator];
				}
			}
		}

		if (uiLignes > uiMATNbLignes) {
			for (unsigned int uiLigneIterator = 0; uiLigneIterator < uiMATNbLignes; uiLigneIterator++) {
				for (unsigned int uiColonneIterator = 0; uiColonneIterator < uiMATNbColonnes; uiColonneIterator++) {
//					MatriceTemp[uiLigneIterator * uiMATNbColonnes + uiColonneIterator] = pLISMATMatrice[uiLigneIterator * uiMATNbColonnes + uiColonneIterator];
				}
			}
		}

		delete(pLISMATMatrice);
//		pLISMATMatrice = MatriceTemp;
		uiMATNbLignes = uiLignes;
	}
}

/*************************************************************************************************************
* Resume : Fonction permettant de modifier tout les attributs de l'objet CMatrice
* Entrees : int uiParamLignes, int iParamColonnes, MType* MTParamMatrice
* Preconditions : {(uiParamLignes && iParamColonnes) >=0}
* Sorties :
* Postconditions : {Nombre de lignes de l'objet CMatrice =uiParamLignes ,son nombre de colonnes = iParamColonnes et son tableau est MTParamMatrice}
***************************************************************************************************************/

template <class MType> void CMatrice<MType>::MATModifierMatrice(unsigned int uiParamLignes, unsigned int uiParamColonnes, CListe<CListe<MType>>* LISParamMatrice) {

	delete(pLISMATMatrice);
	MATModifierNbColonnes(uiParamColonnes);
	MATModifierNbLignes(uiParamLignes);
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
	for (int iLigneIterator = 0; iLigneIterator < uiMATNbLignes; iLigneIterator++) {
		for (int iColonneIterator = 0; iColonneIterator < uiMATNbColonnes; iColonneIterator++)
		{
			std::cout << pLISMATMatrice[iLigneIterator * uiMATNbColonnes + iColonneIterator] << "  ";
		}
		std::cout << std::endl;
	}

}

/*************************************************************************************************************
* Resume : Fonction modifiant l'element du tableau à partir de coordonnees(lignes, colonnes)
* Entrees: int uiParamLignes, int iParamColonnes, MType MTParamElement
* Preconditions: { (uiParamLignes && iParamColonne) <=0}
* Sorties:
* Postconditions: {Element aux coordonnees uiParamLignes et iParamColonnes est egale a MTParamElement}
***************************************************************************************************************/



/*************************************************************************************************************
* Resume : Fonction modifiant l'element du tableau en focntion de son indice
* Entrees: int iIndice, MType MTParamElement
* Preconditions: {iIndice >=0}
* Sorties:
* Postconditions: {pLISMATMatrice[iIndice] = MTParamElement}
***************************************************************************************************************/

template <class MType> void CMatrice<MType>::MATModifierElement1D(unsigned int uiIndice, MType MTParamElement) {
	pLISMATMatrice[uiIndice] = MTParamElement;
}

/*************************************************************************************************************
* Resume : Accesseur pour l'attribut tableau en fonction d'un indice
* Entrees: int iParamIndice
* Preconditions: {iParamIndice >=0}
* Sorties:MType CMatrice
* Postconditions: {Renvoie l'element du tableau a l'indice iParamIndice}
***************************************************************************************************************/

template <class MType> MType CMatrice<MType>::MATLireTableau(unsigned int uiParamIndice) {
	return pLISMATMatrice[uiParamIndice];
}

/*************************************************************************************************************
* Resume : Fonction renvoyant un objet CMatrice etant la transpose
* Entrees:
* Preconditions: {}
* Sorties: CMatric<MType>
* Postconditions: {L'objet CMatrice renvoye est la transpose de l'objet CMatrice }
***************************************************************************************************************/


template <class MType>  CMatrice<MType> CMatrice<MType>::MATTransposer() {
	CMatrice<MType> newMatrice(uiMATNbColonnes, uiMATNbLignes);

	int iBoucle = 0;
	for (int iLigneIterator = 0; iLigneIterator < uiMATNbLignes; iLigneIterator++) {
		for (int iColonneIterator = 0; iColonneIterator < uiMATNbColonnes; iColonneIterator++) {

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
	unsigned int uiNbLignes2 = MATParamMatrice.MATLireNbLignes();
	unsigned int uiNbColonnes2 = MATParamMatrice.MATLireNbColonnes();

	if ((uiMATNbLignes == uiNbColonnes2) && (uiNbLignes2 == uiMATNbColonnes))
	{

		unsigned int uiTailleMat = uiMATNbLignes * uiMATNbColonnes;

		CMatrice<MType> newMatrice(uiMATNbColonnes, uiMATNbLignes);
		for ( int iBoucle = 0; iBoucle < uiTailleMat; iBoucle++)
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
	unsigned int uiNbLignes2 = MATParamMatrice.MATLireNbLignes();
	unsigned int uiNbColonnes2 = MATParamMatrice.MATLireNbColonnes();

	if ((uiMATNbLignes == uiNbColonnes2) && (uiNbLignes2 == uiMATNbColonnes))
	{

		unsigned int uiTailleMat1 = uiMATNbLignes * uiMATNbColonnes;

		CMatrice<MType> newMatrice(uiMATNbColonnes, uiMATNbLignes);
		for (int iBoucle = 0; iBoucle < uiTailleMat1; iBoucle++)
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
	unsigned int uiNbLignes2 = MATParamMatrice.MATLireNbLignes();
	unsigned int uiNbColonnes2 = MATParamMatrice.MATLireNbColonnes();


	if ((uiMATNbLignes == uiNbColonnes2) && (uiNbLignes2 == uiMATNbColonnes))
	{
		CMatrice<MType> newMatrice(uiMATNbLignes, uiNbColonnes2);
		MType mtpValeur;

		for (unsigned int uiLigneIterator = 0; uiLigneIterator < uiMATNbLignes; uiLigneIterator++) {
			for (unsigned int uiColonneIterator = 0; uiColonneIterator < uiNbColonnes2; uiColonneIterator++) {
				mtpValeur = 0;
				for (int iSommeProduit = 0; iSommeProduit < uiMATNbLignes; iSommeProduit++) {
					mtpValeur = mtpValeur + pLISMATMatrice[uiLigneIterator * uiMATNbColonnes + iSommeProduit] * MATParamMatrice[iSommeProduit * uiNbColonnes2 + uiColonneIterator];
				}
				newMatrice.MATModifierElement2D(uiLigneIterator, uiColonneIterator, mtpValeur);

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

	unsigned int uiTailleMat = uiMATNbLignes * uiMATNbColonnes;
	CMatrice<MType> newMatrice(uiMATNbColonnes, uiMATNbLignes);
	for (unsigned int uiIterateur = 0; uiIterateur < uiTailleMat; uiIterateur++) {
		newMatrice.MATModifierElement1D(uiIterateur, pLISMATMatrice[uiIterateur] * mtpParam);
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
	unsigned int uiNbLignes2 = MATParamMatrice.MATLireNbLignes();
	unsigned int uiNbColonnes2 = MATParamMatrice.MATLireNbColonnes();
	unsigned int uiTaille1 = uiMATNbColonnes * uiMATNbLignes;


	if ((uiMATNbLignes == uiNbColonnes2) && (uiNbLignes2 == uiMATNbColonnes))
	{
		CMatrice<MType> newMatrice(uiMATNbLignes, uiNbColonnes2);
		MType mtpValeur;

		for (int iLigneIterator = 0; iLigneIterator < uiMATNbLignes; iLigneIterator++) {
			for (int iColonneIterator = 0; iColonneIterator < uiNbColonnes2; iColonneIterator++) {
				mtpValeur = 0;
				for (int iSommeProduit = 0; iSommeProduit < uiMATNbLignes; iSommeProduit++) {
					if (MATParamMatrice[iSommeProduit * uiNbColonnes2 + iColonneIterator] != 0) {

						mtpValeur = mtpValeur + (pLISMATMatrice[iLigneIterator * uiMATNbColonnes + iSommeProduit] * (1 / MATParamMatrice[iSommeProduit * uiNbColonnes2 + iColonneIterator]));
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

template<class MType> MType& CMatrice<MType>::operator[](const unsigned int uiIndice) {
	return pLISMATMatrice[uiIndice];
}

/*************************************************************************************************************
* Resume : surcharge de l'operateur =
* Entrees: CMatrice<MType> MATParam
* Preconditions: {}
* Sorties:CMatrice<MType>
* Postconditions: {permet de recopier dans un autre objet CMatrice}
***************************************************************************************************************/

template<class MType> CMatrice<MType>& CMatrice<MType>::operator=(CMatrice<MType> MATParam) {
	uiMATNbColonnes = MATParam.uiMATNbColonnes;
	uiMATNbLignes = MATParam.uiMATNbLignes;

	pLISMATMatrice = new MType[uiMATNbColonnes * uiMATNbLignes];
	for (int iIterator = 0; iIterator < uiMATNbColonnes * uiMATNbLignes; iIterator++) {
		pLISMATMatrice[iIterator] = MATParam.pLISMATMatrice[iIterator];
	}
	return *this;
}

