#pragma once

#include "CMatrice.h"
#include "CException.h"

template <class MType> class  COperationMatrice
{
	//Declaration des methodes

public:
	static CMatrice<MType> OPETransposer(CMatrice<MType> MATParamMatrice);

	//Definition des methodes 

	//Transposer d'une matrice
};
template <class MType>  CMatrice<MType> COperationMatrice<MType>::OPETransposer(CMatrice<MType> MATParamMatrice) {
	CMatrice<MType> ppMTTransposer(MATParamMatrice.MATLireNbColonnesV2(), MATParamMatrice.MATLireNbLignesV2()); //Creation d'une matrice des tailles de ligne = this.colonnes et colonne = this.lignes

	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < MATParamMatrice.MATLireNbLignesV2(); uiBoucleLignes++)
	{
		for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < MATParamMatrice.MATLireNbColonnesV2(); uiBoucleColonnes++)
		{
			ppMTTransposer.MATModifierElementV2(uiBoucleColonnes,uiBoucleLignes,MATParamMatrice.MATLireElementV2(uiBoucleLignes,uiBoucleColonnes));
		}
	}

	return ppMTTransposer;
}
