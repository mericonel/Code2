#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	gravity = ofVec2f(0.f, .01f);

}

//--------------------------------------------------------------
void ofApp::update() {

	for (int i = 0; i <mySystems.size(); i++) {
		mySystems[i].update(gravity);
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < mySystems.size(); i++) {
		mySystems[i].draw();
	}

	if (ofGetElapsedTimeMillis() >= 2500) {
		particleSystem myParticleSystem(ofVec2f(mouseX, mouseY));
		mySystems.push_back(myParticleSystem);
		ofResetElapsedTimeCounter();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//particleSystem myParticleSystem(ofVec2f(x, y));
	//mySystems.push_back(myParticleSystem);


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}