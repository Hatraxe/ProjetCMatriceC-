// ProjetCMatriceC++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#pragma once
#include "COperationMatrice.h"
#include "CException.h"
#include <iostream>
#include "CMatrice.h"
#include "CAnalyseurFichier.h"
using namespace std;

int main(int argc,char* argv[])
{
	double dConstante_c;  //La valeur qui sera saisie par l'utilisateur
	CMatrice<double> pMATListeMatrices[1024];  //Liste de matrice ou qui recevra les matrices crees par les fichiers
	CAnalyseurFichier Analyseur;  //Objet CAnalyseurfichier pour pouvoir appeler les methodes
	COperationMatrice<double> operation;  //Objet COperationMatrice pour pouvoir appeler les methodes

	for (int iBoucleArgv = 1; iBoucleArgv < argc; iBoucleArgv++) //Boucle qui parcour argv[] 
	{

		CMatrice<double> MATANA(Analyseur.ANAMatriceFichier(argv[iBoucleArgv])); // Creation d'une matrice a partir du fichier dont le chemin est contenu dans argv[iBoucleArgv]
		pMATListeMatrices[iBoucleArgv - 1] = MATANA; //Stockage de la matrice dans la liste de matrice


	}
	cout << "Saisissez la valeur c :" << endl;
	cin >> dConstante_c; //Demande de saisie de la constante c
	if (cin.fail())
	{
		cerr << "Erreur : la saisie n'est pas un nombre valide. Veuillez saisir un double." << endl;
	}
	cout << endl;

	//Multiplication des matrices par la valeur saisie par l'utilisateur
	for (int iBoucleArgv = 0; iBoucleArgv < argc - 1; iBoucleArgv++)   //Boucle qui parcour argv[]
	{
		cout << "MATRICE" << iBoucleArgv << " * " << dConstante_c << endl;
		operation.OPMAfficherMatrice(pMATListeMatrices[iBoucleArgv] * dConstante_c); //Affichage de la multiplication de chaque matrice par la constante saisie par l'utilisateur
	}
	//Division des matrices par la valeur saisie par l'utilisateur
	for (int iBoucleArgv = 0; iBoucleArgv < argc - 1; iBoucleArgv++)  //Boucle qui parcour argv[]
	{
		try
		{
			cout << "MATRICE" << iBoucleArgv << " / " << dConstante_c << endl;
			operation.OPMAfficherMatrice(pMATListeMatrices[iBoucleArgv] / dConstante_c);  //Affichage de la division de chaque matrice par la constante saisie par l'utilisateur
		}
		catch (CException divisionzero)
		{
			cerr << "Erreur : " << divisionzero.EXCLireValeur() << " division par zero impossible" << endl;
		}
	}
	//Addition des matrices entre elles

	CMatrice<double> MATAddition(pMATListeMatrices[0]); //Initialisation en recopiant premiere matrice de la liste

	for (int iBoucleArgv = 1; iBoucleArgv < argc - 1; iBoucleArgv++) //Boucle qui parcour argv[]
	{
		try {
			MATAddition = MATAddition + pMATListeMatrices[iBoucleArgv]; //Somme des matrice dans MATAddition
		}
		catch (CException erreurtaille)
		{
			cerr << "Erreur : " << erreurtaille.EXCLireValeur() << " Addition impossible matrice de tailles différentes." << endl;
		}
	}
	//Affichage de la matrice Addition
	cout << "Somme de toutes les matrices : " << endl;
	operation.OPMAfficherMatrice(MATAddition);
	cout << endl;

	//Alternance de soustraction et addtion de matrices
	CMatrice<double> MATAlternance(pMATListeMatrices[0]);  //Initialisation en recopiant premiere matrice de la liste

	for (int iBoucleArgv = 1; iBoucleArgv < argc - 1; iBoucleArgv++)//Boucle qui parcour argv[]
	{
		if (iBoucleArgv % 2 == 0) //test de parite si paire on additionne les matrices sinon on soustrait
		{
			try
			{
				MATAlternance = MATAlternance + pMATListeMatrices[iBoucleArgv]; //Addition
			}
			catch (CException erreurtaille)
			{
				cerr << "Erreur : " << erreurtaille.EXCLireValeur() << " Addition impossible matrice de tailles différentes." << endl;
			}
		}
		else
		{
			try
			{
				MATAlternance = MATAlternance - pMATListeMatrices[iBoucleArgv]; //Soustraction
			}
			catch (CException erreurtaille)
			{
				cerr << "Erreur : " << erreurtaille.EXCLireValeur() << " Soustraction impossible matrice de tailles différentes." << endl;
			}
		}
	}

	//Affichage de la matrice d'alternance
	cout << "Alternance de soustraction et d'addition des matrices : " << endl;
	operation.OPMAfficherMatrice(MATAlternance);
	cout << endl;

	//Multiplication des matrices entre elles
	CMatrice<double> MATMultiplication(pMATListeMatrices[0]);  //Initialisation en recopiant premiere matrice de la liste

	for (int iBoucleArgv = 1; iBoucleArgv < argc - 1; iBoucleArgv++)  //Boucle qui parcour argv[]
	{
		try
		{
			MATMultiplication = MATMultiplication * pMATListeMatrices[iBoucleArgv]; //Multiplication de matrices
		}
		catch (CException erreurtaille)
		{
			cerr << "Erreur : " << erreurtaille.EXCLireValeur() << " Multiplication impossible nombre de lignes de la matrice de gauche != du nombre de colonnes de celle de droite.." << endl;
		}
	}

	//Affichage de la matrice des multiplications
	cout << "Multiplication des matrices entre elles : " << endl;
	operation.OPMAfficherMatrice(MATMultiplication);
	cout << endl;
	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
