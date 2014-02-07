#ifndef ofxMyArduino_H
#define ofxMyArduino_H

#define PIN_NR_MAX        16
#define PIN_NO_PWM        -1

#define SETTINGS_SECTION_Connection "Connection"

#include "ofMain.h"
#include "ofxXmlSettings.h"

#define addonName "ofxMyArduino"

// On est à minima pour l'encapsulation de ofArduino
// Plus Tard , on verra
class ofxMyArduinoCommon{
     public:
       ofxMyArduinoCommon();
        virtual ~ofxMyArduinoCommon();
        void        setup();

    public:
        static      int             getNextPinNr();

        static  int                 m_nextPinNr;
        static  map<int,int>        m_pwm;
        static  ofArduino           m_arduino;
        static  bool                m_isSetupDone;
    
    /*
    private:
        // Settings -----------------------------------------------------------
        ofxXmlSettings m_oXML;

        // Settings -----------------------------------------------------------
        void loadSettings(string m_settingsFile = "ofxMyArduino.xml");
        void saveSettings(string m_settingsFile = "ofxMyArduino.xml");
     */
    
public:
    void loadParameters();
    int  getPxPinMini(){return m_pxPinMini.get();};
    int  getPxPinMaxi(){return m_pxPinMaxi.get();};
    
public:
    ofParameterGroup m_gpArduino;
private:
    ofParameter<string> m_pxDevicePort;
    ofParameter<int>    m_pxPinMini;
    ofParameter<int>    m_pxPinMaxi;

protected:
        //SETINGS - A mettre en XML
//        string mx_sDevicePort;
//        bool mx_bVerbose;

    public:
        string sDevicePort(){return m_pxDevicePort;};


};

class ofxMyArduinoClient: public ofxMyArduinoCommon{

    public:
        ofxMyArduinoClient();
        virtual ~ofxMyArduinoClient();
    // METHODS ---------------------------------
    public:
        void addPwmSignal(int _pinNr, int _value);
        int getAPinNumber();

    protected:
        int                 m_pinNr;

};

class ofxMyArduinoServer: public ofxMyArduinoCommon{

    public:
        ofxMyArduinoServer();
        virtual ~ofxMyArduinoServer();

    // METHODS ---------------------------------
    public:
        void        update();
        bool     controls();
        void sendPwm(int _pinNr, int _value);

};


#endif // ofxMyArduino_H
