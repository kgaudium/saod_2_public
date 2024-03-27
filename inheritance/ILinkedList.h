//
// Created by Gaudium on 25.03.2024.
//

#ifndef SAOD_2_ILINKEDLIST_H
#define SAOD_2_ILINKEDLIST_H
template <typename T>
struct ILinkedList
{
    virtual void push_back(const T& data) = 0, push_front(const T& data) = 0;
    virtual void pop_back() = 0, pop_front() = 0;
    virtual T front() const = 0, back() const = 0;
    virtual unsigned int size() const = 0;
    virtual bool empty() const = 0;
    virtual ~ILinkedList() {}
};

#endif //SAOD_2_ILINKEDLIST_H
