#ifndef STRING_H
#define STRING_H
#include "malloc.h"
class String {
    char* data;
    int length;
public:
    String(char* text);
    String(int number);
    String& operator=(const char* text);
    String& operator+(const char* text);
    const char* getData();
    int getLength();
    ~String() {
        free(data);
    }
};  
#endif