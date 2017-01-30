#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
ofBackground(244, 154, 194);
image.load("cat.png");
image2.load("discoBall.png");
myFont.load("curiousCat.ttf", 30);
spaceCats.load("spaceCats.mp3");

spaceCats.setVolume(0.5);

moveRect = false;

posY = -400;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
ofSetColor(255);
image.draw(150, 550, 250, 250);
image2.draw(350, posY, 300, 400);

if(moveRect == false){
ofSetColor(255, 200, 255);
ofDrawRectRounded(150, 550, 300, 250, 75);
ofPushMatrix();
ofSetColor(0);
myFont.drawString("Click here! Meow!", 200, 675);
ofPopMatrix();
}

//here i tried to make the disco ball slowly appear from the top and stop after 4 seconds
if (moveRect == true) {
	float timer = ofGetElapsedTimeMillis();
	if (timer = 1000) {
		timer = 0;
		posY = posY + 100;
	}
if (posY = 0) {
	posY=0;
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
	if (mouseX > 150) {
	if (mouseX < 450){
	if(mouseY > 550){
	moveRect = true;
	//plays the music
	spaceCats.play();

	}
	}
}

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
