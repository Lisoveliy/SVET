#include <Arduino.h>
#include <memory>
#include "core/SVETCore.h"

std::unique_ptr<SVETCore> core;
void setup() {
  bool isStarted{false};
  do{
    isStarted = core->Start();
  }while (!isStarted);
}

void loop() {
  core->Loop();
}