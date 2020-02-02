#pragma once

#include "ofMain.h"
#include "FboSource.h"

class Arc : public ofx::piMapper::FboSource {
    public:
        void setup();
        void update();
        void draw();
        void setName(string _name);
        void setColor(ofColor);
        ofColor rectColor;
    
        float phase;
        void arc(float p, float radius,int width, int height);
       
        
};
