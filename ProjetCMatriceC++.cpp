// ProjetCMatriceC++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#pragma once
#include "COperationMatrice.h"
#include "CListe.h"
#include "CException.h"
#include <iostream>
#include "CMatrice.h"
#include "CAnalyseurFichier.h"

using namespace std;

int main()
{
	CAnalyseurFichier ANA;
	COperationMatrice<double> operation;
	CMatrice<double> MAT1(2, 3);
	MAT1[0][0] = 1;
	MAT1[0][1] = 2;
	MAT1[0][2] = 3;
	MAT1[1][0] = 4;
	MAT1[1][1] = 5;
	MAT1[1][2] = 6;
	cout<< "MAT 1 : "<<"\n"<<endl;
	operation.OPMAfficherMatrice(MAT1);

	CMatrice<double> MAT2(3, 2);
	MAT2[0][0] = 1;
	MAT2[0][1] = 2;
	MAT2[1][0] = 3;
	MAT2[1][1] = 4;
	MAT2[2][0] = 5;
	MAT2[2][1] = 6;
	cout << "MAT 2 : " << "\n" << endl;
	operation.OPMAfficherMatrice(MAT2);

	CMatrice<double> MAT3(2, 3);
	MAT3[0][0] = 7;
	MAT3[0][1] = 8;
	MAT3[0][2] = 9;
	MAT3[1][0] = 10;
	MAT3[1][1] = 11;
	MAT3[1][2] = 12;
	cout << "MAT 3 : " << "\n" << endl;
	operation.OPMAfficherMatrice(MAT3);
	//Multiplier par une constante a gauche
	CMatrice<double> MATResultat = 0*MAT1;
	cout << "0 * MAT 1 : " << "\n" << endl;
	operation.OPMAfficherMatrice(MATResultat);
	//Multiplier par une constante a droite
	MATResultat = MAT1 * 10;
	cout << "MAT 1 * 10 : " << "\n" << endl;
	operation.OPMAfficherMatrice(MATResultat);
	//Diviser par une constante
	MATResultat = MAT1 / 10;
	cout << "MAT 1 / 10 : " << "\n" << endl;
	operation.OPMAfficherMatrice(MATResultat);
	//Multiplier 2 matrices
	MATResultat = MAT2 * MAT1;
	cout << "MAT 2 * MAT1 : " << "\n" << endl;
	operation.OPMAfficherMatrice(MATResultat);
	
	//Soustraire 2 matrices (TODO)
	CMatrice<double> MATAdd(2, 3);
	MATAdd = MAT3 - MAT3;
	cout << "MAT 3 - MAT3 : " << "\n" << endl;
	operation.OPMAfficherMatrice(MATAdd);
	//Additionner 2 matrices (TODO)
	MATAdd = MAT3 + MAT1;
	cout << "MAT 3 + MAT1 : " << "\n" << endl;
	operation.OPMAfficherMatrice(MATAdd);
	
	// Transposer
	CMatrice<double> matriceTransposee = operation.OPMTransposer(MAT2);
	cout << "Transpose de MAT2 : " << endl;
	operation.OPMAfficherMatrice(matriceTransposee);
	CMatrice<double> MATANA(ANA.ANAMatriceFichier("C:/Users/souli/Desktop/FichierTest.txt"));

	cout << "MATANA : " << endl;
	operation.OPMAfficherMatrice(MATANA);
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
