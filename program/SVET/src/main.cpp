#include <Arduino.h>
#include <memory>
#include "SVET.h"
#include "Logger/ServiceLogger.h"

std::unique_ptr<SVET> svet;
std::unique_ptr<ServiceLogger> logger;
int counter = 0;
void setup()
{
  auto builder = SVETBuilder::Setup()->SetLogger(LoggerOptions());
  svet = std::make_unique<SVET>(SVET(builder));
  svet->Start();
  logger = svet->MLogger->GetServiceLogger("main.cpp");
}

void loop()
{
  delay(500);
  auto strCounter = std::to_string(counter).c_str();
  logger->Warn((char*)strCounter);
  counter++;
  svet->Loop();
}