//
// Created by Gaudium on 22.02.2024.
//

#ifndef SAOD_2_LINKEDLIST_H
#define SAOD_2_LINKEDLIST_H
#include "ListNode.h"
#include "ILinkedList.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList : public ILinkedList<T> {
private:
    ListNode<T>* head;

public:
    void push_back(const T& item){
        ListNode<T>* temp = head;
        while (! temp->nextNode->IsTail()){
            temp = temp->nextNode;
        }

        auto newNode = new ListNode<T>(item);
        newNode->nextNode = temp->nextNode;
        temp->nextNode = newNode;
    }

    void push_front(const T& item){
        auto newNode = new ListNode<T>(item);
        newNode->nextNode = head->nextNode;
        head->nextNode = newNode;
    }

    void insert(unsigned int index, const T& item){
        if (index == 0){
            push_front(item);
            return;
        }

//        if (index >= size()){
//            throw std::out_of_range("Index is out of range!");
//        }

//        it's deoptimization
//        if (index == size() - 1){
//            push_back(item);
//            return;
//        }

        ListNode<T>* temp = head;
        for (unsigned int count = 0; count != index; count++, temp = temp->nextNode){
//            std::cout << count << std::endl;
            if (temp->nextNode->IsTail()){
                throw std::out_of_range("Index is out of range!");
            }
        }

        auto newNode = new ListNode<T>(item);
        newNode->nextNode = temp->nextNode;
        temp->nextNode = newNode;
    }

    void pop_back(){
        ListNode<T>* temp = head;
        while (! temp->nextNode->nextNode->IsTail()){
            temp = temp->nextNode;
        }

        ListNode<T>* tempToDelete = temp->nextNode;
        temp->nextNode = tempToDelete->nextNode;
        delete tempToDelete;

        // TODO: вопрос по рациональности
//        temp->nextNode->cascadeDestruct();
//        temp->nextNode = ListNode<T>::GetSentinelNode(true);
    }

    void pop_front(){
        ListNode<T>* temp = head->nextNode;
        head->nextNode = temp->nextNode;
        delete temp;
    }

    void remove_at(unsigned int index){
        ListNode<T>* temp = head;
        for (unsigned int count = 0; count != index; count++, temp = temp->nextNode){
            if (temp->nextNode->nextNode->IsTail()){
                throw std::out_of_range("Index is out of range!");
            }
        }

        auto tempToDelete = temp->nextNode;
        temp->nextNode = tempToDelete->nextNode;

        delete tempToDelete;
    }

    [[nodiscard]] T front() const{
        return head->nextNode->Value;
    }

    [[nodiscard]] T back() const{
        ListNode<T>* temp = head;
        while (! temp->nextNode->IsTail()){
            temp = temp->nextNode;
        }

        return temp->Value;
    }

    void clear(){
        while (!head->nextNode->IsTail()){
            pop_front();
        }
//        head->cascadeDestruct(false); // impossible for huge lists (stack overflow)
//        head->nextNode = ListNode<T>::GetSentinelNode(true);
    }

    void print() const{
        if (size() == 0){
            std::cout << "[]" << std::endl;
            return;
        }

        std::cout << "[";
        for (ListNode<T>* temp = head; !temp->IsTail(); temp = temp->nextNode){
            if (!temp->IsSentinel()){
                std::cout << temp->Value << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    [[nodiscard]] unsigned int size() const{
        if (head->nextNode->IsTail())
            return 0;

        unsigned int result = 0;
        for (ListNode<T>* temp = head; !temp->IsTail(); temp = temp->nextNode, result++){}

        return result - 1;
    }

    [[nodiscard]] bool empty() const{
        return size() == 0;
    }

    T& operator[] (const unsigned int index){
        ListNode<T>* temp = head;
        for (unsigned int count = 0; count != index; count++, temp = temp->nextNode){
            if (temp->nextNode->nextNode->IsTail()){
                throw std::out_of_range("Index is out of range!");
            }
        }

        return temp->nextNode->Value;
    }

    // TODO: не используется
    T const& operator[] (const unsigned int index) const{
        ListNode<T>* temp = head;
        for (unsigned int count = 0; count != index; count++, temp = temp->nextNode){
            if (temp->nextNode->nextNode->IsTail()){
                throw std::out_of_range("Index is out of range!");
            }
        }

        return temp->nextNode->Value;
    }

    // Copy Constructor
    LinkedList(const LinkedList& other){
        this->head = ListNode<T>::GetSentinelNode();
        auto tempThis = head;
        auto tempOther = other.head->nextNode;

        while (! tempOther->IsTail()){
            tempThis->nextNode = new ListNode<T>(tempOther->Value);

            tempThis = tempThis->nextNode;
            tempOther = tempOther->nextNode;
        }

        tempThis->nextNode = ListNode<T>::GetSentinelNode(true);
    }

    // Constructor
    LinkedList(){
        this->head = ListNode<T>::GetSentinelNode();
        head->nextNode = ListNode<T>::GetSentinelNode(true);
    }

    // Destructor
    ~LinkedList(){
//        head->cascadeDestruct(true); // impossible for huge lists (stack overflow)
        while (!head->nextNode->IsTail()){
            pop_front();
        }

        head->cascadeDestruct(true);
    }
};


#endif //SAOD_2_LINKEDLIST_H
