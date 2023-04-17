// ProjetCMatriceC++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#pragma once
#include "CListe.h"
#include "CException.h"
#include <iostream>
using namespace std;

int main()
{
   cout << "Hello World!\n";
   CListe<double> *C1 = new CListe<double>(2);
   CListe<double>* C2 = new CListe<double>(3);
  
   C2->LISModifierElement(123, 1);
   C1->LISModifierElement(65656, 1);
   CListe<double>* C3 = new CListe<double>(*C2);
   cout << C2->LISLireElement(1) << endl;
   cout << C1->LISLireElement(1) << endl;
   
   C1 = C2;

   cout << C1->LISLireTaille() << endl;
   cout << C2->LISLireTaille() << endl;
   C1->LISModifierElement(895, 0);

   cout << C2->LISLireElement(1) << endl;
   cout << C1->LISLireElement(1) << endl;
   C2->LISAjouterElement(456, 0);
   cout << C2->LISLireElement(0) << endl;
   cout << C2->LISLireElement(1) << endl;
   cout << C1->LISLireElement(1) << endl;
   cout << C3->LISLireElement(1) << endl;
   
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
