#pragma once

#include "ofMain.h"
#include "FboSource.h"

class Seawave : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void setName(string _name);

		int rectSize;
        float noiseScale;
};
