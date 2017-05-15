#include "player.h"

player::player() {
x = 0;
y = 0;
}

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
	x = -radius / 2;
	y = radius;

}

void player::draw() {

	ofPushMatrix();
	ofTranslate(location.x, location.y + radius);
	ofRotate(ofRadToDeg(heading));

	if (thrusting) ofSetColor(ofColor::salmon);
	else ofSetColor(125);

	ofDrawRectangle(-radius / 2 - 2, radius, radius / 2, radius / 2);
	ofDrawRectangle(-radius / 2 + 10, radius, radius / 2, radius / 2);

	ofBeginShape();
	ofVertex(-radius, radius);
	ofVertex(0, -radius);
	ofVertex(radius, radius);
	ofEndShape();
	ofPopMatrix();
	thrusting = false;
}

void player::thrust() {

	float angle = heading - PI / 2;

	ofPoint force(cos(angle), sin(angle));
	force *= 0.0025;

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
