#pragma once

#include <string>
#include "SerialColor.h"
#include "MessageType.h"
/*
 * Definition of Logger instance.
 * Writed on 14.06.2024 21:11
 * By Lisoveliy
 */

/// @brief Logger instance for messages on Serial port
class Logger
{
private:
    const MessageType CoreLogLevel;
    const MessageType UserLogLevel;
    const bool UseColor;

    const char *messageTypeToString(MessageType messageType);
    std::string getMessage(MessageType messageType, char *text, char *initiator);
    void sendMessage(char *output, SerialColor color);
    void sendMessage(const char *output, SerialColor color);

public:
    /// @brief Create instance of logger
    /// @param baudRate Speed of Serial port
    /// @param coreLogLevel LogLevel for Core (if userLogLevel and coreLogLevel equals NONE, the serial connection will not start)
    /// @param userLogLevel LogLevel for user (if userLogLevel and coreLogLevel equals NONE, the serial connection will not start)
    /// @param useColor Send messages with color ESCapes on serial monitor
    Logger(short baudRate, MessageType coreLogLevel, MessageType userLogLevel, bool useColor);
    ~Logger();
    /// @brief Log information
    /// @param data Message. Example: "Hello world!"
    /// @param initiator Name of initiator. Example: "main.cpp"
    void Info(char *data, char *initiator = nullptr);

    /// @brief Log Warning
    /// @param data Message. Example: "Some happened"
    /// @param initiator Name of initiator. Example: "main.cpp"
    void Warn(char *data, char *initiator = nullptr);

    /// @brief Log Error
    /// @param data Message. Example: "Error occured"
    /// @param initiator Name of initiator. Example: "main.cpp"
    void Error(char *data, char *initiator = nullptr);
};