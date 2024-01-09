#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------

void ofApp::drawN(int x, int y, int w, int h) {

	ofSetColor(128, 128, 128);
	ofDrawRectangle(x, y, w, h);

	ofPath parallelogram;
	parallelogram.lineTo(x, y);
	parallelogram.lineTo(x + w / 2.5, y);
	parallelogram.lineTo(x + w, y + h);
	parallelogram.lineTo(x + w - w / 2.5, y + h);
	parallelogram.close();

	parallelogram.setFilled(true);
	parallelogram.setFillColor(ofColor::black);
	parallelogram.setStrokeColor(ofColor::white);
	parallelogram.setStrokeWidth(4);

	parallelogram.draw();
}

//--------------------------------------------------------------

void ofApp::drawA(int x, int y, int w, int h) {
	
	ofFill();
	ofSetColor(128, 128, 128);
	int x01 = x;
	int x11 = x + w / 2;
	int x21 = x11;
	int y01 = y;
	int y11 = y;
	int y21 = y - h;
	ofDrawTriangle(x01, y01, x11, y11 , x21, y21);

	ofSetColor(0, 0, 0);
	int x02 = x01 + w/2 + w % 2;
	int x12 = x02 + w / 2;
	int x22 = x02;
	int y02 = y;
	int y12 = y;
	int y22 = y - h;
	ofDrawTriangle(x02, y02, x12, y12, x22, y22);

	ofNoFill();
	ofSetLineWidth(4);
	ofSetColor(255, 255, 255);
	ofDrawTriangle(x02, y02, x12, y12, x22, y22);

	ofFill();
}

//--------------------------------------------------------------

void ofApp::drawS(int xDown, int yDown, int rUp, int rDown) {

	ofPath arcUp;
	arcUp.arc(xDown + rUp / 4, yDown - rDown / 2.5, rUp, rUp, 120, 300);
	arcUp.setFilled(true);
	arcUp.setFillColor(ofColor(128, 128, 128));
	arcUp.setStrokeColor(ofColor::white);
	arcUp.setStrokeWidth(4);
	arcUp.draw();

	ofPath arcDown;
	arcDown.arc(xDown, yDown, rDown, rDown, 300, 480);
	arcDown.close();
	arcDown.setFilled(true);
	arcDown.setFillColor(ofColor::black);
	arcDown.setStrokeColor(ofColor::white);
	arcDown.setStrokeWidth(4);
	arcDown.draw();
}

//--------------------------------------------------------------

void ofApp::drawT(int x, int y, int w, int h) {

	ofPath figure;
	figure.lineTo(x, y);
	figure.lineTo(x + w / 3 * 2, y);
	figure.lineTo(x + w / 3 * 2, y + h);
	figure.lineTo(x + w / 3, y + h);
	figure.lineTo(x + w / 3, y + h / 3.5);
	figure.lineTo(x, y + h / 3.5);
	figure.close();
	figure.setFilled(true);
	figure.setFillColor(ofColor(128, 128, 128));
	figure.setStrokeColor(ofColor::white);
	figure.setStrokeWidth(4);
	figure.draw();

	ofFill();
	ofSetColor(0, 0, 0);
	ofDrawRectangle(x + w / 3 * 2, y, w / 3 , h / 3.5);

	ofNoFill();
	ofSetLineWidth(4);
	ofSetColor(255, 255, 255);
	ofDrawRectangle(x + w / 3 * 2, y, w / 3, h / 3.5);

	ofFill();
}

//--------------------------------------------------------------

void ofApp::drawY(int x, int y, int w, int h) {

	ofPath figure;
	figure.lineTo(x, y);
	figure.lineTo(x + w / 3 * 2, y);
	figure.lineTo(x + w / 3 * 2, y + h);
	figure.lineTo(x + w / 3, y + h);
	figure.lineTo(x + w / 3, y + h / 2);
	figure.close();
	figure.setFilled(true);
	figure.setFillColor(ofColor(128, 128, 128));
	figure.setStrokeColor(ofColor::white);
	figure.setStrokeWidth(4);
	figure.draw();

	ofFill();
	ofSetColor(0, 0, 0);
	ofDrawTriangle(x + w / 3 * 2, y, x + w, y, x + w / 3 * 2, y + h / 2);

	ofNoFill();
	ofSetLineWidth(4);
	ofSetColor(255, 255, 255);
	ofDrawTriangle(x + w / 3 * 2, y, x + w, y, x + w / 3 * 2, y + h / 2);

	ofFill();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//Set the background color
	ofBackground(255, 255, 255);
	
	int scale = 5;

	int x0 = 200;
	int y0 = 200;

	int offset = 20 * scale;
	int lettersHeight = 50 * scale;

	int nOrTWidth = 44 * scale;
	int aWidth = 53 * scale;
	int sWidth = 36 * scale;
	int yWidth = 46 * scale;
	int rUp = 20 * scale;
	int rDown = 23 * scale;

	drawN(x0, y0, nOrTWidth, lettersHeight);
	drawA(x0 + nOrTWidth + offset, y0 + lettersHeight, aWidth, lettersHeight);
	drawS(x0 + nOrTWidth + aWidth + 2.5 * offset, y0 + 1.35* rUp, rUp, rDown);
	drawT(x0 + nOrTWidth + aWidth + sWidth + 3 * offset, y0, nOrTWidth, lettersHeight);
	drawY(x0 + nOrTWidth + aWidth + sWidth + nOrTWidth + 4 * offset, y0, yWidth, lettersHeight);
	drawA(x0 + nOrTWidth + aWidth + sWidth + nOrTWidth + yWidth + 5 * offset, y0 + lettersHeight, aWidth, lettersHeight);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

void ofApp::exit() {
	// save your file in here!!
	//img.grabScreen(0,0,ofGetWidth(), ofGetHeight());
	//img.save("myPic.png", OF_IMAGE_QUALITY_BEST);
}
