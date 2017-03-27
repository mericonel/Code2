#pragma once
#include "ofMain.h"

class particle {
public:
	particle(ofVec2f pos);
	void update(float changeInVel);
	void draw();
	void applyForce(ofVec2f force);

	ofVec2f myPos, myVel, myAccel;
	float myLifeSpan;
	float direction;

	const float INITIAL_LIFE_SPAN = 300.0f;
};
