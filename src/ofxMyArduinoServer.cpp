#include "ofxMyArduino.h"

ofxMyArduinoServer::ofxMyArduinoServer(){
}

ofxMyArduinoServer::~ofxMyArduinoServer(){
    if(m_isSetupDone==true){
        map<int,int>::iterator     onePwm;

        for(onePwm=m_pwm.begin(); onePwm!=m_pwm.end(); onePwm++){
            sendPwm((*onePwm).first, 0);
        }

        m_arduino.disconnect();
    }
}


void ofxMyArduinoServer::update(){

    map<int,int>::iterator     onePwm;

    for(onePwm=m_pwm.begin(); onePwm!=m_pwm.end(); onePwm++){
        sendPwm((*onePwm).first, (*onePwm).second);
    }

   if(controls()){
       m_arduino.update();
   }

}

void ofxMyArduinoServer::sendPwm(int _pinNr, int _value){
    // On envoie
    if(controls()){
        // Sending
        m_arduino.sendPwm(_pinNr, _value);
        // Verbosing
        ofLogVerbose() << "Sending  : " << "Pin Nr=" <<ofToString(_pinNr) << " : " << "Value=" << ofToString(_value);
    }
}

bool ofxMyArduinoServer::controls(){
    // Fait les controles / En cas d'erreurs, met une trace dans la console
    if (!m_arduino.isArduinoReady()) {
        ofLogWarning("Arduino") << "Not ready";
        return false;
    }
    
    // 2 : Is setup ok ?
    if(m_isSetupDone == false){
        ofLogWarning("Arduino") << "No Setup Done";
        return false;
    }

    // NO STOP -> OK
    return true;

}

