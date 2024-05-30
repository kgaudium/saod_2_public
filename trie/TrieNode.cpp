//
// Created by Gaudium on 29.05.2024.
//

#include "TrieNode.h"

std::regex const TrieNode::ValueRegex =  std::regex("[a-zA-Z']");

bool TrieNode::IsCorrectValue(const char& value){
    return std::regex_search(std::string(1, value), ValueRegex);
}

std::ostream& operator << (std::ostream& os, const TrieNode& trieNode) {
    return (os << "TrieNode: " << trieNode.GetValue() << "(" << trieNode.GetOccurrenceCount() << ")" << std::endl);
}