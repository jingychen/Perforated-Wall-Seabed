#pragma once

#include "ofMain.h"
#include "FboSource.h"

class Animation : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void setName(string _name);
        void setColor(ofColor);
        ofColor rectColor;
    
        float t;
        float theta;
        int maxFrameCount;
        void circleAnimation(int width, int height);
};
