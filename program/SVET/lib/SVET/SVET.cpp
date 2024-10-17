#include "SVET.h"
/*
 * Implementation of SVET. Docs in SVET.h
 * Writed on 14.06.2024 21:56
 * By Lisoveliy
 */

SVET::SVET(SVETBuilder *builder)
{
    this->Builder = builder;
}

bool SVET::Start()
{
    // Setup logger
    auto loggerOptions = &Builder->BuildLoggerOptions;
    this->MLogger = std::make_unique<Logger>(loggerOptions->BaudRate,
                                             loggerOptions->CoreLoggerLevel,
                                             loggerOptions->UserLoggerLevel,
                                             loggerOptions->UseColor);

    delete this->Builder; // nullptr to Builder
    this->Builder = nullptr;
    return true;
}
void SVET::Loop()
{
}