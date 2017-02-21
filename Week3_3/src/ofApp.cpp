#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
gui.setup ();
gui.add(sinPara.set("SIN", 0.0, 0.0, 300.0));
gui.add(cosPara.set("COS", 0.0, 0.0, 300.0));

}

//--------------------------------------------------------------
void ofApp::update(){
sinF = sin(ofGetElapsedTimef() * 2.0) * sinPara;
cosF = cos(ofGetElapsedTimef() * 2.0) * cosPara;
}

//--------------------------------------------------------------
void ofApp::draw(){
gui.draw ();

ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
ofSetColor(138, 43, 226, 100);
ofCircle(sinF * sin(ofGetElapsedTimef() * 5), cosF * cos(ofGetElapsedTimef() * 4), 30);
ofSetColor(138, 43, 226, 95);
ofCircle(sinF * sin(ofGetElapsedTimef() * 4.95), cosF * cos(ofGetElapsedTimef() * 3.95), 30);
ofSetColor(138, 43, 226, 90);
ofCircle(sinF * sin(ofGetElapsedTimef() * 4.9), cosF * cos(ofGetElapsedTimef() * 3.9), 30);
ofSetColor(138, 43, 226, 85);
ofCircle(sinF * sin(ofGetElapsedTimef() * 4.85), cosF * cos(ofGetElapsedTimef() * 3.85), 30);
ofSetColor(138, 43, 226, 80);
ofCircle(sinF * sin(ofGetElapsedTimef() * 4.8), cosF * cos(ofGetElapsedTimef() * 3.8), 30);
ofSetColor(138, 43, 226, 75);
ofCircle(sinF * sin(ofGetElapsedTimef() * 4.75), cosF * cos(ofGetElapsedTimef() * 3.75), 30);
ofSetColor(138, 43, 226, 70);
ofCircle(sinF * sin(ofGetElapsedTimef() * 4.7), cosF * cos(ofGetElapsedTimef() * 3.7), 30);
ofSetColor(138, 43, 226, 65);
ofCircle(sinF * sin(ofGetElapsedTimef() * 4.65), cosF * cos(ofGetElapsedTimef() * 3.65), 30);
ofSetColor(138, 43, 226, 60);
ofCircle(sinF * sin(ofGetElapsedTimef() * 4.5), cosF * cos(ofGetElapsedTimef() * 3.6), 30);


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
