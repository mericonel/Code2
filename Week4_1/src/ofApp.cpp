#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

xPos = ofGetWidth()/2;
yPos = ofGetHeight()/2;
radius = 25;
mover = 0.05;

}

//--------------------------------------------------------------
void ofApp::update(){

	if (ofGetElapsedTimeMillis() >= 3000) {
	randomFl = ofRandom (0, 4);
	radius = ofRandom(20, 30);
	ofResetElapsedTimeCounter();
}

if (randomFl > 0 && randomFl <= 1) {
	xPos += mover; 
	if (xPos >= ofGetWidth() - 100) {
	mover *= -1;
	}} else {}
if (randomFl > 1 && randomFl <= 2) {
	xPos -= mover;
	if (xPos <= 100) {
	mover *= -1;
	}} else {}
if (randomFl > 2 && randomFl <= 3) {
	yPos += mover; 
	if (yPos >= ofGetHeight() - 100) {
		mover *= -1;
	}} else {}
if (randomFl > 3 && randomFl <= 4) {
	yPos -= mover; 
	if (yPos <= 100) {
		mover *= -1;
	}} else {}
}

//--------------------------------------------------------------
void ofApp::draw(){
ofSetBackgroundAuto(false);

ofDrawCircle(xPos, yPos, radius);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
