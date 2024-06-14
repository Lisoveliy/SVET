#include "Debug.h"
#include <string>
#include <Arduino.h>
/// @brief Creating new instance of a debug logger (Using HardwareSerial class) Can be the only one on the project
/// @param baudRate Speed of serial port
Debug::Debug(short baudRate = 9600, bool isCoreDebugAllowed = true){
    this->isCoreDebugAllowed = isCoreDebugAllowed;
    if(!Serial)
        Serial.begin(baudRate);
}
Debug::~Debug(){
    if(Serial)
        Serial.end();
}
char* Debug::messageTypeToString(MessageType messageType){
    switch (messageType)
    {
    case MessageType::LOG:
        return "LOG";
    case MessageType::WARN:
        return "WARN";
    case MessageType::ERROR:
        return "ERROR";
    }
}
const char* Debug::getMessage(MessageType messageType, char* text){
    std::string output;
    output.append("[");
    output.append(messageTypeToString(messageType));
    output.append("]: ");
    output.append(text);
    return output.c_str();
}
void Debug::Log(char* text){
    Serial.write(27);
    Serial.print("[37;40m");
    Serial.println(getMessage(MessageType::LOG, text));
}
void Debug::Warn(char* text){
    Serial.write(27);
    Serial.print("[33;40m");
    Serial.println(getMessage(MessageType::WARN, text));
}
void Debug::Error(char* text){
    Serial.write(27);
    Serial.print("[31;40m");
    Serial.println(getMessage(MessageType::ERROR, text));
}

void Debug::CoreLog(char* text){
    if(!isCoreDebugAllowed)
        return;
    Serial.write(27);
    Serial.print("[37;40m CORE:");
    Serial.println(getMessage(MessageType::LOG, text));
}
void Debug::CoreWarn(char* text){
    if(!isCoreDebugAllowed)
        return;
    Serial.write(27);
    Serial.print("[33;40m CORE:");
    Serial.println(getMessage(MessageType::WARN, text));
}
void Debug::CoreError(char* text){
    if(!isCoreDebugAllowed)
        return;
    Serial.write(27);
    Serial.print("[31;40m CORE:");
    Serial.println(getMessage(MessageType::ERROR, text));
}