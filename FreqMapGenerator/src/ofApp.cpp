#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
myFont.load("Double Pixel-7.ttf", 25);
nextTrigger = 0;
beatAllow = true;
screenshotCount = 0;

	cursor.load("cursor1.png");
	musicName = "badname";
	musicType = ".mp3";
beat.loadSound(musicName + musicType);
//i took fffSmooth and the ability to store beat from Lewis Lepton's
//example about audio reactive shapes: www.youtube.com/watch?v=liTsE7P-GDs
fftSmooth = new float [8192];
for (int i = 0; i < 8192; i++) {
	fftSmooth[i] = 0;
}

bands = 64;
beat.setLoop(true);
beat.setVolume(0.2);

	ofBackground(179, 158, 181);
	ofSetLineWidth(3);
	//ofSetBackgroundAuto(false);

	w = walker();
}

//--------------------------------------------------------------
void ofApp::update() {
	if (ofGetElapsedTimeMillis() > nextTrigger) {
	beatAllow = true;
	nextTrigger = ofGetElapsedTimeMillis()+ 20;
	}
	else {
		beatAllow = false;
	}

ofSoundUpdate();
float * value = ofSoundGetSpectrum(bands);
for (int i = 0; i < bands; i++) {
	fftSmooth[i] *= 0.3f;
	if (fftSmooth[i] < value[i]) {
		fftSmooth[i] = value [i];
}
}

if (backgroundReset == true){
	w.x = 0;
	w.y = 0;
}

if(musicPlaying == true){
for (int i = 0; i < bands; i++){
	if (fftSmooth[i] > 0.6 && beatAllow == true) {
		ofSetLineWidth(1);
		if (w.x >= 0) {
			if (w.y <= 0) {
				pt.set(102, -76);
				line.addVertex(pt);
			}else if (w.y > 0) {
				pt.set(102, 76);
				line.addVertex(pt);
			}} else if (w.x <= 0) {
			if (w.y < 0) {
				pt.set(-102, -76);
				line.addVertex(pt);
			}else if (w.y >= 0) {
				pt.set(-102, 76);
				line.addVertex(pt);
			}}}
	else {
		pt.set(w.x, w.y);
		line.addVertex(pt);
	}}}

ofSetFrameRate(mouseX);
	w.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
if (musicPlaying == false){
	ofSetColor(255, 0, 0);
	myFont.drawString("space to draw/pinpoint", 15, ofGetHeight()-25);
	ofSetColor(255, 255, 0);
	myFont.drawString("enter to reset position", 280, ofGetHeight() - 25);
	ofSetColor(0, 255, 0);
	myFont.drawString("c to clear", 555, ofGetHeight() - 25);
	ofSetColor(0, 255, 255);
	myFont.drawString("mouse for manual", 680, ofGetHeight() - 25);
	ofSetColor(0, 0, 255);
	myFont.drawString("m for music", 880, ofGetHeight() - 25); }

	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	ofScale(w.scale, w.scale);
	w.draw();

	ofSetLineWidth(3);
	line.draw();

	if (lineReset == true) {
	ofSetColor(0, 100);
		pt.set(w.x, w.y);
		line.addVertex(pt);
	} 

	ofPushMatrix();
	float a = atan2(w.y - 0, w.x - 0) * RAD_TO_DEG;
	if (backgroundReset == false) {
		ofRotate(a - 90);
	}
	ofSetColor(0, 100);
	cursor.draw(-5, -8, 10, 16);
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) { 
	if (key == OF_KEY_RETURN) {
	if(backgroundReset == false){
		backgroundReset = true;
		//line.close();
	}
	else {
		backgroundReset = false;
	}
	}

	if (key == 'm'){
	if (musicPlaying == false){
		beat.play ();
		musicPlaying = true;
		} else {
		img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		screenshotCount += 1;
		string filename = "SCR" + ofToString(musicName) + ofToString(screenshotCount)+".png";
		img.save(filename);
		beat.stop();
		musicPlaying = false;
		}
	}
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key) { 
	if (key == 'c') {
	line.clear();
	}

if (key == ' ') {
	if (lineReset == false) {
		lineReset = true;
	}
	else {
		lineReset = false;
		ofSetLineWidth(1);
		if (w.x >= 0){
		if (w.y <= 0) {
			pt.set(102, -76);
			line.addVertex(pt);
		} else if (w.y > 0) {
			pt.set(102, 76);
			line.addVertex(pt);
		}} else if (w.x <= 0){
		 if (w.y < 0) {
			pt.set(-102, -76);
			line.addVertex(pt);
		} else if (w.y >= 0) {
			pt.set(-102, 76);
			line.addVertex(pt);
		}
	}
}
}
}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) { }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) { 
ofPushMatrix();
float mx = ofMap(mouseX, 0, ofGetWidth(), -102, 102);
float my = ofMap(mouseY, 0, ofGetHeight(), -76, 76);
w.x = mx;
w.y = my;
ofPopMatrix();
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) { }
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) { }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) { }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) { }