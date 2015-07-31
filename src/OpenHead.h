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
    int                     movieXpos, speed, timer, fullCircle;
    bool                    waiting;
    ofxPhidgetsEncoder      enc;
    float                   currentPos, oldPos, rotSpeed;
    double                  mean, meanCount, temp;
    float                   position, goal, difference;
    
    float                   tourCount, scrollTimes, encoderPulses;
};

