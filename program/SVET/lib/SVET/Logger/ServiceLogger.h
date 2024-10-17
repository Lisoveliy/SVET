#pragma once

#include <memory>
class Logger;

/*
 * Definition of ServiceLogger instance.
 * Writed on 17.10.2024 16:41
 * By Lisoveliy
 */

class ServiceLogger
{
    char *initiator;
    Logger *mLogger;

public:
    /// @brief Create ServiceLogger instance
    /// @param initiator name of service
    ServiceLogger(Logger *logger, char *initiator = nullptr);
    /// @brief Log information
    /// @param data Message. Example: "Hello world!"
    void Info(char *data);

    /// @brief Log Warning
    /// @param data Message. Example: "Some happened"
    void Warn(char *data);

    /// @brief Log Error
    /// @param data Message. Example: "Error occured"
    void Error(char *data);
};