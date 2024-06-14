#pragma once
#include "options/LoggerOptions/LoggerOptions.h"
#include <memory>

/*
 * Definition of SVETBuilder.
 * Writed on 14.06.2024 21:29
 * By Lisoveliy
 */

/// @brief Builder for SVET Framework
class SVETBuilder
{
    friend class SVET;

private:
    LoggerOptions BuildLoggerOptions;

public:
    /// @brief Setup SVET using SVETBuilder
    /// @return Builder for setup
    static SVETBuilder *Setup();

    /// @brief Set Logger Parameters
    /// @param options Options of logging
    /// @return Builder for setup
    SVETBuilder *SetLogger(LoggerOptions options);
};