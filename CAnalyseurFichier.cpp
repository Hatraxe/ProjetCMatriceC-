#pragma once
#include "CAnalyseurFichier.h"
#include "CException.h"

#pragma warning(disable : 4996)
#pragma warning(disable : 4244)

/*************************************************************************************************************
* Resume : Fonction analysant les informations que la ligne passe en parametre donne
* Entrees: char* pcStr
* Preconditions: {}
* Sorties: int
* Postconditions: {identification du type d'information}
***************************************************************************************************************/

int CAnalyseurFichier::ANAAnalyseLigne(char* pcStr) {
	ANASupprimerEspace(pcStr);
	size_t sTaille = strlen(pcStr);
	if (pcStr[0] != '\0' && pcStr[0] != '\r' && pcStr[0] != '\n' && pcStr[0] != '\rn') {

		if ('t' == tolower(pcStr[0])) {
			return 1;
		}
		else if (('l' == tolower(pcStr[5]) && 'i' == tolower(pcStr[6])) || ('l' == tolower(pcStr[6]) && 'i' == tolower(pcStr[7]))) {
			return 2;
		}
		else if (('c' == tolower(pcStr[5]) && 'o' == tolower(pcStr[6])) || ('c' == tolower(pcStr[6]) && 'o' == tolower(pcStr[7]))) {
			return 3;
		}
		else if ('m' == tolower(pcStr[0])) {
			return 4;
		}
		else {
			return 0;
		}
	}

}

/*************************************************************************************************************
* Resume : Supression des espaces de la chaine de caractere
* Entrees: char* pcStr
* Preconditions: {}
* Sorties:
* Postconditions: {la chaine de caractere n'a plus d'espace}
***************************************************************************************************************/

void CAnalyseurFichier::ANASupprimerEspace(char* pcStr)
{
	int iBoucle;
	int iRepere = 0;
	size_t iLength = strlen(pcStr);
	for (iBoucle = 0; iBoucle < iLength; iBoucle++)
		if (pcStr[iBoucle] != ' ') {
			pcStr[iRepere++] = pcStr[iBoucle];
		}

	pcStr[iRepere] = '\0';
}

/*************************************************************************************************************
* Resume : Creer un objet CMatrice a partir d'un fichier texte
* Entrees: cons char* pcLien
* Preconditions: {}
* Sorties:CMatrice<double>
* Postconditions: {Renvoie la CMatrice correspondant aux information issus du fichier}
***************************************************************************************************************/

CMatrice<double> CAnalyseurFichier::ANALireFichier(const char* pcLien) {
	ifstream fichier(pcLien);
	CMatrice<double> MATResult;
	//CException CException(1);
	if (fichier.is_open()) {

		char cLigne[1024];
		int iTypeVariable;
		char* cpBuffer;
		//Type des elements de la matrice
		do
		{
			fichier.getline(cLigne, 1024);
			iTypeVariable = ANAAnalyseLigne(cLigne);
			if (iTypeVariable == 1) {
				cpBuffer = strtok(cLigne, "=");
				cpBuffer = strtok(NULL, "=");
				if (tolower(cpBuffer[0] != 'd')) {
					//throw CException;
				}
			}
			else if (iTypeVariable == 2) {
				cpBuffer = strtok(cLigne, "=");
				cpBuffer = strtok(NULL, "=");

				MATResult.MATModifierNbrLignes(atoi(cpBuffer));
			}
			else if (iTypeVariable == 3) {
				cpBuffer = strtok(cLigne, "=");
				cpBuffer = strtok(NULL, "=");
				MATResult.MATModifierNbrColonnes(atoi(cpBuffer));
			}
			else if (iTypeVariable == 4) {
				int NbrLignes = MATResult.MATLireNbrLignes();
				int NbrColonnes = MATResult.MATLireNbrColonnes();
				double dElement;
				_CRT_DOUBLE dblValeur;
				for (int iIterateurLignes = 0; iIterateurLignes < NbrLignes; iIterateurLignes++) {
					do {
						fichier.getline(cLigne, 1024);
					} while (cLigne[0] == '\n' || cLigne[0] == '\0');
					cpBuffer = strtok(cLigne, " []abcdefghijklmnopkrstuvwxyzABCDEFGHIJKLMNOPKRSTUVWXYZ\t");
					for (int iIterateurColonnes = 0; iIterateurColonnes < NbrColonnes; iIterateurColonnes++) {
						dElement = _atodbl(&dblValeur, cpBuffer);
						MATResult.MATModifierElement2D(iIterateurLignes, iIterateurColonnes, dblValeur.x);
						cpBuffer = strtok(NULL, " ");

					}

				}
			}
		} while (cLigne[0] != NULL);
		return MATResult;
	}
}