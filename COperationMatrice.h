#pragma once

#include "CMatrice.h"
#include "CException.h"

template <class MType> class  COperationMatrice
{
public:
	//Declaration des methodes

	/* Cette methode calcule et renvoie la transpose de la matrice mis en parametre sans la modifie
	Entree : La matrice dont on veut obtenir la transpose
	Pre-condition : neant
	Sortie : une nouvelle matrice qui est la transpose de celle passe en parametre
	Post-condition : La matrice retourne est la transpose de celle passe en parametre
	*/
	static CMatrice<MType> OPMTransposer(CMatrice<MType> MATParamMatrice);


	/* Cette methode affiche dans la console les valeurs contenues dans la matrice avec la meme representation qu'en mathematique.
	Entree : neant
	Pre-condition : neant
	Sortie : neant
	Post-condition : l'objet en corus est afficher dans la console a la maniere d'une matrice en mathematique
	*/
	void OPMAfficherMatrice(CMatrice<MType> MATParamMatrice);
};

	//Definition des methodes

/* Cette methode calcule et renvoie la transpose de la matrice mis en parametre sans la modifie
	Entree : La matrice dont on veut obtenir la transpose
	Pre-condition : neant
	Sortie : une nouvelle matrice qui est la transpose de celle passe en parametre
	Post-condition : La matrice retourne est la transpose de celle passe en parametre
	*/
template <class MType>  CMatrice<MType> COperationMatrice<MType>::OPMTransposer(CMatrice<MType> MATParamMatrice)
{
	CMatrice<MType> ppMTTransposer(MATParamMatrice.MATLireNbColonnes(), MATParamMatrice.MATLireNbLignes()); //Creation d'une matrice des tailles de ligne = this.colonnes et colonne = this.lignes

	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < MATParamMatrice.MATLireNbLignes(); uiBoucleLignes++)
	{
		for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < MATParamMatrice.MATLireNbColonnes(); uiBoucleColonnes++)
		{
			ppMTTransposer.MATModifierElement(uiBoucleColonnes,uiBoucleLignes,MATParamMatrice.MATLireElement(uiBoucleLignes,uiBoucleColonnes));
		}
	}
	return ppMTTransposer;
}


/* Cette methode affiche dans la console les valeurs contenues dans la matrice avec la meme representation qu'en mathematique.
	Entree : neant
	Pre-condition : neant
	Sortie : neant
	Post-condition : l'objet en corus est afficher dans la console a la maniere d'une matrice en mathematique
	*/
template <class MType> void COperationMatrice<MType>::OPMAfficherMatrice(CMatrice<MType> MATParamMatrice)
{
	for (unsigned int uiLigneIterator = 0; uiLigneIterator < MATParamMatrice.MATLireNbLignes(); uiLigneIterator++)
	{
		for (unsigned int uiColonneIterator = 0; uiColonneIterator < MATParamMatrice.MATLireNbColonnes(); uiColonneIterator++)
		{
			cout << MATParamMatrice.MATLireElement(uiLigneIterator,uiColonneIterator) << "  ";
		}
		cout << endl;
	}
	cout << endl;
}