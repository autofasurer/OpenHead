#pragma once

#include "ofMain.h"
#include "ofxPhidgetsEnc.h"
class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		

    ofVideoPlayer           openHeadMovie;
    int                     movieXpos, speed, timer, fullCircle;
    bool                    waiting;
    ofxPhidgetsEncoder      enc;
    float                   currentPos, oldPos, rotSpeed;
    double                  mean, meanCount, target, oldOffset, newOffset;
    float                   testposition, goal, difference;
};

