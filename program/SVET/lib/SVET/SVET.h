#pragma once
#include "SVETBuilder/SVETBuilder.h"
#include "Logger/Logger.h"
#include <memory>

/*
 * Definition of SVET.
 * Writed on 14.06.2024 21:56
 * By Lisoveliy
 */

class SVET
{
    /// @brief Builder for SVET, exists only on start
    SVETBuilder *Builder;

public:
    std::unique_ptr<Logger> SLogger;
    /// @brief Method that must be included to setup() on main.cpp
    /// @return true if SVET was started
    bool Start();
    /// @brief Method that must be included to loop() on main.cpp
    void Loop();
    /// @brief Create new instance of SVET
    /// @param builder Builder of SVET
    SVET(SVETBuilder *builder);
};