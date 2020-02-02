//From Pulsating Arcs
#include "arc.h"

void Arc::setup(){
    // Give our source a decent name
    name = "pulsing arc";
    rectColor = ofColor(0);
    // Allocate our FBO source, decide how big it should be
    allocate(500, 500);
    
    
    //ofBackground(0);
    ofSetFrameRate(60);
    phase = 0;
   
}

void Arc::setName(string _name){
    name = _name;
}

void Arc::setColor(ofColor c){
    rectColor = c;
}

// Don't do any drawing here
void Arc::update(){
    phase++;
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void Arc::draw(){
    ofClear(0); //clear the buffer

    //do it with static values
    //since the buffer is 500x500, then...
    //drawMovingRect(250, 250, 500, 500);

    //or pass it dynamic values (ie. ask the fbo how big it is)
    //ofBackground(0);
     int numOfLines=40;
        float spacing = 8; // spacing between arcs

        for (int i=0; i<numOfLines; i++)
        {
            int position = phase + spacing*i;
            float phaseDiff = 8;
            arc(phase+ phaseDiff*i, spacing + spacing*i,fbo->getWidth(),fbo->getHeight());
        
    }

    
    
    
    }


   
void Arc::arc(float p, float radius,int width, int height){
    ofPushMatrix();
    ofTranslate(width/2, height/2);


    ofPath path;
    float startAngle = ofMap(sin(ofDegToRad(p)), -1, 1, 0, 360)*0.1 ;
    float endAngle = ofMap(sin(ofDegToRad(p)), -1, 1, 0, 360) + 1;
    path.arc(0, 0, radius, radius, startAngle, endAngle);
    path.setCircleResolution(100);
    path.setStrokeWidth(3);
    path.setFilled(false);

    //optional cool colors :)
    ofColor red = ofColor::red;
    ofColor blue = ofColor::blue;
    float percent = ofMap(endAngle, startAngle, 360, 0, 1, true);
    ofColor c = red.getLerped(blue, percent);
    path.setColor(c);
    //end of optional colors

    path.draw();
    ofPopMatrix();
}
