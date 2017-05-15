#include "player.h"


void player::setup() {
	location.set(ofGetWidth() / 2, ofGetHeight() / 2);
	velocity.set(0, 0);
	acceleration.set(0, 0);

	mass = 1;
	radius = mass * 16;
	damping = 0.995;
	topSpeed = 0.6;
	heading = 0;

	thrusting = false;


}

void player::update() {

	velocity += acceleration;
	velocity *= damping;
	location += velocity;
	acceleration *= 0;

}

void player::draw() {

	ofPushMatrix();
	ofTranslate(location.x, location.y + radius);
	ofRotate(ofRadToDeg(heading));

	if (thrusting) ofSetColor(ofColor::red);
	else ofSetColor(150);

	ofBeginShape();
	ofVertex(-radius, radius);
	ofVertex(0, -radius -5);
	ofVertex(radius, radius);
	ofEndShape();
	ofPopMatrix();
	thrusting = false;
}


void player::thrust() {

	float angle = heading - PI / 2;

	ofPoint force(cos(angle), sin(angle));
	force *= 0.003;

	applyForce(force);
	thrusting = true;
}

void player::turn(float a) {
	heading += a;
}


void player::checkEdges() {
	float frame = radius * 2;
	if (location.x > ofGetWidth()) location.x = -frame;
	else if (location.x < -frame) location.x = ofGetWidth();

	if (location.y > ofGetHeight() + frame) location.y = -frame;
	else if (location.y < -frame) location.y = ofGetHeight() + frame;
}


void player::applyForce(const ofPoint & force) {
	ofPoint f(force);
	acceleration += f;
}
