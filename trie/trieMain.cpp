//
// Created by Gaudium on 29.05.2024.
//

#include "Trie.h"
#include <iostream>
#include <chrono>
#include <fstream>

int main(){
    bool useEngWiki = true;

    if (useEngWiki) {
        std::string text;
        std::ifstream fin("engwiki_ascii.txt", std::ios::binary);
        if (!fin.is_open()) {
            std::cout << "not open!" << std::endl;
            return 0;
        }
        text.append((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
        std::cout << "Text was loaded" << std::endl;

        Trie trie = Trie();
        // Загружаем в trie
        auto time_one = std::chrono::high_resolution_clock::now();
        trie.Insert(text);
        auto time_two = std::chrono::high_resolution_clock::now();
        std::cout << "Text was loaded to trie for " << std::chrono::duration<double>(time_two - time_one).count() << std::endl
                  << std::endl;

        std::string word = "wiki"; // слово, которое ищем
        // Ищем слово (должно быть 491)
        time_one = std::chrono::high_resolution_clock::now();
        std::cout << trie.Find(word) << std::endl;
        time_two = std::chrono::high_resolution_clock::now();
        std::cout << "Trie\t" << std::chrono::duration<double>(time_two - time_one).count() << std::endl << std::endl;

        time_one = std::chrono::high_resolution_clock::now();
        std::cout << trie.Size() << std::endl;
        time_two = std::chrono::high_resolution_clock::now();
        std::cout << "Trie Size calculated for " << std::chrono::duration<double>(time_two - time_one).count() << std::endl;
    }
    else {
        Trie trie = Trie();
        trie.Insert("are they the most fun and these are fun");
    //    trie.Insert("brux");

//        std::cout << trie.Find("are") << std::endl;
//        std::cout << trie.Find("they") << std::endl;
//        std::cout << trie.Find("the") << std::endl;
//        std::cout << trie.Find("most") << std::endl;
//        std::cout << trie.Find("fun") << std::endl;
//        std::cout << trie.Find("and") << std::endl;
//        std::cout << trie.Find("these") << std::endl;
//        std::cout << trie.Find("a") << std::endl;

//        std::cout << trie.Size() << std::endl;

        std::cout << trie.SamePrefixCount("a") << std::endl;
    }
}