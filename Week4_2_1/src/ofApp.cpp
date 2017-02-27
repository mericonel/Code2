#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	scale = 20;
	ofSetFrameRate(25);

	ofSetBackgroundColor(147, 112, 219);


}

//--------------------------------------------------------------
void ofApp::update(){

	if (ofGetElapsedTimeMillis() >= 10000){
		ofSetBackgroundAuto(true);
		ofResetElapsedTimeCounter();
}
}

//--------------------------------------------------------------
void ofApp::draw(){

ofSetBackgroundAuto (false);

	for (int y = 0; y < 50; y++) {
		for (int x = 0; x < 50; x++) {
			ofSetColor(ofColor(0));
			ofTranslate(x * scale, y * scale);
			float angle = ofRandom(360);
			ofRotate (angle);
			ofDrawLine (x * scale, y * scale, scale, 3);
		}
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
