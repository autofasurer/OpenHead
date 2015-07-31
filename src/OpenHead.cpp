#include "OpenHead.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
	ofSetVerticalSync(true);
	ofHideCursor();
    
    encoderPulses = 29000;
    scrollTimes = 10;
    tourCount = encoderPulses / scrollTimes;
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
    
    currentPos = enc.encPos;
    rotSpeed = currentPos - oldPos;

    meanCount += 1;
    mean += temp;
    
    cout << "mean: " << mean << endl;
    cout << "meanCount: " << meanCount << endl;
    cout << "speed: " << mean / meanCount << endl;
    //speed = mean / meanCount;
    
    oldPos = currentPos;
    
    speed = currentPos / tourCount;
    
    if (!waiting && movieXpos >= 0-ofGetWidth()){
        movieXpos = movieXpos - speed;
    }
    else {
    waiting = true;
    timer += 1;
        if (timer >= 100){
            waiting = false;
            timer = 0;
            movieXpos = ofGetWidth();
        }
    }
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
