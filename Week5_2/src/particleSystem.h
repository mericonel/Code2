#pragma once
#include "ofMain.h"
#include "particle.h"

class particleSystem {
public:
	particleSystem(ofVec2f pos);

	void update(ofVec2f force);
	void draw();

	vector<particle> myParticles;

	const int MAX_SIZE = 100;
	ofVec2f myPos;


};