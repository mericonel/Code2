#pragma once
#include "ofMain.h"
#include "player.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	player ship;

	bool isPressed;
	bool isRight;
	bool isLeft;

	float lineX, lineY;
	bool rightB, leftB, upB, downB;
	float randomTime;
	float time;
	float randomChoose;
	float randomSpeed;

	int score;
	bool defeated;
	ofTrueTypeFont waveyFont;

	float fontAlpha;
	bool initiated;

	ofImage triangleImg;
	float imgW, imgH;
	float scaler;
	float speed;
	bool speeder = false;

	ofSoundPlayer soundtrack;
	float soundSpeed;


};
