#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
ofSetBackgroundColor(216, 191, 216);
num = 100;

}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBeginShape();
	ofSetColor(128, 0, 128);
	for (int i = 0; i < num; i++) {

		float add = ofNoise(sin((i/100.0)*TWO_PI), ofGetElapsedTimef());
		ofVertex(ofGetWidth()/2 + (200  * add) * cos((i / num)*TWO_PI),
			ofGetHeight()/2 + (400  * add) * sin((i / num)*TWO_PI));
}
ofEndShape();

	ofBeginShape();
	ofSetColor(128, 0, 128, 90);
	for (int i = 0; i < num; i++) {

		float add = ofNoise(sin((i / 100.0)*TWO_PI), ofGetElapsedTimef());
	ofVertex(ofGetWidth() / 2 + (300 * add) * cos((i / num)*TWO_PI),
		ofGetHeight() / 2 + (400 * add) * sin((i / num)*TWO_PI)); 
}
ofEndShape();

ofBeginShape();
ofSetColor(128, 0, 128, 75);
for (int i = 0; i < num; i++) {

	float add = ofNoise(sin((i / 100.0)*TWO_PI), ofGetElapsedTimef());
ofVertex(ofGetWidth() / 2 + (350 * add) * cos((i / num)*TWO_PI),
		ofGetHeight() / 2 + (400 * add) * sin((i / num)*TWO_PI));
}
ofEndShape();
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
