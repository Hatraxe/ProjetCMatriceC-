#include "CMatrice.h"

CMatrice<double> operator*(double mtpParam, CMatrice<double> mtpParamMatrice)
{
	return mtpParamMatrice * mtpParam;
}