#include "OpenHead.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
	ofSetVerticalSync(true);
	ofHideCursor();
    
    encoderPulses = 29000;
    scrollTimes = 20;
    scrollPulses = encoderPulses / scrollTimes;
    widthDouble = ofGetWidth()*2.0f;
   
    currentPos = oldPos = 0;
    movieXpos = 0;
    waiting = 0;
	speed = 0;
    timer = 0;
	openHeadMovie.loadMovie("movies/OpenHead.mov");
	openHeadMovie.play();
    enc.init();
    mean = meanCount = 0;
    position = 0.;
    goal = 1.;
    temp = 26.;
    difference = 0.;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    openHeadMovie.update();
    enc.update();
    
    currentPos += temp;
    scrollMod = currentPos % scrollPulses;
    //currentPos = enc.encPos;
    rotSpeed = currentPos - oldPos;
    
    movieXpos = ((scrollMod / (scrollPulses / widthDouble) ) - ofGetWidth())*-1.0f;
    
    cout << "movieXpos: " << movieXpos << endl;
    
    difference = (((goal - position) * 0.05) + difference) * 0.8;
    position += difference;
  
}

//--------------------------------------------------------------
void ofApp::draw(){

    openHeadMovie.draw(movieXpos * position ,0, ofGetWidth(), ofGetHeight());
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    switch(key){
        case '0':
            openHeadMovie.firstFrame();
        break;
        
        case 'f':
            ofToggleFullscreen();
        break;
        
        case 'r':
            meanCount = mean = 0;
        break;
        
        case 's':
            if (goal == 1.){
                goal = 0.;
            }
            else if(goal == 0.){
                goal = 1.;
            }
        break;
        case OF_KEY_UP:
            temp += 10;
            break;
        case OF_KEY_DOWN:
            temp -= 10;
            break;
    }
}
