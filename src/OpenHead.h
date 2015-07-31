#pragma once

#include "ofMain.h"
#include "ofxPhidgetsEnc.h"
class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		void keyPressed(int key);
	

    ofVideoPlayer           openHeadMovie;
    int                     movieXpos, timer, fullCircle, scrollMod, scrollPulses, currentPos;
    bool                    waiting;
    ofxPhidgetsEncoder      enc;
    float                   oldPos, rotSpeed;
    double                  mean, meanCount, temp;
    float                   position, goal, difference;
    
    float                   widthDouble, scrollTimes, encoderPulses, speed;
};

