//From SimpleSine
#include "rec.h"

void Rectangle::setup(){
	// Give our source a decent name
    name = "rotate rectangle";
    rectColor = ofColor(255);
	// Allocate our FBO source, decide how big it should be
    allocate(500, 500);
    
    ofSetFrameRate(60);
}

void Rectangle::setName(string _name){
    name = _name;
}

void Rectangle::setColor(ofColor c){
    rectColor = c;
}

// Don't do any drawing here
void Rectangle::update(){
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void Rectangle::draw(){
    ofClear(0); //clear the buffer

    //do it with static values
    //since the buffer is 500x500, then...
    //drawMovingRect(250, 250, 500, 500);

    //or pass it dynamic values (ie. ask the fbo how big it is)
    drawRotRec(fbo->getWidth(),fbo->getHeight());
}

void Rectangle::drawRotRec(int width, int height){ //ofGetWidth()should be fob->getWidth()
    //RECT rotation
    ofSetColor(255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(width/2, height/2);
    float angle = sin(ofDegToRad(ofGetFrameNum())) * 180;
    ofRotateDeg(angle);
    float c2 = ofMap(sin(ofDegToRad(ofGetFrameNum())), -1, 1, 0, 255);
    ofSetColor(c2,ofRandom(0,255),ofRandom(0,255),255);
    ofDrawRectangle(0,0,200,200);
    ofPopMatrix();
}

