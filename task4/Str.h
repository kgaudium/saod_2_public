//
// Created by Gaudium on 22.02.2024.
//

#ifndef SAOD_2_STR_H
#define SAOD_2_STR_H
#include <cstring>
#include <iostream>

class Str {
public:
    char* _text;

    Str(){
        _text = new char[1]{0};
    }

    Str(const char* p){
        if(p){
            _text = new char [std::strlen(p) + 1];
            std::strcpy(_text, p);
        }
        else{
            _text = new char[1]{0};
        }
    }

    // Конструктор копирования
    Str(const Str& s){
//        std::cout << "copy " <<  std::endl;

        _text = new char[std::strlen(s._text)+1];

        std::strcpy(_text, s._text);
    }

    ~Str() {
        delete[] _text;
    }

    Str operator +(const char* other) const{
        size_t text_len = std::strlen(this->_text);
        size_t sz_len = std::strlen(other);

        char* new_text = new char[text_len + sz_len + 1]{};

        new_text[text_len + sz_len] = '\0';
        for (int i = 0; i<text_len; i++){
            new_text[i]=_text[i];
        }
        for (int i = 0; i<sz_len; i++){
            new_text[text_len + i]=other[i];
        }

        return new_text;
    }

    Str& operator +=(const char* other){
        size_t text_len = std::strlen(this->_text);
        size_t sz_len = std::strlen(other);

        char* new_text = new char[text_len + sz_len + 1]{};

        new_text[text_len + sz_len] = '\0';
        for (int i = 0; i<text_len; i++){
            new_text[i]=_text[i];
        }
        for (int i = 0; i<sz_len; i++){
            new_text[text_len + i]=other[i];
        }
        delete[] _text;                                     // нужно ли?
        this->_text = new char[text_len + sz_len + 1]{};
        std::strcpy(this->_text, new_text);

        return *this;
    }

    Str& operator = (const Str& other){

        if (&other != this){
            std::strcpy(_text, other._text);
        }

        return *this;
    };

    // Оператор каста
    operator const char*() const{
        return _text;
    }
};


#endif //SAOD_2_STR_H
