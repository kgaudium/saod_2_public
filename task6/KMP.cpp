// KMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KMP_StateMachine.h"

int main()
{
	char vCode[] = { static_cast<char>(0x88), 0x42, static_cast<char>(0xE0), 0x46,
                     static_cast<char>(0xEB), 0x27, 0x00, static_cast<char>(0xED), 0x3F,
                     static_cast<char>(0x8B), static_cast<char>(0xCE), static_cast<char>(0xE3), 0x12,
                     static_cast<char>(0x8D), 0x7E, static_cast<char>(0xE0) };
	// Здесь реализация. В stdafx уже включен ввод/вывод.


    KMP_StateMachine sm {vCode, 16};


	return 0;
}

