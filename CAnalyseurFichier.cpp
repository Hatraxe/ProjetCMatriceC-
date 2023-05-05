#pragma once
#include "CAnalyseurFichier.h"
#include "CException.h"
#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable : 4996)
#pragma warning(disable : 4244)

/*************************************************************************************************************
* Resume : Fonction analysant les informations que la ligne passe en parametre donne
* Entrees: char* pcStr
* Preconditions: {}
* Sorties: int
* Postconditions: {identification du type d'information}
***************************************************************************************************************/

int CAnalyseurFichier::ANAAnalyseurLigne(char* pcStr) 
{
	ANASupprimerEspace(pcStr);
	size_t sTaille = strlen(pcStr);
	if (pcStr[0] != '\0' && pcStr[0] != '\r' && pcStr[0] != '\n' && pcStr[0] != '\rn') 
	{

		if (strstr(pcStr,"type")!=nullptr || strstr(pcStr, "Type") != nullptr || strstr(pcStr, "TYPE") != nullptr)  
		{
			return 1;
		}
		else if (strstr(pcStr, "ligne")!=nullptr || strstr(pcStr, "Ligne")!=nullptr || strstr(pcStr, "LIGNE")!=nullptr) 
		{
			return 2;
		}
		else if (strstr(pcStr, "col") != nullptr || strstr(pcStr, "Col") != nullptr || strstr(pcStr, "COL") != nullptr) 
		{
			return 3;
		}
		else if (strstr(pcStr, "[") != nullptr) 
		{
			return 4;
		}
		else 
		{
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
	unsigned int uiRepere = 0;
	size_t stLength = strlen(pcStr);

	for (unsigned int uiBoucle = 0; uiBoucle < stLength; uiBoucle++)
		if (pcStr[uiBoucle] != ' ') 
		{
			pcStr[uiRepere++] = pcStr[uiBoucle];
		}
	pcStr[uiRepere] = '\0';
}

/*************************************************************************************************************
* Resume : Creer un objet CMatrice a partir d'un fichier texte
* Entrees: cons char* pcLien
* Preconditions: {}
* Sorties:CMatrice<double>
* Postconditions: {Renvoie la CMatrice correspondant aux information issus du fichier}
***************************************************************************************************************/

CMatrice<double> CAnalyseurFichier::ANAMatriceFichier(const char* pcCheminFichier) 
{
	ifstream fichierMatrice(pcCheminFichier);
	CMatrice<double> MATErreur(0,0);
	if (fichierMatrice.is_open())
	{
		int iTypeLigne;
		unsigned int NbLignes =0;
		unsigned int NbColonnes =0;
		char* pcTempoChaine;
		char cLigne[1024];

		do
		{
			fichierMatrice.getline(cLigne, 1024);
			iTypeLigne = ANAAnalyseurLigne(cLigne);
			if (iTypeLigne == 1) 
			{
				pcTempoChaine = strtok(cLigne, "=");
				pcTempoChaine = strtok(NULL, "=");

				if (strstr(pcTempoChaine,"double")!= nullptr) 
				{
					
				}
			}
			else if (iTypeLigne == 2) 
			{
				pcTempoChaine = strtok(cLigne, "=");
				pcTempoChaine = strtok(NULL, "=");
				NbLignes = atoi(pcTempoChaine);
			}
			else if (iTypeLigne == 3) 
			{
				pcTempoChaine = strtok(cLigne, "=");
				pcTempoChaine = strtok(NULL, "=");
				NbColonnes = atoi(pcTempoChaine);
			}
			else if (iTypeLigne == 4)
			{
				CMatrice<double> MATFichier(NbLignes,NbColonnes);
				double dElementMatrice;

				for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < NbLignes; uiBoucleLignes++) 
				{
					do {
						fichierMatrice.getline(cLigne, 1024);
					} while (cLigne[0] == '\n' || cLigne[0] == '\0');
					pcTempoChaine = strtok(cLigne, " []!§$£*+/?abcdefghijklmnopkrstuvwxyzABCDEFGHIJKLMNOPKRSTUVWXYZ\t");
					for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < NbColonnes; uiBoucleColonnes++) {
						dElementMatrice = stod(pcTempoChaine);
						MATFichier.MATModifierElement(uiBoucleLignes, uiBoucleColonnes, dElementMatrice);
						pcTempoChaine = strtok(NULL, " ");
						
					}

				}
				return MATFichier;
			}
		} while (cLigne[0] != NULL);
		return MATErreur;
	}
	//CException CException(1);
	/*if (fichier.is_open()) {

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

				//MATResult.MATModifierNbLignes(atoi(cpBuffer));
			}
			else if (iTypeVariable == 3) {
				cpBuffer = strtok(cLigne, "=");
				cpBuffer = strtok(NULL, "=");
				//MATResult.MATModifierNbrColonnes(atod(cpBuffer));
			}
			else if (iTypeVariable == 4) {
				int NbLignes = MATResult.MATLireNbLignes();
				int NbColonnes = MATResult.MATLireNbColonnes();
				double dElement;
				_CRT_DOUBLE dblValeur;
				for (int iIterateurLignes = 0; iIterateurLignes < NbLignes; iIterateurLignes++) {
					do {
						fichier.getline(cLigne, 1024);
					} while (cLigne[0] == '\n' || cLigne[0] == '\0');
					cpBuffer = strtok(cLigne, " []abcdefghijklmnopkrstuvwxyzABCDEFGHIJKLMNOPKRSTUVWXYZ\t");
					for (int iIterateurColonnes = 0; iIterateurColonnes < NbColonnes; iIterateurColonnes++) {
						dElement = _atodbl(&dblValeur, cpBuffer);
						//MATResult.MATModifierElement2D(iIterateurLignes, iIterateurColonnes, dblValeur.x);
						cpBuffer = strtok(NULL, " ");

					}

				}
			}
		} while (cLigne[0] != NULL);
		return MATResult;
	}*/
}