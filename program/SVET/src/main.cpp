#include <Arduino.h>
#include <memory>
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
  delay(1000);
  logger->Info("Hello INFO", "main.cpp");
  logger->Warn("Hello WARN", "main.cpp");
  logger->Error("Hello ERROR", "main.cpp");
  svet->Loop();
}