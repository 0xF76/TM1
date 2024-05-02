/**
* @author Jakub Bubak
* @date 02.05.2024
*/

#include "dft.h"

void DFT(Complex *input, Complex *output, int N) {
	Complex W[N];
	Complex sum;

	for(int i = 0; i < N; i++) {
		double angle = -2 * M_PI * i / N;
		W[i].real = cos(angle);
		W[i].imag = sin(angle);
	}

	for(int k = 0; k < N; k++) {
		sum.real = 0;
		sum.imag = 0;

		for(int n = 0; n < N; n++) {
			sum.real += input[n].real * W[(n * k) % N].real;
			sum.imag += input[n].real * W[(n * k) % N].imag;
		}

		if(sum.real < 0.001 && sum.real > -0.001) {
			sum.real = 0;
		}

		if(sum.imag < 0.001 && sum.imag > -0.001) {
			sum.imag = 0;
		}


		output[k].real = sum.real;
		output[k].imag = sum.imag;
	}
}

void DFT_bars(Complex *input, uint8_t* display, uint8_t N) {

	double temp[N];
	double max_val = DBL_MIN;

	for(int i = 0; i < N; i++) {
		temp[i] = sqrt(pow(input[i].real,2) + pow(input[i].imag,2));

		if(temp[i] > max_val) {
			max_val = temp[i];

		}
	}

	for(int i = 0; i < N; i++) {
		temp[i] = (temp[i] / max_val) * 8;
		display[i] = pow(2,(int)round(temp[i])) - 1;
	}

}
