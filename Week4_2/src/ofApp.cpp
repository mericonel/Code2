#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	scale = 20;
	cols = floor(ofGetWindowWidth() / scale);
	rows = floor(ofGetWindowHeight() / scale);

	inc = 0.1;
	ofSetFrameRate(10);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
float yOff = 0;
	for (int y = 0; y < rows; y++) {
	float xOff = 0;
		for (int x = 0; x < cols; x++) {
		float start = (x + y * ofGetWidth()) * 4;
		float r = ofNoise(xOff, yOff) * 255;
			xOff += inc;
			ofSetColor(ofColor(ofRandom(r)));
			ofDrawRectangle(x * scale, y * scale, scale, scale);
		}
		yOff += inc;
	}

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
