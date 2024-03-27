//
// Created by Gaudium on 26.03.2024.
//

#ifndef SAOD_2_IPRIORITYQUEUE_H
#define SAOD_2_IPRIORITYQUEUE_H
template <typename T>
struct IPriorityQueue
{
    virtual void push(const T& data) = 0;
    virtual void pop() = 0;
    virtual T top() const = 0;
    virtual unsigned int size() const = 0;
    virtual bool empty() const = 0;
    virtual ~IPriorityQueue() {}
};
#endif //SAOD_2_IPRIORITYQUEUE_H
