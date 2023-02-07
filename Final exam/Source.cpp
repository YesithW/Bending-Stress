#include <iostream>
#include "Bending.h"
#include <cmath>

using namespace std;

Bending::Bending() {
	Load_kN = Length_m = w_cm = h_cm = r_cm = 0;
}

void Bending::SetDim(double height, double width, double length) {
	h_cm = height;
	w_cm = width;
	Length_m = length;
}

void Bending::SetDim(double radius, double length) {
	r_cm = radius;
	Length_m = length;
}

void Bending::SetLoad(double load) {
	Load_kN = load;
}

double Bending::GetStress(double position, char shape) {
	double M, x, I, stress;
	
	if (shape == 's') {
		I = (w_cm * h_cm * h_cm * h_cm) / 12;
		for (int i = 0; i < position+1; i++) {
			x = (Length_m / position) * i;
			M = Load_kN * (Length_m - x);

			stress = M * (h_cm / 2)*1000 / I;

			cout << x << "\t\t" << stress<<"\n";
		}

	}

	else {
		I = (PI * r_cm * r_cm * r_cm * r_cm) / 4;
		for (int i = 0; i < position+1; i++) {
			x = (Length_m / position) * i;
			M = Load_kN * (Length_m - x);

			stress = M * (r_cm)*1000 / I;

			cout << x << "\t\t" << stress<<"\n";
		}

	}

	return 0;

	
}