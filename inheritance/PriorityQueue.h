//
// Created by Gaudium on 25.03.2024.
//

#ifndef SAOD_2_PRIORITYQUEUE_H
#define SAOD_2_PRIORITYQUEUE_H
#include "LinkedList.h"
#include "IPriorityQueue.h"

template <typename T>
class PriorityQueue : public LinkedList<T>, public IPriorityQueue<T> {

public:
    PriorityQueue() : LinkedList<T>() {}

    [[nodiscard]] unsigned int size() const override {
        return LinkedList<T>::size();
    }

    [[nodiscard]] bool empty() const override{
        return LinkedList<T>::empty();
    }

    void push(const T& data) override{
        LinkedList<T>::push_front(data);
    }

    void pop() override{
        unsigned int maxIndex = 0;
        T maxValue = LinkedList<T>::operator[](maxIndex);
        for (unsigned int i = 0; i < size(); i++){
            T tempValue = LinkedList<T>::operator[](i);
            if (tempValue > maxValue){
                maxIndex = i;
            }
        }

        LinkedList<T>::remove_at(maxIndex);
    }

    T top() const override{
        if (empty()){
            throw std::out_of_range("Queue is empty! Cannot get top element.");
        }

        T maxValue = LinkedList<T>::operator[](0);
        for (unsigned int i = 0; i < size(); i++){
            T tempValue = LinkedList<T>::operator[](i);
            if (tempValue > maxValue){
                maxValue = tempValue;
            }
        }

        return maxValue;
    }
};


#endif //SAOD_2_PRIORITYQUEUE_H
