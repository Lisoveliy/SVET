#include <Arduino.h>
#include "Logger.h"

/*
 * Implementation of Logger instance. Docs on Logger.h
 * Writed on 14.06.2024 21:11
 * By Lisoveliy
 */

Logger::Logger(
    short baudRate,
    MessageType coreLogLevel,
    MessageType userLogLevel,
    bool useColor) : CoreLogLevel{coreLogLevel}, UserLogLevel{userLogLevel}, UseColor{useColor}
{
    if (coreLogLevel == NONE && userLogLevel == NONE)
    {
        return;
    }
    Serial.begin(baudRate);
}

Logger::~Logger()
{
    Serial.end();
}

const char *Logger::messageTypeToString(MessageType messageType)
{
    switch (messageType)
    {
    case MessageType::INFO:
        return "INFO";
    case MessageType::WARN:
        return "WARN";
    case MessageType::ERROR:
        return "ERROR";
    case MessageType::NONE:
    default:
        return "";
    }
}

std::string Logger::getMessage(MessageType messageType, char *text, char *initiator)
{
    std::string output;
    output += "[";
    output += messageTypeToString(messageType);
    output += "]";
    if (initiator != nullptr)
    {
        output += ' ';
        output += initiator;
    }
    output += ": ";
    output += text;
    return output;
}

void Logger::Info(char *data, char *initiator)
{
    // TODO: check core and user level
    if (UseColor)
    {
        Serial.write(27);
        Serial.print("[37m"); // White color
    }
    Serial.println(getMessage(MessageType::INFO, data, initiator).c_str());
    if (UseColor)
    {
        Serial.write(27);
        Serial.print("[37m");
    }
}

void Logger::Warn(char *data, char *initiator)
{
    // TODO: check core and user level
    if (UseColor)
    {
        Serial.write(27);
        Serial.print("[33m"); // Orange color
    }
    Serial.println(getMessage(MessageType::WARN, data, initiator).c_str());
    if (UseColor)
    {
        Serial.write(27);
        Serial.print("[37m");
    }
}

void Logger::Error(char *data, char *initiator)
{
    // TODO: check core and user level
    if (UseColor)
    {
        Serial.write(27);
        Serial.print("[31m"); // Red color
    }
    Serial.println(getMessage(MessageType::ERROR, data, initiator).c_str());
    if (UseColor)
    {
        Serial.write(27);
        Serial.print("[37m");
    }
}