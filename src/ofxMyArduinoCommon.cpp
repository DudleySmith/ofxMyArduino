#include "ofxMyArduino.h"


// Init des membres statiques
map<int,int>    ofxMyArduinoCommon::m_pwm;
int             ofxMyArduinoCommon::m_nextPinNr = 0;

ofxMyArduinoCommon::ofxMyArduinoCommon(){
    //loadSettings();
    loadParameters();
}

ofxMyArduinoCommon::~ofxMyArduinoCommon(){
    //saveSettings();
}

// ------------------------------------------------------------------------------------------
int ofxMyArduinoCommon::getNextPinNr(){

    if(m_nextPinNr < PIN_NR_MAX){
        return ofxMyArduinoCommon::m_nextPinNr++;
   }else{
        return -1;
   }

};

// ------------------------------------------------------------------------------------------
void ofxMyArduinoCommon::loadParameters(){
    m_gpArduino.add(m_pxDevicePort.set("DevicePort", "tty.usbmodem1411"));
    m_gpArduino.add(m_pxPinMini.set("PinMini", 0, 0, 16));
    m_gpArduino.add(m_pxPinMaxi.set("PinMaxi", 13, 0, 16));
}
