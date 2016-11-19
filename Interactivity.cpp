#include "Interactivity.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/freeglut.h>
#endif

#include <iostream>
#include <cmath>
using namespace std;

// Include project files
#include "Player.h"
#include "Environment.h"

int level = 1;								// the level the game is on

float theta = 0;							// The angle of rotation
// The first 3 paramters of gluLookAt
float eye[] = {Environment::getLength(), Environment::getLength() * 3, -20};
// The 4-6 paramters of gluLookAt	
float center[] = {Environment::getLength(), 0, Environment::getLength() * 2 + 8};

int Interactivity::getLevel() {	 // Get the game level
	return level;
}

float Interactivity::getTheta() { // Get the horizontal angle of rotation
	return theta;
}

Interactivity::point3D Interactivity::getEye() { // Get first 3 paramters of gluLookAt
	Interactivity::point3D point;
	point.x = eye[0];
	point.y = eye[1];
	point.z = eye[2];
	return point;
}

Interactivity::point3D Interactivity::getCenter() { // Get 4-6 paramters of gluLookAt
	Interactivity::point3D point;
	point.x = center[0];
	point.y = center[1];
	point.z = center[2];
	return point;
}

void Interactivity::keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 'q':	// Quit the program
		case 'Q':
		case 27:
			exit(0);
			break;
		case 'w':	// Forward
		case 'W':
			Player::setRotation(270);
			break;
		case 'a':	// Left
		case 'A':
			Player::setRotation(0);
			break;
		case 's':	// Backwards
		case 'S':
			Player::setRotation(90);
			break;
		case 'd':	// Right
		case 'D':
			Player::setRotation(180);
			break;
	}
}

void Interactivity::special(int key, int x, int y) {
	float change;
	switch (key) {
		case GLUT_KEY_LEFT:		// Rotate left
			if (theta < 75)
				theta += 5;
			break;
 		case GLUT_KEY_RIGHT:	// Rotate right
			if (theta > -75)
				theta -= 5;
 			break;
 		case GLUT_KEY_UP:		// Move camera upwards
			if (eye[1] < 30)
				eye[1] += 2;
			break;
 		case GLUT_KEY_DOWN:		// Move camera downwards
			if (eye[1] > 6)
				eye[1] -= 2;
 			break;
	}
}

void Interactivity::printInstructions() {
	cout << "-----------------------------------"  << endl;
	cout << "INSTRUCITONS: " << endl;
	cout << "KEY             ACTION" << endl;
	cout << "Q               Quit"   << endl;
	cout << "ESC"            << endl;
	cout << "LEFT            Rotate camera left" << endl;
	cout << "RIGHT           Rotate camera right" << endl;
	cout << "UP              Move camera upwards" << endl;
	cout << "DOWN            Move camera downwards" << endl;
	cout << "W               Turn the character forwards" << endl;
	cout << "A               Turn the character left" << endl;
	cout << "S               Turn the character backwards" << endl;
	cout << "D               Turn the character right" << endl;
	cout << "-----------------------------------"  << endl;
}