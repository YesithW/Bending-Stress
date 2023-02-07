#pragma once
#ifndef BENIDING_H
#define BENIDING_H

class Bending
{
protected:
	double Load_kN, Length_m, w_cm, h_cm, r_cm;
	const double PI = 3.1416;
	/*
	Variable Definitions
	Load_kN		- The point load in kN
	Length_m	- Beam length in meters
	w_cm		- Width of the cross-section of the square shaped beam in centimeters
	h_cm		- Height of the cross-section of the square shaped beam in centimeters
	r_cm		- Radius of the cross-section of the round beam
	*/

public:
	Bending(); //Default constructor shall initialize all data members to ZERO
	void SetDim(double height, double width, double length); // Sets the dimensions of a square shaped beam
	void SetDim(double radius, double length);				// Sets the dimensions of a circular beam
	void SetLoad(double load);								//Sets the value of the point load
	double GetStress(double position, char shape);		//Calculates and return the of the given beam at different positions. 
	//Position is the x value and shape can have either c, C, s, or S depending on the shape  

};
#endif

