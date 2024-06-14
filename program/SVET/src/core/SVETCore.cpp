#include "SVETCore.h"

/// @brief Method for run SVET Core (Must be placed on start() in main.cpp or main.ino)
/// @return true is start was successful or false if not
bool SVETCore::Start(){
    logger->Log("SVET Core is starting...");
    return true;
}
/// @brief Method for update SVET Core (Must be placed on loop() in main.cpp or main.ino)
void SVETCore::Loop(){
}

/// @brief Creating new instance of SVETCore. Can be the only one on the project
SVETCore::SVETCore(){
    logger = new Debug();
}

/// @brief Creating new instance of SVETCore. Can be the only one on the project
/// @param showDebugInfo Turn on or off debug info from SVETCore (Debug instance will still work)
/// @param baudRate Speed of serial port for Debug instance
SVETCore::SVETCore(bool showDebugInfo, short baudRate = 9600) : SVETCore(){
    this->showDebugInfo = showDebugInfo;
}