#include "CMatrice.h"

/*Cette fonction permet de multiplier un double par un CMatrice
Entree : un double, et une matrice
Pre - condition : neant
Sortie : une matrice de double
Post - condition : La matrice retourne contient les valeurs correspondant au double* la matrice
*/
CMatrice<double> operator*(double mtpParam, CMatrice<double> mtpParamMatrice)
{
	return mtpParamMatrice * mtpParam;
}
