#include "string.h"

int get_str_length(const char* str) {
    int str_len = 0;
    while (*(str++)!='\0')
    {
        str_len++;
    }
    return str_len;
}

int numPlaces (int n) {
    if (n < 0) n = -n;
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
    return 10;
}

String:: String(char* text) {
    int str_len = get_str_length(text);
    length = str_len;
    data = (char*)malloc((sizeof(char) * (str_len + 1)));
    if(data!=nullptr) {
        for(int i=0; i<str_len; i++) {
            data[i] = text[i];
        }
        data[str_len] = '\0';
    }
    else {
        data = nullptr;
    } 
}

String::  String(int number){
    int i = 0;
    bool negative = false;
    int str_len = numPlaces(number);
    if(number < 0) {
        negative = true;
        number = -number;
        str_len++;
    }
    data = (char*)malloc((sizeof(char) * (str_len + 1)));
    if(data) {
         length = str_len; /*set length*/
         int i = str_len - 1;
         if(negative) {
            data[0] = '-';
         }
         do {
              data[i--] = (number % 10) + '0';  
              number /= 10; 
         } while (number != 0);

         data[str_len] ='\0';
    }
    else {
        /*error handling*/
    }
}

String& String::operator=(const char* text) {
    int str_len = get_str_length(text);
    this->length = str_len;
    free(this->data);
    this->data = (char*)malloc((sizeof(char) * (str_len + 1)));
    if(data!=nullptr) {
        for(int i=0; i<str_len; i++) {
            data[i] = text[i];
        }
        data[str_len] = '\0';
    }
    return *this;
}

String& String::operator+(const char* text) {
    int str_len = get_str_length(text);
    int my_len = this->length;
    char* new_data = (char*)malloc((sizeof(char) * (str_len + my_len + 1)));
    if(new_data != nullptr) {
        for(int i=0; i< my_len; i++) {
            new_data[i] = this->data[i];
        }
        for (int i = 0; i < str_len; i++)
        {
            new_data[my_len+i] = text[i];
        }
        int new_len = my_len + str_len;
        new_data[new_len] = '\0';
        this->length = new_len;
        free(this->data);
        this->data = new_data;
    }
    return *this;
}

const char* String::getData() {
        return data;
}

int String::getLength() {
    return length;
}