/*CLASSE CException
DOCUMENTATION
Attributs : uiEXCvaleur, entier, contient la valeur de l’exception
Structure : Cette classe contient une méthode de modification et une méthode
de consultation de la valeur de l’exception
Méthode : néant
Modules internes :*/

#include "CException.h"
#include <fstream>

//CORPS

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
	uiEXCValeur = FAUX;
	// l’exception est initialisée
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
	// l’exception est modifiée
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
inline unsigned int CException::EXCLireValeur()
{
	return(uiEXCValeur);
}