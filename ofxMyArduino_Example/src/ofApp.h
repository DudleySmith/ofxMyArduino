#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxMyArduino.h"

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
		
    ofxPanel m_pnPanel;
    ofxPanel m_pnPinValues;
    

    ofxIntSlider     m_pin02;
    ofxIntSlider     m_pin03;
    ofxIntSlider     m_pin04;
    ofxIntSlider     m_pin05;
    ofxIntSlider     m_pin06;
    ofxIntSlider     m_pin07;
    ofxIntSlider     m_pin08;
    ofxIntSlider     m_pin09;
    ofxIntSlider     m_pin10;
    ofxIntSlider     m_pin11;
    ofxIntSlider     m_pin12;
    ofxIntSlider     m_pin13;
    
    ofxMyArduinoClient m_oArdClient;
    ofxMyArduinoServer m_oArdServer;
    ofArduino ard;
    
    void setupArduino(const int & version);
    
};
