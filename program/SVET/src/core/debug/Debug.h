enum MessageType{
    LOG,
    WARN,
    ERROR
};

class Debug{
private:
    bool isCoreDebugAllowed{true};
    char* messageTypeToString(MessageType messageType);
    const char* getMessage(MessageType messageType, char* text);
public:
    void Log(char* text);
    void Warn(char* text);
    void Error(char* text);
    
    void CoreLog(char* text);
    void CoreWarn(char* text);
    void CoreError(char* text);
    Debug(short baudRate = 9600, bool isCoreDebugAllowed = true);
    ~Debug();
};