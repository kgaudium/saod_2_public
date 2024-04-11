//
// Created by Gaudium on 11.04.2024.
//

#ifndef SAOD_2_STR_H
#define SAOD_2_STR_H
#include <cstring>
#include "_str.h"


class Str {
    _str* m_pStr;
public:
    Str () {m_pStr = new _str;}		//если не копия, то создаем

    Str (const char* p) {		// новый ресурс
        m_pStr = new _str(p);
    }

    // Copy constructor
    Str (const Str &s)
    {
        m_pStr = s.m_pStr; 	// ссылаемся на тот же ресурс
        m_pStr->AddRef(); 	// отмечаем, что сослались
    }

    Str & operator = (const Str &s){
        if(this != &s){
            s.m_pStr -> AddRef(); // Важен порядок?!
            m_pStr -> Release();
            m_pStr = s.m_pStr;
        }
        return *this;
    }

    Str & operator += (const Str &s){
        int length = len() + s.len();
        if (s.len() != 0) {		// добавление ничего не изменит!
            _str *pstrTmp = new _str; 	// Новый ресурс
            delete [] pstrTmp->m_pszData;

            pstrTmp->m_pszData = new char [length + 1];
            strcpy_s(pstrTmp->m_pszData, length + 1 , m_pStr->m_pszData);
            strcat_s(pstrTmp->m_pszData, length + 1 , s.m_pStr->m_pszData);

            m_pStr->Release();
            m_pStr = pstrTmp;
        }
        return *this;
    }

    operator const char*() const{
        return m_pStr->m_pszData;
    }

    ~ Str () {
        m_pStr -> Release(); 	// Не уничтожаем ресурс!
    }				// Уменьшаем счетчик ссылок!

    [[nodiscard]] int len() const {
        return strlen(m_pStr->m_pszData);
    }


    int rfind(const char* t, int off) const{
        int subLen = strlen(t);
        const char* text = m_pStr->m_pszData;

        if (off > len()) off = len()-1;

        for (int i = off-subLen+1; i>=0; i--){
            if (text[i] == t[0]){
//                int tempResult = i;
                bool resultFound = true;

                for (int j = i+1; j<i+subLen; j++){
                    if (text[j] != t[j-i]) {
                        resultFound = false;
                        break;
                    }
                }

                if (resultFound){
                    return i;
                }

            }
        }

        return -1;
    }
};

#endif //SAOD_2_STR_H
