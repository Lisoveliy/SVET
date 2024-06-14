#include <Arduino.h>
#include <memory>
#include "SVETBuilder/SVETBuilder.h"
#include "SVET.h"

std::unique_ptr<SVET> svet;
Logger *logger;
void setup()
{
  auto builder = SVETBuilder::Setup()->SetLogger(LoggerOptions());
  svet = std::make_unique<SVET>(SVET(builder));
  svet->Start();
  logger = svet->SLogger.get();
}

void loop()
{
  logger->Info("Hello", "main.cpp");
  logger->Warn("Warn asd", "main.cpp");
  logger->Error("Warferr", "main.cpp");
  delay(1000);
  svet->Loop();
}