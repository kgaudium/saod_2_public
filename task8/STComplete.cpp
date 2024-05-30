// STComplete.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>  //Нужно для работы с файлами.
#include <list>
#include <string.h>
#include "SufTree.h"
#include <chrono>

/// <summary>
/// Строит случайную строку заполненную латинскими символами
/// </summary>
/// <param name="ab_size">размер алфавита</param>
/// <param name="len">длина строки</param>
/// <returns>случайную строку из латинских символов</returns>
string get_rnd_str(int ab_size, int len)
{
    string s(len,0);
    for (int i = 0; i < len; i++)
    {
        int rch = rand() % ab_size + 'a';
        s [i]= char(rch);
    }
    return s;
}


//#define FROM_FILE
int main()
{
#ifdef FROM_FILE
    cout << "Enter a file name (empty for 'rfc 1951.txt'): ";

    string fname;
    char fName[128]{0};
//    cin.getline(fName, sizeof(fName));
//
//    if (strlen(fName) == 0)
//        strcpy(fName, "rfc 1951.txt");
    cout << fName << endl;

    strcpy(fName, "1.txt");

    ifstream ifs(fName, ios_base::in | ios_base::binary);
    char input[128];

    streampos begin, end;
    begin = ifs.tellg();
    ifs.seekg(0, ios::end);
    end = ifs.tellg();
    cout << "size is: " << (end - begin) << " bytes.\n";
    ifs.seekg(0, ios::beg);

    char* inp = new char[end - begin];
    SufTree st(inp);
    auto start = chrono::steady_clock::now();

    int maxRemaind = 0, iMax = 0;
    char c = ifs.get();
    for (int i = 0; ifs.good(); i++) {
        inp[i] = c;
        st.extend(i);
        c = ifs.get();
    }
    st.finalize();
    auto stop = chrono::steady_clock::now();
    ifs.close();

    st.FillLeaves();    // Можно и без него, но не будут заполнены индексы суффиксов.
    st.FillPath();
    st.FillNodes();

//    st.ShowTree();

    st.PrintPalindromes(12);
    cout << st.MaxPalindromeLen() << endl;
    cout << endl << endl;

    cout << "Time difference = " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << "[ms]" << endl;
#else
    string s = get_rnd_str(2, 7);
    s += string(s.rbegin(), s.rend());
    cout << s << endl;
    auto start = chrono::steady_clock::now();

    SufTree st(s.c_str());
    for (int i = 0; i < s.length(); i++)
        st.extend(i);
    // и завершаем построение, делая все суффиксы явными!
    st.finalize();
    
    auto stop = chrono::steady_clock::now();

    st.FillLeaves();    // Можно и без него, но не будут заполнены индексы суффиксов.
    st.FillPath();
    st.FillNodes();

    st.ShowTree();
    st.PrintPalindromes(4);
    cout << st.MaxPalindromeLen() << endl;
    cout << endl << endl;
    cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << "[mks]" << endl;

#endif

}
