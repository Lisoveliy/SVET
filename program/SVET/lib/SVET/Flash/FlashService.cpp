#include "FlashService.h"
#include <EEPROM.h>

/*
 * Implementation of Flash service. Docs on header file.
 * Writed on 21.10.2024 17:11
 * By Lisoveliy
 */

FlashService::FlashService(int allocSize)
{
    EEPROM.begin(allocSize);
}

bool FlashService::WriteData(char *key, void *object, size_t size)
{
    try
    {
        flashMap.insert(flashHashMap::value_type(FlashMapping(key, size), this->addressPointer));
        EEPROM.put(addressPointer, object);
        addressPointer += size;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool FlashService::WriteData(char *key, char data)
{
    try
    {
        flashMap.insert(flashHashMap::value_type(FlashMapping(key, 1), this->addressPointer));
        EEPROM.write(addressPointer, data);
        addressPointer++;
        return true;
    }
    catch (...)
    {
        return false;
    }
}