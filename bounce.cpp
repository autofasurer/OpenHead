//
//  bounce.cpp
//  OpenHead
//
//  Created by Brecht Debackere on 30/07/15.
//
//

#include "bounce.h"

float bounce(float position, float goal, float speed, float resistance){
    float newPos = goal - position;
    newPos *= speed;
    newPos *= resistance;
    return newPos;
}