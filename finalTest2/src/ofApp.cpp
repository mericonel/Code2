#include "ofApp.h"

void ofApp::setup() {
	ofBackground(255);
	ship.setup();
	isPressed = false;
	lineX = ofGetWidth();
	lineY = 0;
	rightB = false;
	leftB = false;
	upB = false;
	downB = false;
	randomTime = 3000;
	time = 0;
	defeated = false;
	score = 0;

	waveyFont.load("waveyFont.ttf", 50);
	soundtrack.load("aquarium.mp3");
	soundtrack.play();
	soundtrack.setLoop(true);
	soundtrack.setSpeed(1);

	initiated = false;
	fontAlpha = 255;

	triangleImg.load("wave.png");
	imgW = ofGetWidth() * 5;
	imgH = ofGetHeight() * 5;
	scaler = 2800;
	speed = 1;

}

//--------------------------------------------------------------
void ofApp::update() {
	ship.update();
	ship.checkEdges();

	if (isPressed)ship.thrust();
	if (isRight) ship.turn(-0.003);
	if (isLeft)  ship.turn(0.003);

	if (defeated == false) {
		score = ofGetElapsedTimef();
	}
	if (isPressed == false && defeated == false){
	scaler += 1;
	} else if (isPressed == true && defeated == false) {
	scaler -= 1;
	}
	if (scaler >= 2000) {
		scaler = 2000;
	}
	if (scaler <= -5000) {
		scaler = -5000;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
if (defeated == false && initiated == true){
	ship.draw();
}
//----------------------------------wave-----------------------------
ofPushMatrix();
ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
ofRotate(ofGetFrameNum() * 0.05 * speed, 0, 0, 1);
ofPushMatrix();
triangleImg.draw(-imgW / 2 + scaler / 2, -imgH / 2 + scaler / 2, imgW - scaler, imgH - scaler);
ofPopMatrix();
ofPopMatrix();
//-------------------------------------wave----------------------------
if (defeated == true) {
	soundtrack.setSpeed(1);
scaler -= 3;
	ofSetColor(0);
	string scoreString = ofToString(score);
	waveyFont.drawString("Your score is " + scoreString, ofGetWidth() / 2 - 85, ofGetHeight() / 2);
	waveyFont.drawString("Press Enter to Restart", ofGetWidth() / 2 - 145, ofGetHeight()/2 + 40);
}
if (initiated == false) {
ofSetColor(0, fontAlpha);
	waveyFont.drawString("the wave", ofGetWidth() / 2 - 65, ofGetHeight() / 2);
	fontAlpha -= 0.1;
	scaler -= 4;
}
if (fontAlpha <= 0) {
	initiated = true;
}
	ofSetColor(255, 0, 0);
	ofSetLineWidth(10);
	soundSpeed = ofMap(randomSpeed, 0.05, 0.4, 0.5, 1.4);
	speed = ofMap(randomSpeed, 0.05, 0.4, 0.5, 2.5);

	if (initiated == true && defeated == false){
	soundtrack.setSpeed (soundSpeed);
	}

	if (defeated == false && initiated == true){
	if (ofGetElapsedTimeMillis() - time >= randomTime) {
		soundtrack.setSpeed(ofRandom(0.3, 1.5));
		randomChoose = ofRandom(0, 4);
		randomTime = ofRandom(1000, 3500);
		randomSpeed = ofRandom(0.05, 0.4);
		time = ofGetElapsedTimeMillis();
	}
	ofDrawLine(lineX, 0, lineX, ofGetHeight());
	ofDrawLine(0, lineY, ofGetWidth(), lineY);

	//check constraints and reset position
	if (lineX <= -10) {
		lineX = ofGetWidth() + 5;
	} else if (lineX >= ofGetWidth() + 10) {
		lineX = -5;
	}

	if (lineY <= -10) {
		lineY = ofGetHeight() + 5;
	} else if (lineY >= ofGetHeight() + 10) {
		lineY = -5;
	}

	//going left
	if (randomChoose >= 0 && randomChoose < 1){
	leftB = true;
	lineX -= randomSpeed;
	} else { leftB = false; }
	//going right
	if (randomChoose >= 1 && randomChoose < 2) {
		rightB = true;
		lineX += randomSpeed;
	} else { rightB = false; }
	//going down
	if (randomChoose >= 2 && randomChoose <= 3) {
	downB = true;
	lineY += randomSpeed;
	} else { downB = false; }
	//going up
	if (randomChoose >= 3 && randomChoose <= 4) {
		upB = true;
		lineY -= randomSpeed;
	} else { upB = false; }

	//cout << ship.x - lineX << endl;

	if (lineX - ship.x <=10 && lineX - ship.x >= -10) {
		defeated = true;
	} else if (lineY - ship.y <= 10 && lineY - ship.y >= -10) {
		defeated = true;
	}
	}

}

void ofApp::keyPressed(int key) {
	if (key == 'a' || key == 'A' || key == OF_KEY_LEFT) isRight = true;
	if (key == 'd' || key == 'D' || key == OF_KEY_RIGHT) isLeft = true;
	if (key == 'w' || key == 'W' || key == OF_KEY_UP) isPressed = true;

	if (defeated == true){
	if (key == OF_KEY_RETURN) {
		scaler = -5000;
		ofResetElapsedTimeCounter();
		defeated = false;
		ship.x = ofGetWidth()/2;
		ship.y = ofGetHeight()/2;
		lineX = ofGetWidth();
		lineY = 0;
		randomChoose = ofRandom(0, 4);
		randomTime = ofRandom(1000, 5000);
		randomSpeed = ofRandom(0.05, 0.25);
	}
	}
}
void ofApp::keyReleased(int key) {
	if (key == 'a' || key == 'A' || key == OF_KEY_LEFT) isRight = false;
	if (key == 'd' || key == 'D' || key == OF_KEY_RIGHT) isLeft = false;
	if (key == 'w' || key == 'W' || key == OF_KEY_UP) isPressed = false;
}
void ofApp::mouseMoved(int x, int y) { }
void ofApp::mouseDragged(int x, int y, int button) { }
void ofApp::mousePressed(int x, int y, int button) {
	//isPressed = true;
}

void ofApp::mouseReleased(int x, int y, int button) {
	//isPressed = false;
}
void ofApp::windowResized(int w, int h) { }
void ofApp::gotMessage(ofMessage msg) { }
void ofApp::dragEvent(ofDragInfo dragInfo) { }
