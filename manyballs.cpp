//From manyballs#include "manyballs.h"
#include "manyballs.h"
void Manyballs::setup(){
	// Give our source a decent name
    name = "manyballs";
    rectColor = ofColor(255);
	// Allocate our FBO source, decide how big it should be
    allocate(500, 500);
    
    setupBalls();
    
    ofSetBackgroundAuto(false);
}

void Manyballs::setName(string _name){
    name = _name;
}

void Manyballs::setColor(ofColor c){
    rectColor = c;
}

// Don't do any drawing here
void Manyballs::update(){
    updateBalls();
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void Manyballs::draw(){
    //ofClear(0); //clear the buffer

    //do it with static values
    //since the buffer is 500x500, then...
    //drawMovingRect(250, 250, 500, 500);

    //or pass it dynamic values (ie. ask the fbo how big it is)
    
    ofSetColor(0, 0, 0, 20);
    
    ofDrawRectangle(0, 0, fbo->getWidth(), fbo->getHeight());
    
   drawBalls(0,0,fbo->getWidth(), fbo->getHeight());
}

void Manyballs::setupBalls() {
    ofSetCircleResolution(50);
    for (int i=0; i<50; i++){
        ofVec2f randomLocation = ofVec2f(ofRandom(0,fbo->getWidth()),ofRandom(0,fbo->getHeight()));
        locations.push_back(randomLocation);
        ofVec2f randomSpeed = ofVec2f(ofRandom(-3,3),ofRandom(-3,3));
        speeds.push_back(randomSpeed);
    }
}

void Manyballs::updateBalls(){
    // Move balls
    for(int i = 0; i < locations.size(); i++){
        locations[i] = locations[i] + speeds[i];
        if (locations[i].x<5 || locations[i].x>fbo->getWidth()-5) speeds[i].x*=-1;
        if (locations[i].y<5 || locations[i].y>fbo->getHeight()-5) speeds[i].y*=-1;
    }
}
void Manyballs::drawBalls(int x, int y, int w, int h){
    ofSetColor(0,82,219);
    
    for(int i = 0; i < locations.size(); i++){
//        float val = ofDist(0,0,locations[i].x,locations[i].y );
//        ofColor c;
//        c.r = ofMap(val, 0, 5, 0, 255);
//        c.g = ofMap(val, 0,5, 64, 255);
//        c.b = ofMap(val, 0,5, 128, 255);
//        ofSetColor(c, 255);
        ofDrawCircle(locations[i], 3);
    }
}
