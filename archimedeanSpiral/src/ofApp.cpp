#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    recording = false;
    
    gui.setup();
//    gui.add(scale.setup("spiralScale", 65, 1, 100));
    gui.add(scale.setup("spiralScale", 90, 1, 100));
    //    gui.add(rotationAngle.setup("rotationAngle", M_PI / 8, M_PI / 16, M_PI / 2));
    gui.add(overallSpeed.setup("speed", 0.5, 0, 3));
    gui.add(noiseAmount.setup("noise", 1, 0, 3));
    gui.add(trail.setup("trail", 25, 0, 255));
    
//    p1.assign(2500, particle());
    p1.assign(1000, particle());
    
    for (int i = 0; i < p1.size(); i++) {
        p1[i].setup();
    }
    
    //NICER TRAILS
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB); // with alpha, 32 bits red, 32 bits green, 32 bits blue, 32 bits alpha, from 0 to 1 in 'infinite' steps
    
    //FASTER
    //fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA); // with alpha, 8 bits red, 8 bits green, 8 bits blue, 8 bits alpha, from 0 to 255 in 256 steps
    
    fbo.begin();
    ofClear(255, 255, 255, 0);
    fbo.end();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (recording) {
        glReadBuffer(GL_FRONT);
        
        //        ofSaveFrame(true);
        //        ofSaveScreen(ofToString(ofGetFrameNum())+".png");
        ofSaveViewport(ofToString(ofGetFrameNum())+".png");
    }
    
    //--------------------------------------------------------------
    archimedeanSpiral1.update(ofGetWidth()/2, ofGetHeight()/2, scale, M_PI / 8);
    
    for (int i = 0; i < p1.size(); i++) {
        p1[i].update(overallSpeed,noiseAmount);
        p1[i].applyForceFromSpiral(archimedeanSpiral1.dsk);
    }
    
    ofEnableAlphaBlending();
    
    //lets draw some graphics into our fbo
    fbo.begin();
    
    
    ofSetColor(0, 0, 0, trail);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    for (int i = 0; i < p1.size(); i++) {
        ofSetColor(ofColor::white);
        p1[i].draw(1);
    }
    
    fbo.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0, 0, 0, 255);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255, 255, 255,255);
    fbo.draw(0, 0);
    
    
    for (int i = 0; i < p1.size(); i++) {
        ofSetColor(ofColor::white);
        p1[i].draw(1);
    }
    
    
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='r'){
        recording = true;
    }
    if(key=='c'){
        recording = false;
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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
