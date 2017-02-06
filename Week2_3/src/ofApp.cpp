#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
rotater = 0;
turn = 0.5;


}

//--------------------------------------------------------------
void ofApp::update(){
rotater += turn;
}
//--------------------------------------------------------------
void ofApp::draw(){

	ofDrawBitmapString("Click to change rate!", ofGetWidth()/2 - 75, 150);
	

ofPushMatrix();
	//ofRotate(50, 0, 0, 0);
ofTranslate(ofGetWidth() / 2 , ofGetHeight() / 2);
	ofRotate(rotater);
	ofSetColor(255);
	ofDrawTriangle(0,  - 150,  - 150,  + 150, + 150,  + 150);
	ofRotate(rotater);
	ofSetColor(177, 156, 217);
	ofDrawTriangle(0, -125, -125, +125, +125, +125);
	ofPopMatrix();

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

	turn = ofRandom(0.3, 1);

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
