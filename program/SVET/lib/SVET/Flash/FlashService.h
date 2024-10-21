#pragma once
#include "FlashMapping.h"
#include <unordered_map>
/*
 * Definition of Flash service.
 * Writed on 21.10.2024 17:11
 * By Lisoveliy
 */
typedef std::unordered_map<FlashMapping, int> flashHashMap;
class FlashService{
    private:
    flashHashMap flashMap;
    int addressPointer = 0;

    public:
    /// @brief Flash Service constructor
    /// @param allocSize Size of Flash Allocation (in bytes) (default - 128kb)
    FlashService(int allocSize = 0x20000);

    /// @brief Write data object by key
    /// @param key string key for hash
    /// @param object any type of object casted to void*
    /// @return true on success, false on failure (IDKWhat kind of failure)
    bool WriteData(char* key, void* object, size_t size);

    /// @brief Write byte data by key
    /// @param key string key for hash
    /// @param data byte of data
    /// @return 
    bool WriteData(char* key, char data);

    /// @brief Update data object by key
    /// @param key 
    /// @param object 
    /// @return true on success, false on failure (for example not same size of object)
    bool UpdateData(char* key, void* object);

    /// @brief Remove data object by key
    /// @param key string key for hash
    /// @return true on success, false on failure (IDKWhat kind of failure)
    bool RemoveData(char* key);

    /// @brief Read data object by key
    /// @param key string key for hash
    /// @return data object
    void* ReadData(char* key);
};