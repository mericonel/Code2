#pragma once
#include "ofMain.h"

class walker {
public:
	walker();

	void setup();
	void update();
	void draw();

	int constrain(int, int, int);

	int x;
	int y;
	int scale;
	float alpha;

};


