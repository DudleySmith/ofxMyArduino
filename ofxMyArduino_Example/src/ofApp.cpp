#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    m_oArdServer.m_gpArduino.setName("Arduino");
    m_pnPanel.setup(m_oArdServer.m_gpArduino, "XML/MyArduino.xml");
    m_pnPanel.loadFromFile("XML/MyArduino.xml");
    
    m_pnPinValues.setup();
    m_pnPinValues.setName("Values");
    m_pnPinValues.setPosition(10, 100);
    m_pnPinValues.add(m_pin01.setup("Pin 01", 0, 0, 255));
    m_pnPinValues.add(m_pin02.setup("Pin 02", 0, 0, 255));
    m_pnPinValues.add(m_pin03.setup("Pin 03", 0, 0, 255));
    m_pnPinValues.add(m_pin04.setup("Pin 04", 0, 0, 255));
    m_pnPinValues.add(m_pin05.setup("Pin 05", 0, 0, 255));
    m_pnPinValues.add(m_pin06.setup("Pin 06", 0, 0, 255));
    m_pnPinValues.add(m_pin07.setup("Pin 07", 0, 0, 255));
    m_pnPinValues.add(m_pin08.setup("Pin 08", 0, 0, 255));
    m_pnPinValues.add(m_pin09.setup("Pin 09", 0, 0, 255));
    m_pnPinValues.add(m_pin10.setup("Pin 10", 0, 0, 255));
    m_pnPinValues.add(m_pin11.setup("Pin 11", 0, 0, 255));
    m_pnPinValues.add(m_pin12.setup("Pin 12", 0, 0, 255));
    
    m_oArdServer.setup();
    /*
    ard.connect("/dev/tty.usbmodem1411");

    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
	*/
}

void ofApp::setupArduino(const int & version){
    ofLogVerbose() << "init done";
}

//--------------------------------------------------------------
void ofApp::update(){
    m_oArdClient.addPwmSignal(2, m_pin01);
    m_oArdClient.addPwmSignal(3, m_pin02);
    m_oArdClient.addPwmSignal(4, m_pin03);
    m_oArdClient.addPwmSignal(5, m_pin04);
    m_oArdClient.addPwmSignal(6, m_pin05);
    m_oArdClient.addPwmSignal(7, m_pin06);
    m_oArdClient.addPwmSignal(8, m_pin07);
    m_oArdClient.addPwmSignal(9, m_pin08);
    m_oArdClient.addPwmSignal(10, m_pin09);
    m_oArdClient.addPwmSignal(11, m_pin10);
    m_oArdClient.addPwmSignal(12, m_pin11);
    m_oArdClient.addPwmSignal(13, m_pin12);
    
    m_oArdServer.update();
    
    //ard.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    m_pnPanel.draw();
    m_pnPinValues.draw();
    
    if(!m_oArdServer.isOK()){
        ofSetColor(ofColor::red);
        ofDrawBitmapString("Arduino not set", ofPoint(10, ofGetHeight() - 25));
    }else{
        ofSetColor(ofColor::greenYellow);
        ofDrawBitmapString("Arduino set", ofPoint(10, ofGetHeight() - 25));
    }
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
