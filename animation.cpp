/*Geometric Animations / 161016
 by Saskia Freeke
 https://www.openprocessing.org/sketch/405926
 */
#include "animation.h"

void Animation::setup(){
	// Give our source a decent name
    name = "circle animation";
    rectColor = ofColor(0);
	// Allocate our FBO source, decide how big it should be
    allocate(500, 500);
    maxFrameCount = 200;
}

void Animation::setName(string _name){
    name = _name;
}

void Animation::setColor(ofColor c){
    rectColor = c;
}

// Don't do any drawing here
void Animation::update(){
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void Animation::draw(){
    ofClear(0); //clear the buffer

    //do it with static values
    //since the buffer is 500x500, then...
    //drawMovingRect(250, 250, 500, 500);

    //or pass it dynamic values (ie. ask the fbo how big it is)
    //ofBackground(0);
    circleAnimation(fbo->getWidth(),fbo->getHeight());
}

void Animation::circleAnimation(int width, int height){
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(width/2, height/2); // translate 0,0 to center
    t = (float)ofGetFrameNum()/maxFrameCount;
    theta = TWO_PI*t;

    for ( int x= -175; x <= 175; x += 25) {
      for (int y= -100; y <= 155; y += 50) {
        float offSet = 50*x+y+y;   // play with offSet to change map below

        float x2 =ofMap(cos(-theta+offSet), 0, 1, 0, 25); // map x position
        float y2 =ofMap(cos(-theta+offSet), 0, 1, 25, 0); // map y position
        float sz2 =ofMap(sin(-theta+offSet), 0, 1, 15, 45); // map size off the ellipse
        ofSetColor(250-(x/2), 44 +(x/6), 250-(y/2),100); // color with gradient created

        ofDrawEllipse(x+x2, y-y2, sz2, sz2);
      }
    }
    ofPopStyle();
    ofPopMatrix();
}
