#include "ofxMyArduino.h"

ofxMyArduinoClient::ofxMyArduinoClient(){
};

ofxMyArduinoClient::~ofxMyArduinoClient(){
};

void ofxMyArduinoClient::addPwmSignal(int _pinNr,int _value){

    if(_pinNr!=PIN_NO_PWM && _pinNr>=getPxPinMini() && _pinNr<=getPxPinMaxi()){
        // We can change
        m_pwm[_pinNr] = _value;
    }

}

int ofxMyArduinoClient::getAPinNumber(){
    m_pinNr = getNextPinNr();
    return m_pinNr;
}



