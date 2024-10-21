#pragma once

class FlashMapping{
    public:
    char* key;
    short size;

    FlashMapping(char* key, short size){
        this->key = key;
        this->size = size;
    }
};