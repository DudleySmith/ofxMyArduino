#include "ofxMyArduino.h"

ofxMyArduinoServer::ofxMyArduinoServer(){
}

ofxMyArduinoServer::~ofxMyArduinoServer(){
    if(m_bSetupDone==true){
        map<int,int>::iterator     onePwm;

        for(onePwm=m_pwm.begin(); onePwm!=m_pwm.end(); onePwm++){
            sendPwm((*onePwm).first, 0);
        }

        m_oArduino.disconnect();
    }
}

void ofxMyArduinoServer::setup(){
    
    // replace the string below with the serial port for your Arduino board
    // you can get this from the Arduino application or via command line
    // for OSX, in your terminal type "ls /dev/tty.*" to get a list of serial devices
    m_oArduino.connect(getPxDevicePort(), 57600);
	
	// listen for EInitialized notification. this indicates that
	// the arduino is ready to receive commands and it is safe to
	// call setupArduino()
	ofAddListener(m_oArduino.EInitialized, this, &ofxMyArduinoServer::setupArduino);
	m_bSetupDone	= false;	// flag so we setup arduino when its ready, you don't need to touch this :)
    
}

//--------------------------------------------------------------
void ofxMyArduinoServer::setupArduino(const int & version) {
	
	// remove listener because we don't need it anymore
	ofRemoveListener(m_oArduino.EInitialized, this, &ofxMyArduinoServer::setupArduino);
    
    // it is now safe to send commands to the Arduino
    m_bSetupDone = true;
    
    // print firmware name and version to the console
    ofLogNotice() << m_oArduino.getFirmwareName();
    ofLogNotice() << "firmata v" << m_oArduino.getMajorFirmwareVersion() << "." << m_oArduino.getMinorFirmwareVersion();
    
    for(int iPinNr=getPxPinMini(); iPinNr<=getPxPinMaxi(); iPinNr++){
        m_pwm.insert(pair<int, int>(iPinNr, 0));
        // SET ALL PWM needed to PWM_MODE :)
        m_oArduino.sendDigitalPinMode(iPinNr,ARD_PWM);
        // SET ALL PWM needed to PWM_MODE :)
        m_oArduino.sendPwm(iPinNr,0);
        // Message
        ofLogNotice() << "Init Arduino : Pin: " << ofToString(iPinNr) << " MODE: " << ofToString(ARD_PWM)+" VALUE: 0";
    }
    
    // Listen for changes on the digital and analog pins
    ofAddListener(m_oArduino.EDigitalPinChanged, this, &ofxMyArduinoServer::digitalPinChanged);
    ofAddListener(m_oArduino.EAnalogPinChanged, this, &ofxMyArduinoServer::analogPinChanged);
}

// ----------------------------------------------------------------------
void ofxMyArduinoServer::update(){
    
    // Don't swap this update, it's useful to know about connection
    m_oArduino.update();
    
    map<int,int>::iterator     onePwm;
    for(onePwm=m_pwm.begin(); onePwm!=m_pwm.end(); onePwm++){
        sendPwm((*onePwm).first, (*onePwm).second);
    }

}

void ofxMyArduinoServer::sendPwm(int _pinNr, int _value){
    // On envoie --
    if(controls()){
        // Sending
        m_oArduino.sendPwm(_pinNr, _value);
        // Verbosing
        ofLogVerbose() << "Sending  : " << "Pin Nr=" <<ofToString(_pinNr) << " : " << "Value=" << ofToString(_value);
    }
}

bool ofxMyArduinoServer::controls(){
    
    // Fait les controles / En cas d'erreurs, met une trace dans la console
    if (!m_oArduino.isArduinoReady()) {
        ofLogWarning("Arduino") << "Not ready";
        return false;
    }
    
    // 2 : Is setup ok ?
    if(m_bSetupDone == false){
        ofLogWarning("Arduino") << "No Setup Done";
        return false;
    }

    // NO STOP -> OK
    return true;

}

void ofxMyArduinoServer::digitalPinChanged(const int & pinNum){
    ofLogWarning() << "Not implemented Digital pin changed";
}

void ofxMyArduinoServer::analogPinChanged(const int & pinNum){
    ofLogWarning() << "Not implemented Analog pin changed";
}
