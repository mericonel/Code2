#include "particle.h"

particle::particle(ofVec2f pos) {
	myPos = pos;
	myVel = ofVec2f((ofRandom(-10.f, 10.0f)), (ofRandom(-10.f, 10.0f)));
	myLifeSpan = INITIAL_LIFE_SPAN;
}

void particle::update(float changeInVel) {

myAccel = ofVec2f(0, 0.1f);
	myVel += myAccel;
	myPos += myVel * changeInVel;

	if (myLifeSpan > 0) {
		myLifeSpan -= 1.0f;
	}

}
void particle::draw() {


	if (myLifeSpan > 290) {
		ofSetColor(147, 112, 219);
	}
	else {
		ofSetColor(147, ofRandom(255), ofRandom(255));
	}
	float size = ofMap(myLifeSpan, 0, 200, 0, 10);
	ofDrawCircle(myPos, size);
}
void particle::applyForce(ofVec2f force) {
	myAccel = force;
}