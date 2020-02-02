
#pragma once

#include "ofMain.h"
#include "FboSource.h"

class Manyballs : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void drawMovingRect(int, int, int, int);
        void setName(string _name);
        void setColor(ofColor);
        ofColor rectColor;

        void setupBalls();
        void updateBalls();
        void drawBalls(int x, int y, int w, int h);

        vector <ofVec2f> locations;
        vector <ofVec2f> speeds;
};
