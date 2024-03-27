//
// Created by Gaudium on 07.03.2024.
//

#ifndef SAOD_2_LISTNODE_H
#define SAOD_2_LISTNODE_H


/* TODO: Вопрос про абстракный класс нода задать */
template <typename T>
class ListNode{
public:
    T Value;
    ListNode<T>* nextNode;

    // Constructor
    ListNode(T value){
        Value = value;
        nextNode = 0;
    }

    // Copy constructor
    ListNode(const ListNode<T>& other){
        this->Value = other.Value;
        this->nextNode = other.nextNode;
    }

    [[nodiscard]] bool IsSentinel() const{
        return _isSentinel;
    }

    [[nodiscard]] bool IsTail() const{
        return _isSentinel && nextNode == 0;
    }

    static ListNode<T>* GetSentinelNode(bool isTail=false){
        return new ListNode<T>(true, isTail);
    }

    void cascadeDestruct(bool deleteSelf=true){
        if (nextNode != 0) {
            nextNode->cascadeDestruct();
        }

        if (deleteSelf)
            delete this;
    }

private:
    bool _isSentinel = false;

    // Private constructor for sentinel nodes
    ListNode(bool isSentinel, bool isTail){
        this->_isSentinel = isSentinel;
        if (isTail){
            this->nextNode = nullptr;
        }
    }
};

#endif //SAOD_2_LISTNODE_H
