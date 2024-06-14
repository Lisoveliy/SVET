#include "LoggerOptions.h"

/*
 * Implementation of Logger Options. Docs on LoggerOptions.h
 * Writed on 14.06.2024 21:29
 * By Lisoveliy
 */

LoggerOptions::LoggerOptions(
    MessageType coreLoggerLevel,
    MessageType userLoggerLevel,
    bool useColor,
    short baudRate)
{
    this->CoreLoggerLevel = coreLoggerLevel;
    this->UserLoggerLevel = userLoggerLevel;
    this->UseColor = useColor;
    this->BaudRate = baudRate;
}