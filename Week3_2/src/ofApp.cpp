#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	colorChange = 177;

}

//--------------------------------------------------------------
void ofApp::update(){

	ofBackground(30);
	ofSetColor(255);

circlePoints = 1600;
speed = ofGetElapsedTimef() / 2;


}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2); 
	ofPolyline circle;

	for (int i = 0; i<circlePoints; i++)
	{
		angle = TWO_PI / circlePoints*i;
		radius = 65 *sin((angle + speed)* 16);

		x = cos(angle + speed)*200;
		y = sin(angle + speed)*200;

		if (i<0.5*circlePoints) {
			x = cos(angle + speed)*(200 + radius);
			y = sin(angle + speed)*(200 + radius);

		}
		circle.addVertex(ofPoint(x, y));
	}

	ofSetLineWidth(7);
	ofSetColor(colorChange, 156, 217);
	circle.close(); 
	circle.draw();
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
