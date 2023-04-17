#pragma once

#include "CMatrice.h"
#include "CException.h"

template <class MType> class  COperationMatrice
{
	//Declaration des methodes

public:
	static CMatrice<MType> OPETransposer(CMatrice<MType> MATParamMatrice);
	//Multiplication

	static CMatrice<MType> OPEMultiplication(CMatrice<MType> MATParamMatrice1, CMatrice<MType> MATParamMatrice2);
	static CMatrice<MType> OPEMultiplication(CMatrice<MType> MATParamMatrice, double OTPParam);
	static CMatrice<MType> OPEMultiplication(double OTPParam, CMatrice<MType> MATParamMatrice);


	//Addition

	static CMatrice<MType> OPEAddition(CMatrice<MType> MATParamMatrice1, CMatrice<MType> MATParamMatrice2);

	//Soustraction

	static CMatrice<MType> OPESoustraction(CMatrice<MType> MATParamMatrice1, CMatrice<MType> MATParamMatrice2);

	//Division

	static CMatrice<MType> OPEDivision(CMatrice<MType> MATParamMatrice1, CMatrice<MType> MATParamMatrice2);
	static CMatrice<MType> OPEDivision(CMatrice<MType> MATParamMatrice, double OTPParam);
	static CMatrice<MType> OPEDivision(double OTPParam, CMatrice<MType> MATParamMatrice);
};
//Definition des methodes 

//Transposer d'une matrice

template <class MType>  CMatrice<MType> COperationMatrice<MType>::OPETransposer(CMatrice<MType> MATParamMatrice) {
	int iNbrLignes = MATParamMatrice.MATLireNbrLignes();
	int iNbrColonnes = MATParamMatrice.MATLireNbrColonnes();
	int iTailleMat = iNbrLignes * iNbrColonnes;

	CMatrice<MType>* newMatrice = new CMatrice<MType>(iNbrLignes, iNbrColonnes);

	for (int iBoucle = 0; iBoucle < iTailleMat; iBoucle++)
	{
		newMatrice[iBoucle] = MATParamMatrice[iTailleMat - iBoucle - 1];
	}
	return newMatrice;
}



//Multiplication de 2 matrices
// Il faut que le nombre de colonnes de la matrice de droite soit egale au nombre de lignes de celle de gauche et inversement nombre de ligne a droite egale nombre de colonne à gauche

template <class MType>  CMatrice<MType> COperationMatrice<MType>::OPEMultiplication(CMatrice<MType> MATParamMatrice1, CMatrice<MType> MATParamMatrice2) {
	int iNbrLignes1 = MATParamMatrice1.MATLireNbrLignes();
	int iNbrColonnes1 = MATParamMatrice1.MATLireNbrColonnes();
	int iNbrLignes2 = MATParamMatrice2.MATLireNbrLignes();
	int iNbrColonnes2 = MATParamMatrice2.MATLireNbrColonnes();
	int iTaille1 = iNbrColonnes1 * iNbrLignes1;
	if ((iNbrLignes1 == iNbrColonnes2) && (iNbrLignes2 == iNbrColonnes1))
	{
		CMatrice<MType>* newMatrice = new CMatrice<MType>(iNbrLignes1, iNbrColonnes2);
		for (int iBoucle = 0; iBoucle < iTaille1; iBoucle++)
		{
			newMatrice[iBoucle];
		}

		return newMatrice;
	}

}

//Multiplication d'une matrice par un coefficient

template <class MType>  CMatrice<MType> COperationMatrice<MType>::OPEMultiplication(CMatrice<MType> MATParamMatrice, double OTPParam)
{
	int iNbrLignes = MATParamMatrice.MATLireNbrLignes();
	int iNbrColonnes = MATParamMatrice.MATLireNbrColonnes();
	int iTailleMat = iNbrLignes * iNbrColonnes;
	CMatrice<MType>* newMatrice = new CMatrice<MType>(iNbrLignes, iNbrColonnes);
	for (int iBoucle = 0; iBoucle < iTailleMat; iBoucle++)
	{
		newMatrice[iBoucle] = MATParamMatrice[iBoucle] * OTPParam;
	}
	return newMatrice;
}

//Multiplication d'un coefficient par une matrice

