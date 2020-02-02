#pragma once

#include "ofMain.h"
#include "FboSource.h"

class Mountain : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void setName(string _name);

		ofColor cClouds,  cFade, cFurther, cCloser, cMist;
        void fade(ofColor fadeColor,int width, int height);
        void clouds(ofColor cloudColor,int width, int height);
        void mountains(ofColor closerColor, ofColor furtherColor, ofColor mistColor,int width, int height);
        };
