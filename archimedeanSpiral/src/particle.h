#ifndef particle_h
#define particle_h

#include <stdio.h>
#include "ofMain.h"


#endif /* particle_h */

class particle {
    
public:
    particle();
    
    void setup();
    void update(float speed,float noise);
    void draw(float sizeDot);
    void repel(vector<ofVec2f>repelPt);
    void applyForceFromSpiral(vector<ofVec2f> spiralPts);
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    ofVec2f repelFrc;
    float drag;
    
    ofVec2f uniqueVal;
    float size;
};
