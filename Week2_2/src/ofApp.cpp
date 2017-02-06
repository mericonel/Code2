#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
image.load("star.png");

size = 100;

}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofGetElapsedTimeMillis() >= 1000) {
		posX = ofRandom(0, ofGetWidth());
		posY = ofRandom(0, ofGetWidth() / 2 - 400);
		ofResetElapsedTimeCounter();
		size = 100;
		}
}

//--------------------------------------------------------------
void ofApp::draw(){

	posY += 1;
	size -= 0.1;

	if (size <= 5) {
		size = 5;
	}

cout << ofGetElapsedTimeMillis() << endl;

image.draw(posX, posY, size, size);

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
