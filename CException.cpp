#include "CException.h"
#include <fstream>

/**************************************************************
Nom : CException
***************************************************************
Constructeur par d�faut de la classe Cexception : permet
d�initialiser un objet
***************************************************************
Entr�e : rien
N�cessite : n�ant
Sortie : rien
Entra�ne : L�exception est intialis�e � FAUX
***************************************************************/
CException::CException()
{
	uiEXCValeur = DEFAUT; // Initialisation de la valeur a 0
}


/**************************************************************
Nom : EXCmodifier valeur
***************************************************************
Cette fonction permet de modifier la valeur de l�exception
***************************************************************
Entr�e : la nouvelle valeur de l�exception
N�cessite : n�ant
Sortie : rien
Entra�ne : L�exception est modifi�e
***************************************************************/
void CException::EXCModifierValeur(unsigned int valeur)
{
	uiEXCValeur = valeur;
}


/**************************************************************
Nom : EXClire valeur
***************************************************************
Cette fonction permet de consulter la valeur de l�exception
***************************************************************
Entr�e : rien
N�cessite : n�ant
Sortie : la valeur de l�exception
Entra�ne : L�exception est retourn�e
***************************************************************/
unsigned int CException::EXCLireValeur()
{
	return uiEXCValeur;
}