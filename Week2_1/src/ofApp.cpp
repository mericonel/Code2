#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
posX = ofGetWidth()/2 -size;
posY = ofGetHeight()/2 -size;
move =1;
size = 25;
colorX = 177;

}

//--------------------------------------------------------------
void ofApp::update(){
posX += move;

if(posX  > ofGetWidth() ){
move *= -1;
posY = ofGetHeight() / 2 - size/2;
colorX = ofRandom(0, 255);
size += 5;
}

if (posX <= 0) {
	move *= -1;
	size += 5;
	posY = ofGetHeight() / 2 - size/2;
	colorX = ofRandom(0, 255);
}

if (size >= 400) {
	size = 25;
}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundAuto(true);

ofPushMatrix();
ofSetColor(colorX, 156, 217);
ofDrawRectangle(posX, posY, size, size);
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
