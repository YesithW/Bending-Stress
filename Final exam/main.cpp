#include <iostream>
#include "Bending.h"

using namespace std;

int main() {

	char shape;
	int len, wid, hei, radi, load, points;
	cout << "Bending Stress Calculation\n\n"
		"\t Circle <c>\n"
		"\t Square <s>\n\n"
		"Select the shape <c or s> \t";
		cin >> shape;

	cout << "\nProvide the beam dimensions in the given units\n";

	if (shape == 's') {
		
		cout << "\nLength (m)\t"; cin >> len;
		cout << "\nWidth (cm)\t"; cin >> wid;
		cout << "\nHeight (cm)\t"; cin >> hei;

	}

	else if (shape == 'c') {
		cout << "Length (m)\t"; cin >> len;
		cout << "\nRadius (cm)\t"; cin >> radi;

	}

	else  {
		cout << "Enter a valid input";
	}


	cout << "\n Provide the loading analysis details\n\n"
		"Point Load (kN)\t"; cin >> load;

	cout << "\nNumber of points required \t"; cin >> points;

	Bending obj;

	if (shape == 's') {
		obj.SetDim(hei, wid, len);
	}

	else if (shape == 'c') {
		obj.SetDim(radi, len);

	}
	
	obj.SetLoad(load);
	cout << "\nStress Distribution\n";
	cout << "\nDistance \t" << "Stress (MPa)\n\n";

	obj.GetStress(points, shape);
	



	return 0;
}