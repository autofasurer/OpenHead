#include "OpenHead.h"
#include "bounce.h"

//--------------------------------------------------------------
void ofApp::setup(){
    currentPos = oldPos = 0;
    newOffset = oldOffset = target = 1.000;
	ofBackground(0,0,0);
	ofSetVerticalSync(true);
	ofHideCursor();
    movieXpos = 0;
    waiting = 0;
	speed = 5;
    timer = 0;
	openHeadMovie.loadMovie("movies/OpenHead.mov");
	openHeadMovie.play();
    enc.init();
    mean = meanCount = 0;
    testposition = 0.;
    goal = 1.;
    difference = 0.;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    openHeadMovie.update();
    enc.update();
    currentPos = enc.encPos;
    rotSpeed = currentPos - oldPos;
    meanCount += 1;
    mean += rotSpeed;
    oldPos = currentPos;
    
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
    difference = ((((goal - testposition) * 0.05) + difference) * 0.8);
    testposition += difference;
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofPixels &pixels = openHead.getPixelsRef();
    openHeadMovie.draw(movieXpos * testposition ,0, ofGetWidth(), ofGetHeight());
    //cout << enc.encPos << endl;
    oldOffset = newOffset;
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    switch(key){
        case '0':
            openHead.firstFrame();
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
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
