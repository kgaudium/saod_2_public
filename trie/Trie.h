//
// Created by Gaudium on 29.05.2024.
//

#ifndef SAOD_2_TRIE_H
#define SAOD_2_TRIE_H

#include <iostream>
#include <string>
#include "TrieNode.h"

class Trie {
private:
    TrieNode root;

public:
    Trie() : root('\0', true){    }

//    ~Trie() {
//        root.~TrieNode();
//    }

    Trie(const std::string& text) : Trie() {
        Insert(text);
    }

     [[nodiscard]] size_t SamePrefixCount(const std::string& prefix) const{
        const TrieNode* tempNode = &root;
        for (auto it = prefix.begin(); it != prefix.end(); it++){
            if (!tempNode->IsHaveChild(*it)){
                throw std::invalid_argument("No such prefix: " + prefix);
            }

            tempNode = tempNode->GetChildNode(*it);
        }

        return tempNode->GetChildsOccurrences();
    }

    [[nodiscard]] size_t Size() const{
        return root.GetChildsOccurrences();
    }

    void Insert(const std::string& text){
        TrieNode* tempNode = &root;
        for (auto it = text.begin(); it != text.end(); it++){
            if (!TrieNode::IsCorrectValue(*it)){
                tempNode->IncreaseOccurrences();
                tempNode = &root;
                continue;
            }

            if (tempNode->IsHaveChild(*it)){
                tempNode = tempNode->GetChildNode(*it);
                continue;
            }
            tempNode->AddChild(*it);
            tempNode = tempNode->GetChildNode(*it);
        }

        if (TrieNode::IsCorrectValue(*(text.end()-1))) {
            tempNode->IncreaseOccurrences();
        }
    }

    [[nodiscard]] size_t Find(const std::string& text) const{
        const TrieNode* tempNode = &root;
        for (auto it = text.begin(); it != text.end(); it++) {
            if (!tempNode->IsHaveChild(*it)){
                return 0;
            }

            tempNode = tempNode->GetChildNode(*it);
        }

        return tempNode->GetOccurrenceCount();
    }

    TrieNode& GetRoot(){
        return (TrieNode&) root;
    }
};


#endif //SAOD_2_TRIE_H
