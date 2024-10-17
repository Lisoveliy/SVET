#include <Arduino.h>
#include "Logger.h"
#include "PerepheryCore/SerialCore.h"

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
    SerialCore::Start(baudRate);
}

Logger::~Logger()
{
    SerialCore::Stop();
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

void Logger::sendMessage(char *data, SerialColor color)
{
    SerialCore::SetColor(color);
    SerialCore::SendLine(data);
    SerialCore::SetColor(WHITE);
}

void Logger::sendMessage(const char *data, SerialColor color)
{
    SerialCore::SetColor(color);
    SerialCore::SendLine(data);
    SerialCore::SetColor(WHITE);
}

void Logger::Info(char *data, char *initiator)
{
    sendMessage(getMessage(MessageType::INFO, data, initiator).c_str(), WHITE);
}

void Logger::Warn(char *data, char *initiator)
{
    sendMessage(getMessage(MessageType::WARN, data, initiator).c_str(), ORANGE);
}

void Logger::Error(char *data, char *initiator)
{
    sendMessage(getMessage(MessageType::ERROR, data, initiator).c_str(), RED);
}

std::unique_ptr<ServiceLogger> Logger::GetServiceLogger(char *initiator){
    return std::make_unique<ServiceLogger>(ServiceLogger(this, initiator));
}