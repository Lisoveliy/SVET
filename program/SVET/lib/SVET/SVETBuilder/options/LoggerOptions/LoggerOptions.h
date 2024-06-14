#pragma once
#include <Logger/Logger.h>

/*
 * Definition of Logger Options.
 * Writed on 14.06.2024 21:21
 * By Lisoveliy
 */

/// @brief Logger Options
class LoggerOptions
{
public:
    MessageType CoreLoggerLevel;
    MessageType UserLoggerLevel;
    bool UseColor;
    short BaudRate;
    /// @brief Setup Logger Options
    /// @param coreLoggerLevel Level of core logging
    /// @param userLoggerLevel Level of user logging
    /// @param useColor Use color on serial monitor
    /// @param baudRate Speed of serial port
    LoggerOptions(
        MessageType coreLoggerLevel = INFO,
        MessageType userLoggerLevel = INFO,
        bool useColor = false,
        short baudRate = 19200);
    LoggerOptions(LoggerOptions &) = delete;
};