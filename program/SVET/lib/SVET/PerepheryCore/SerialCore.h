#pragma once

#include "Logger/SerialColor.h"

/*
 * Definition of SerialCore.
 * Writed on 15.06.2024 14:11
 * By Lisoveliy
 */

namespace SerialCore
{
    void Start(short baudRate);
    void Stop();
    void SendLine(char *data);
    void SendLine(const char *data);
    void SetColor(SerialColor color);
    const char *GetEscapeColor(SerialColor color);
};

/*
 * Implementation of SerialCore.
 * Writed on 15.06.2024 14:12
 * By Lisoveliy
 */

void SerialCore::Start(short baudRate)
{
    Serial.begin(baudRate);
}

void SerialCore::Stop()
{
    Serial.end();
}

void SerialCore::SendLine(char *data)
{
    Serial.println(data);
}
void SerialCore::SendLine(const char *data)
{
    Serial.println(data);
}

void SerialCore::SetColor(SerialColor color)
{
    Serial.write(27);
    Serial.print(GetEscapeColor(color)); // White color
}

const char *SerialCore::GetEscapeColor(SerialColor color)
{
    switch (color)
    {
    case SerialColor::WHITE:
        return "[37m";
    case SerialColor::ORANGE:
        return "[33m";
    case SerialColor::RED:
        return "[31m";
    default:
        return "";
    }
}