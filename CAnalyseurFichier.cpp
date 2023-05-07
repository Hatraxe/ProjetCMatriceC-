#pragma once
#include "CAnalyseurFichier.h"
#include "CException.h"
#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable : 4996)


	/* Cette methode analyse et identifie les différentes types de lignes
	Entree : la chaine de caractere a analyser
	Pre-condition : neant
	Sortie : un entier correspondant au type de ligne (1 pour le typematrice, 2 pour le nbr de lignes, 3 celui de colonnes et 4 pour le debut les valeurs de la amtrice et zero le reste
	Post-condition : l'entier retourner correspond au type de ligne
	*/

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
	/* Cette methode permet de supprimer les espace dans une chaine de caractere
	Entree : la chaine de caractere que l'on veut traiter
	Pre-condition : neant
	Sortie : la chiane de caractere sans les espace
	Post-condition : la chaine de caractere retourne n'a plus d'espace
	*/

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


	/* Cette methode permet de creer une matrice de double a partir du chemin d'un fichier texte
	Entree : Le chemin du fichier texte
	Pre-condition : le fichier dois suivre un certain format voir README.txt
	Sortie : une nouvelle matrice de double avec les valeurs du fichier
	Post-condition : La matrice retourne est possede tout les valeurs et attributs du fichier texte en parametre ou CException erreurfichier ou CException erreurtype ou
	*/
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

				if (strstr(pcTempoChaine,"double")== nullptr && strstr(pcTempoChaine, "int")==nullptr && strstr(pcTempoChaine, "float")==nullptr)
				{
					CException erreurtype;
					erreurtype.EXCModifierValeur(ERREUR_TYPE);
					throw  erreurtype;
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
					pcTempoChaine = strtok(cLigne, " []abcdefghijklmnopkrstuvwxyzABCDEFGHIJKLMNOPKRSTUVWXYZ\t");
					for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < NbColonnes; uiBoucleColonnes++)
					{
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
	
	CException erreurfichier;
	erreurfichier.EXCModifierValeur(ERREUR_FICHIER);
	throw erreurfichier;

	
}