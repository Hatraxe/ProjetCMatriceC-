#include "CException.h"
#include <fstream>

/**************************************************************
Nom : CException
***************************************************************
Constructeur par défaut de la classe Cexception : permet
d’initialiser un objet
***************************************************************
Entrée : rien
Nécessite : néant
Sortie : rien
Entraîne : L’exception est intialisée à FAUX
***************************************************************/
CException::CException()
{
	uiEXCValeur = DEFAUT; // Initialisation de la valeur a 0
}


/**************************************************************
Nom : EXCmodifier valeur
***************************************************************
Cette fonction permet de modifier la valeur de l’exception
***************************************************************
Entrée : la nouvelle valeur de l’exception
Nécessite : néant
Sortie : rien
Entraîne : L’exception est modifiée
***************************************************************/
void CException::EXCModifierValeur(unsigned int valeur)
{
	uiEXCValeur = valeur;
}


/**************************************************************
Nom : EXClire valeur
***************************************************************
Cette fonction permet de consulter la valeur de l’exception
***************************************************************
Entrée : rien
Nécessite : néant
Sortie : la valeur de l’exception
Entraîne : L’exception est retournée
***************************************************************/
unsigned int CException::EXCLireValeur()
{
	return uiEXCValeur;
}