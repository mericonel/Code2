#include "particle.h"

particle::particle(ofPoint l) {
	acceleration.set(0, 0.05);
	velocity.set(ofRandom(-1, 1), ofRandom(-2, 0));
	location.set(ofGetWidth()/2, 100);
	alphaValue = 400.0;
}

void particle::setup() {

}

void particle::update() {
	velocity += acceleration;
	location += velocity;
	alphaValue -= 2.0;

}

void particle::display() {
	ofSetColor(147, 112, 219, alphaValue);
	ofDrawCircle(location, 6);
}

bool particle::isDead() {
	if (alphaValue < 0.0) {
		return true;
	}
	else {
		return false;
	}
}
