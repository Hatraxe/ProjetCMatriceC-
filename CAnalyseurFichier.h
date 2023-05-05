#pragma once
#include <fstream>
#include <cstring>
#include "CMatrice.h"

class CAnalyseurFichier
{
public:
	static void ANASupprimerEspace(char* pcStr);
	static int ANAAnalyseurLigne(char* pcStr);
	static CMatrice<double> ANAMatriceFichier(const char* cLien);
};

