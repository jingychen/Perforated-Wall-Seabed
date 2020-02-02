/*
  Blue Mountains by Bárbara Almeida
  https://www.openprocessing.org/sketch/179401
 */
#include "mountain.h"

void Mountain::setup(){
	// Give our source a decent name
	name = "mountain";

	// Allocate our FBO source, decide how big it should be
	allocate(500, 500);

    
    
	cClouds = ofColor::fromHsb(330, 25, 100);  //light rose for the clouds
    cFade = ofColor::fromHsb(220, 50, 50); // purplish saturated medium blue for the fade of the sky
    cFurther = ofColor::fromHsb(230, 25, 90);  //purplish unsaturated light bluse for the further mountains
    cCloser = ofColor::fromHsb(210, 70, 10);  //greeny saturated dark blue for the closer mountains
    cMist = ofColor(255); //white for the mist
}
void Mountain::setName(string _name){
    name = _name;
}

// Don't do any drawing here
void Mountain::update(){
	
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void Mountain::draw(){
	
    if(int(ofGetFrameRate())%10 == 0){
    ofBackground(ofColor::fromHsb(230, 25, 90,100));
    fade(cFade,fbo->getWidth(),fbo->getHeight());
    clouds(cClouds,fbo->getWidth(),fbo->getHeight());
    mountains(cCloser, cFurther, cMist,fbo->getWidth(),fbo->getHeight());
    }
}
void Mountain::fade(ofColor fadeColor,int width, int height){
    for(int i = 0; i < height/3; i++)
    {
      float alfa = ofMap(i, 0, height/3, 360, 0);
      
      ofSetLineWidth(1);
      ofSetColor(fadeColor, alfa);
      ofDrawLine(0, i, ofGetWidth(), i);
    }

}
void Mountain::clouds(ofColor cloudColor,int width, int height){
    float begin = ofRandom(50); //changes the begin of noise each time
    
    float i = 0;
    
    for(int x = 0; x < width; x += 2)
    {
      float j = 0;
      
      for(int y = 0; y < width; y += 2)
      {
        float alfaMax = ofMap(y, 0, height/4, 520, 0);  //the clouds become transparent as they become near to the mountains
        float alfa = ofNoise(begin + i, begin + j);
        alfa = ofMap(alfa, 0.4, 1, 0, alfaMax);
        
        ofNoFill();
        ofSetColor(cloudColor, alfa);
        ofDrawEllipse(x, y, 2, 2);
        
        j += 0.06; //increase j faster than i so the clouds look horizontal
      }
      
      i += 0.01;
    }

}
void Mountain::mountains(ofColor closerColor, ofColor furtherColor, ofColor mistColor,int width, int height){
    //FIND THE REFERENCE Y OF EACH MOUNTAIN:
    float y0 = width - 500;  //fist reference y
    int i0 = 30;  //initial interval
    
    //float[] cy = new float[10]; //initialize the reference y array
    //vector<float> cy; //???
    float cy[10]; //how to define an array??
    for (int j = 0; j < 10; j++)
    {
      cy[9-j] = y0;
      y0 -= i0 / pow(1.2, j);
    }
    //DRAW THE MOUNTAINS/
    float dx = 0;
    
    for (int j = 1; j <  10; j++)
    {
      float a = ofRandom(-width/2, width/2);  //random discrepancy between the sin waves
      float b = ofRandom(-width/2, width/2);  //random discrepancy between the sin waves
      float c = ofRandom(2, 4);  //random amplitude for the second sin wave
      float d = ofRandom(40, 50);  //noise function amplitude
      float e = ofRandom(-width/2, width/2);  //adds a discrepancy between the noise of each mountain
        
      for (int x = 0; x < width; x ++)
      {
        float y = cy[j]; //y = reference y
        y += 10*j*sin(2*dx/j + a);  //first sin wave oscillates according to j (the closer the mountain, the bigger the amplitude and smaller the frequency)
        y += c*j*sin(5*dx/j + b);   //second sin wave has a random medium amplitude (affects more the further mountains) and bigger frequenc
        y += d*j*ofNoise(1.2*dx/j +e);  //first noise function adds randomness to the mountains, amplitude depends on a random number and increases with j, frequency decrases with j
        y += 1.7*j*ofNoise(10*dx);  //second noise function simulates the canopy, it has high frequency and small amplitude depending on j so it is smoother on the further mountains
        
        ofSetLineWidth(2);  //mountains look smoother with stroke weight of 2
        //ofSetColor(lerpColor(furtherColor, closerColor, j/9));
        ofSetColor(furtherColor.getLerped(closerColor, j/9));
        ofDrawLine(x, y, x, height);
        
        dx += 0.02;
      }
      
     
      //ADD MIST
      for (int i =  height; i > cy[j]; i -= 3)
      {
        float alfa = ofMap(i, cy[j], height, 0, 360/(j+1));  //alfa is begins bigger for the further mountains
        ofSetLineWidth(3);  //interval of 3 for faster rendering
        ofSetColor(mistColor, alfa);
        ofDrawLine(0, i, width, i);
      }
    }
}
