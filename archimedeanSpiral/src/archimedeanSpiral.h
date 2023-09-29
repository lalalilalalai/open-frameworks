#ifndef archimedeanSpiral_h
#define archimedeanSpiral_h

#include <stdio.h>
#include <map>
#include <cmath>
#include <iostream>
#include <ofPath.h>
#include "ofMain.h"

#endif /* archimedeanSpiral_h */

class archimedeanSpiral {
    
public:
    archimedeanSpiral();
    
    void setup();
    void update(float offset_x, float offset_y, float scale, float rotationAngle);
    void draw();
    
    std::vector<ofVec2f> dsk;
    ofPolyline polyline;
    float rotationAngle;
};
