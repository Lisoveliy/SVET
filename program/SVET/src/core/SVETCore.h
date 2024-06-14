#include "debug/Debug.h"

class SVETCore{
    bool showDebugInfo{true};
public:
    Debug* logger;
    bool Start();
    void Loop();
    SVETCore();
    SVETCore(bool showDebugInfo, short baudRate = 9600);
};