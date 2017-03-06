#pragma once
#include "ofMain.h"

class particle {
public:
	particle(ofPoint);
	void setup();
	void update();
	void display();
	bool isDead();

	ofVec2f location;
	ofPoint velocity;
	ofPoint acceleration;
	float alphaValue;

	
};