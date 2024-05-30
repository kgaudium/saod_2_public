//
// Created by Gaudium on 29.05.2024.
//

#ifndef SAOD_2_TRIENODE_H
#define SAOD_2_TRIENODE_H


#include <cstddef>
#include <memory>
#include <stdexcept>
#include <memory>
#include <map>
#include <regex>


class TrieNode {
public:
    static const std::regex ValueRegex;
private:
    bool isRoot;
    char value;
    size_t occurrenceCount;
    std::map<char, std::unique_ptr<TrieNode>> childs;

public:
    static bool IsCorrectValue(const char& value);

    TrieNode(char value, bool isRoot=false){
        this->value = value;
        this->isRoot = isRoot;
        occurrenceCount = 0;
    }

//    ~TrieNode(){
//    }

    void AddChild(const char& nodeValue){
        if (IsHaveChild(nodeValue))
            throw std::invalid_argument("Node already have child: " + std::string(1, nodeValue));

        if (!IsCorrectValue(nodeValue))
            throw std::invalid_argument("Value doesn't match value pattern: " + std::string(1, nodeValue));

        childs[nodeValue] = std::make_unique<TrieNode>(nodeValue);
    }

    void IncreaseOccurrences(){
        this->occurrenceCount++;
    }

    size_t GetChildsOccurrences() const{
        size_t sum = 0;
        for (auto it = childs.begin(); it != childs.end(); it++){
            sum += it->second->GetChildsOccurrences();
        }

        if (isRoot) return sum;
        return sum + GetOccurrenceCount();
    }

    [[nodiscard]] char GetValue() const{
        if (isRoot) throw std::logic_error("Root node doesn't have a value.");
        return value;
    }

    [[nodiscard]] size_t GetOccurrenceCount() const{
        if (isRoot) throw std::logic_error("Root node doesn't have occurrences.");
        return occurrenceCount;
    }

    [[nodiscard]] bool IsRoot() const{
        return isRoot;
    }

    [[nodiscard]] bool IsHaveChild(const char& nodeValue) const{
        return childs.find(nodeValue) != childs.end();
    }

    [[nodiscard]] TrieNode* GetChildNode(const char& nodeValue) const{
        auto it = childs.find(nodeValue);
        if (it != childs.end()) {
            return it->second.get();
        }
        //        return nullptr;
        throw std::invalid_argument("Child node with the given value does not exist: " + std::string(1, nodeValue));
    }
};

#endif //SAOD_2_TRIENODE_H
