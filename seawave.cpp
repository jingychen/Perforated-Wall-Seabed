//From noisePixels
#include "seawave.h"

void Seawave::setup(){
	// Give our source a decent name
	name = "seawave";

	// Allocate our FBO source, decide how big it should be
	allocate(500, 500);
    
    ofSetFrameRate(60);
    rectSize = 3;
    noiseScale = 0.01;

	
}

void Seawave::setName(string _name){
    name = _name;
}

// Don't do any drawing here
void Seawave::update(){
	
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void Seawave::draw(){
	 ofBackground(0);
        for (int x=0; x<fbo->getWidth()/rectSize; x++)
        {
            for (int y=0; y < fbo->getHeight()/rectSize; y++)
            {
                float noiseValue = ofNoise(x*noiseScale, y*noiseScale, float(ofGetFrameNum())*noiseScale);
                ofSetColor(5,44,149,noiseValue * 255);
                ofDrawRectangle(x*rectSize,y*rectSize,rectSize,rectSize);
            }
        }
    }
