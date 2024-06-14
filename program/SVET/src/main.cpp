#include <Arduino.h>
#include <memory>

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