template <class MType>  CMatrice<MType> COperationMatrice<MType>::OPEMultiplication(double OTPParam, CMatrice<MType> MATParamMatrice) {

	return OPEMultiplication(MATParamMatrice, OTPParam);
}

//Addition de 2 matrices
//Faire attention à la taille des matrices elle doivent etre egale (meme nombre de lignes et de colonnes) pour pouvoir faire l'addition

template <class MType>  CMatrice<MType> COperationMatrice<MType>::OPEAddition(CMatrice<MType> MATParamMatrice1, CMatrice<MType> MATParamMatrice2) {
	int iNbrLignes1 = MATParamMatrice1.MATLireNbrLignes();
	int iNbrColonnes1 = MATParamMatrice1.MATLireNbrColonnes();
	int iNbrLignes2 = MATParamMatrice2.MATLireNbrLignes();
	int iNbrColonnes2 = MATParamMatrice2.MATLireNbrColonnes();

	if ((iNbrLignes1 == iNbrColonnes2) && (iNbrLignes2 == iNbrColonnes1))
	{

		int iTailleMat1 = iNbrLignes1 * iNbrColonnes1;

		CMatrice<MType>* newMatrice = new CMatrice<MType>(iNbrLignes1, iNbrColonnes1);
		for (int iBoucle = 0; iBoucle < iTailleMat1; iBoucle++)
		{
			newMatrice[iBoucle] = MATParamMatrice1[iBoucle] + MATParamMatrice2[iBoucle];
			return newMatrice;
		}
	}

}

//Soustraction de 2 matrices
//Faire attention à la taille des matrices elle doivent etre egale (meme nombre de lignes et de colonnes) pour pouvoir faire l'addition

template <class MType>  CMatrice<MType> COperationMatrice<MType>::OPESoustraction(CMatrice<MType> MATParamMatrice1, CMatrice<MType> MATParamMatrice2) {
	int iNbrLignes1 = MATParamMatrice1.MATLireNbrLignes();
	int iNbrColonnes1 = MATParamMatrice1.MATLireNbrColonnes();
	int iNbrLignes2 = MATParamMatrice2.MATLireNbrLignes();
	int iNbrColonnes2 = MATParamMatrice2.MATLireNbrColonnes();

	if ((iNbrLignes1 == iNbrLignes2) && (iNbrColonnes2 == iNbrColonnes1))
	{
		CException CException(1);
		throw CException;
	}

	int iTailleMat1 = iNbrLignes1 * iNbrColonnes1;

	CMatrice<MType>* newMatrice = new CMatrice<MType>(iNbrLignes1, iNbrColonnes1);
	for (int iBoucle = 0; iBoucle < iTailleMat1; iBoucle++)
	{
		newMatrice[iBoucle] = MATParamMatrice1[iBoucle] - MATParamMatrice2[iBoucle];

	}
	return newMatrice;


}
//Division d'une matrice par un coefficient

template <class MType>  CMatrice<MType> COperationMatrice<MType>::OPEDivision(CMatrice<MType> MATParamMatrice, double OTPParam) {

	if (OTPParam == 0)
	{
		throw OTPParam;
	}
	else
	{
		int iNbrLignes = MATParamMatrice.MATLireNbrLignes();
		int iNbrColonnes = MATParamMatrice.MATLireNbrColonnes();
		int iTailleMat = iNbrLignes * iNbrColonnes;
		CMatrice<MType>* newMatrice = new CMatrice<MType>(iNbrLignes, iNbrColonnes);
		for (int iBoucle = 0; iBoucle < iTailleMat; iBoucle++)
		{
			newMatrice[iBoucle] = MATParamMatrice[iBoucle] / OTPParam;
		}
		return newMatrice;
	}
}

//Division d'un coefficient par une matrice

template <class MType>  CMatrice<MType> COperationMatrice<MType>::OPEDivision(double OTPParam, CMatrice<MType> MATParamMatrice) {

	return OPEDivision(MATParamMatrice, OTPParam);
}

//Division de 2 matrices

template <class MType>  CMatrice<MType> COperationMatrice<MType>::OPEDivision(CMatrice<MType> MATParamMatrice1, CMatrice<MType> MATParamMatrice2) {
	CMatrice<MType>* newMatrice = new CMatrice<MType>(MATParamMatrice1.MATLireNbrLignes(), MATParamMatrice2.MATLireNbrColonnes());
	return newMatrice;
}
