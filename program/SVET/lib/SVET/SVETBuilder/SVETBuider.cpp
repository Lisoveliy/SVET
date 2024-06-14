#include "SVETBuilder.h"

/*
 * Implementation of SVETBuilder. Docs in SVETBuilder.h
 * Writed on 14.06.2024 21:29
 * By Lisoveliy
 */

SVETBuilder *SVETBuilder::Setup()
{
    return new SVETBuilder();
}

SVETBuilder *SVETBuilder::SetLogger(LoggerOptions options)
{
    this->BuildLoggerOptions = options;
    return this;
}