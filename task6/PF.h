#pragma once

#ifdef PF_EXPORT
#  define EXPORT __declspec(dllexport)
#else
#  define EXPORT __declspec(dllimport)
#endif

class EXPORT PF
{
	int N = 0;
	int *pv = 0;
public:
    PF() {};
    EXPORT PF(const PF&p);
    EXPORT ~PF();

    PF&operator = (const PF&) = delete;

    EXPORT operator int() const;
    EXPORT int operator [](int i) const;
	// Инициализирует префикс-функцию строкой s
    EXPORT void Init(const char *s, int sz);
};

