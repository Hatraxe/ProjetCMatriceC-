#include "CMatriceV2.h"

CMatriceV2<double> operator*(double mtpParam, CMatriceV2<double> mtpParamMatrice)
{
	return mtpParamMatrice * mtpParam;
}

