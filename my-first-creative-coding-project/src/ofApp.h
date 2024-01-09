#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void drawN(int x, int y, int w, int h);
		void drawA(int x, int y, int w, int h);
		void drawS(int xUp, int yUp, int rUp, int rDown);
		void drawT(int x, int y, int w, int h);
		void drawY(int x, int y, int w, int h);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void exit();

		ofImage img;
};
