#pragma once
#include <fstream>
#include "CMatrice.h"
class CAnalyseurFichier
{
public:
	static void ANASupprimerEspace(char* pcStr);
	static int ANAAnalyseLigne(char* pcStr);
	static CMatrice<double> ANALireFichier(const char* cLien);
};

