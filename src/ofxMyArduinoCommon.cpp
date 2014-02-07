#include "ofxMyArduino.h"


// Init des membres statiques
map<int,int>    ofxMyArduinoCommon::m_pwm;
int             ofxMyArduinoCommon::m_nextPinNr = 0;
ofArduino       ofxMyArduinoCommon::m_arduino;
bool            ofxMyArduinoCommon::m_isSetupDone;

ofxMyArduinoCommon::ofxMyArduinoCommon(){
    //loadSettings();
    loadParameters();
}

ofxMyArduinoCommon::~ofxMyArduinoCommon(){
    //saveSettings();
}

void ofxMyArduinoCommon::setup(){
    string msg="";
    int iPinNr;

    if(m_isSetupDone==false){
        if(m_arduino.connect(m_pxDevicePort)){
                ofLogNotice() << "Connect on " << m_pxDevicePort;

            for(iPinNr=getPxPinMini(); iPinNr<=getPxPinMaxi(); iPinNr++){
                m_pwm.insert(pair<int, int>(iPinNr, 0));
                // SET ALL PWM needed to PWM_MODE :)
                m_arduino.sendDigitalPinMode(iPinNr,ARD_PWM);
                // SET ALL PWM needed to PWM_MODE :)
                m_arduino.sendPwm(iPinNr,0);
                // Message
                msg = "Init Arduino : Pin: "+ofToString(iPinNr)+" MODE: "+ofToString(ARD_PWM)+" VALUE: 0";
                ofLogNotice() << (msg);

            }

            // Setup is ok
            m_isSetupDone = true;
        }else{
            ofLogNotice() << "No Connect on : " << m_pxDevicePort;
        }
    }
}

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
    m_gpArduino.add(m_pxPinMini.set("PinMini", 2, 2, 12));
    m_gpArduino.add(m_pxPinMaxi.set("PinMaxi", 12, 2, 12));
}

/*
// -------------------------------------------------------------------------------------------
void ofxMyArduinoCommon::loadSettings(string _settingsFile){

    if(!m_oXML.loadFile(_settingsFile))
        cout << "[" << addonName << "]" << " : " << "Unable to open before Reading : " << _settingsFile << endl;

        // we can load even if the file is not open, because there's somme default values
        // SECTION = Audio Reac ----------------------------------------
        m_oXML.pushTag(SETTINGS_SECTION_Connection);
        // --
        mx_sDevicePort  = m_oXML.getValue("DevicePort", "COM1");
        mx_bVerbose = m_oXML.getValue("VerboseOn", false);
         // --
        m_oXML.popTag();

}

// -------------------------------------------------------------------------------------------
void ofxMyArduinoCommon::saveSettings(string _settingsFile){

    if(!m_oXML.loadFile(_settingsFile))
        cout << "[" << addonName << "]" << " : " << "Unable to open before Writing : " << _settingsFile << endl;

        // we can load even if the file is not open, because there's somme default values
        // SAVE THE Audio Reac Section ----------------------------------------
        if(!m_oXML.pushTag(SETTINGS_SECTION_Connection)) {
            m_oXML.addTag(SETTINGS_SECTION_Connection);
            m_oXML.pushTag(SETTINGS_SECTION_Connection);
        }
        // --
        m_oXML.setValue("DevicePort",   mx_sDevicePort);
        m_oXML.setValue("VerboseOn",    mx_bVerbose);
        // --
        m_oXML.popTag();

        // Ecrit le fichier ------------
        m_oXML.saveFile(_settingsFile);

}
*/
