/**
* @author Jakub Bubak
* @date 02.05.2024
*/

#ifndef PROJEKT_TM_DFT_H
#define PROJEKT_TM_DFT_H

#include "main.h"
#include <math.h>

typedef struct {
	double real;
	double imag;
} Complex;

void DFT(Complex *input, Complex *output, int N);

#endif //PROJEKT_TM_DFT_H
