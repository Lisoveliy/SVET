#include "ServiceLogger.h"
#include "Logger.h"
/*
 * Implementation of Service Logger instance. Docs on ServiceLogger.h
 * Writed on 17.10.2024 16:41
 * By Lisoveliy
 */

ServiceLogger::ServiceLogger(Logger *logger, char *initiator)
{
    this->initiator = initiator;
    this->mLogger = logger;
}

void ServiceLogger::Info(char *data)
{
    this->mLogger->Info(data, initiator);
}

void ServiceLogger::Warn(char *data)
{
    this->mLogger->Warn(data, initiator);
}

void ServiceLogger::Error(char *data)
{
    this->mLogger->Error(data, initiator);
}