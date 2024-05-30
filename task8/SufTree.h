#pragma once
#include <iostream>	// Нужно, т.к. есть методы визуализации
#include <map>		// для хранения ребер ведущих к дочерним узлам
#include <vector>
#include <list>
#include "Edge.h"
#include "Node.h"
using namespace std;


class ActivePoint {
public:
	Node* node;		// Текущий активный узел
	int edge = -1;	// Текущее активное ребро в активном узле
	int length;		// Длина по активному ребру
};

class SufTree {
    int modT;
	const char* input;				// Буфер где заполняется T
	int last_read = -1;				// Количество прочитанных байтов
	Node* lastCreatedNode = nullptr;

	int node_count = 0;					// Счетчик для задания id-узла.
	Node* root = new Node(node_count++);

	int remainder = 0;					// Количестов суффиксов еще не добавленных явно, но уже присутствующих в дереве.
	ActivePoint ap = { root, -1, 0 };	// {текущий узел, активное ребро в узле, длина по активному ребру}
public:

	SufTree(const char* inp) :input(inp){}
	SufTree(const SufTree&) = delete;			// Запретили копирование, чтобы пользовались ссылками
	SufTree& operator=(const SufTree&) = delete;// Запретили присванивание.

	// все для деструктора
	void deleteEdge(Edge& e) {
		if (e.node)
			deleteNode(e.node);
	}

	void deleteNode(Node* n) {
		for (auto& c : n->children)
		{
			deleteEdge(c.second);
		}
		delete n;
	}
	~SufTree() {
		deleteNode(root);
	}
	// Методы построения дерева
	void extend(int i);
	void finalize();
	
	// Лучше здесь, т.к. нужен индекс последнего прочитаннного смивола. 
	int edgeLen(Edge& e) {
		return e.end >= 0 ? e.end - e.start + 1 : last_read - e.start + 1;
	}
#pragma region Прикладные методы
private:
    bool isPalindrome(const char* str, int start, int len) {
        int end = start + len - 1;
        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

	void fillLeaves(Node* n, int len)
	{
		for (auto& p : n->children)
		{
			int _len = len + edgeLen(p.second);
			if (p.second.isLeaf()) {
				p.second.sufIdx = last_read - _len + 1;
			}
			if (p.second.node)
				fillLeaves(p.second.node, _len);
		}
	}

    void fillPath(Node* n, int pLen) {
        n->pathLen = pLen;
        for (auto& child : n->children) {
            if (child.second.node != nullptr) {
                int edgeLength = (child.second.end == -1 ? last_read : child.second.end) - child.second.start + 1;
                fillPath(child.second.node, pLen + edgeLength);
            }
        }
    }


//    void fillNodes(Node *n) {
//        if (n == nullptr) return;
////        if (n->pathLen < 2) return;
//
//        // Если узел n - лист, добавляем его индекс или реверс-индекс в соответствующий набор
//        if (n->leaf) {
//            if (n->id < modT) {
//                n->idx.insert(n->id);
//            } else {
//                n->revIdx.insert(n->id - modT);
//            }
//            return;
//        }
//
//        // Рекурсивно обрабатываем дочерние узлы
//        for (auto &[_, edge] : n->children) {
//            if (n == root){
////                std::cout << "I'm root" << std::endl;
//            }
//
//            // Если дочернее ребро - лист, добавляем его индекс или реверс-индекс в соответствующий набор
//            if (edge.isLeaf()) {
//                if (edge.sufIdx < modT) {
//                    n->idx.insert(edge.sufIdx);
//                } else {
//                    n->revIdx.insert(edge.sufIdx - modT);
//                }
//                continue;
//            }
//
//            // Здесь всё срабатывает правильно, но для второй ветки ничего не заполняется т.к. они почему-то отмечены как листья, хотя не должны
//            fillNodes(edge.node);
//            // Если дочерний узел имеет наборы idx и revIdx, включаем их в наборы родительского узла
//            n->idx.insert(edge.node->idx.begin(), edge.node->idx.end());
//            n->revIdx.insert(edge.node->revIdx.begin(), edge.node->revIdx.end());
//        }
//    }

    void fillNodes(Node* n, int level) {
        if (n == nullptr) return;

        // Заполняем idx для текущего узла
        if (n->id != -1) {  // Корневой узел не имеет собственного индекса
            n->idx.insert(n->id);
        }

        // Заполняем revIdx для текущего узла
        for (int i : n->idx) {
            n->revIdx.insert(2 * modT - 1 - i);
        }

        // Рекурсивно заполняем дочерние узлы
        for (auto& child : n->children) {
            if (!child.second.isLeaf()) {
                fillNodes(child.second.node, level + 1);
                // Добавляем индексы дочерних узлов в текущий узел
                n->idx.insert(child.second.node->idx.begin(), child.second.node->idx.end());
                n->revIdx.insert(child.second.node->revIdx.begin(), child.second.node->revIdx.end());
            }
        }
    }

    int maxPalindromeLen(Node* n, int len) {
        int maxLen = 0;

        // Проверяем текущий узел на наличие палиндрома
        for (int i : n->idx) {
            int j = modT - i - len;
            if (n->revIdx.find(j) != n->revIdx.end()) {
                maxLen = len;
                break;
            }
        }

        // Рекурсивно проверяем детей текущего узла
        for (auto& child : n->children) {
            if (!child.second.isLeaf()) {
                maxLen = std::max(maxLen, maxPalindromeLen(child.second.node, len + edgeLen(child.second)));
            }
        }

        return maxLen;
    }

    int edgeLen(const Edge& e) const {
        if (e.end == -1) return last_read - e.start + 1;
        return e.end - e.start + 1;
    }


//    void getMaxPalindromes(Node *n, list<int> &res, int len) {
//        if (n == nullptr) return;
//
//        // Если путь к текущему узлу является палиндромом нужной длины, добавляем его индекс в результат
//        if (n->idx.size() > 0 && n->revIdx.size() > 0 && n->pathLen == len) {
//            for (int idx : n->idx) {
//                int revIdx = modT - idx - len; // Реверс-индекс для палиндрома
//                if (n->revIdx.find(revIdx) != n->revIdx.end()) {
//                    res.push_back(idx);
//                }
//            }
//        }
//
//        // Рекурсивно обходим дочерние узлы
//        for (auto &[_, edge] : n->children) {
//            if (edge.node == nullptr) continue; // Проверяем, что у ребра есть узел
//            getMaxPalindromes(edge.node, res, len); // Рекурсивный вызов для каждого дочернего узла
//        }
//    }

    void getMaxPalindromes(Node* n, list<int>& res, int len) {
        if (n->pathLen == len) {
            for (int idx : n->idx) {
                if (n->revIdx.find(2 * modT - 1 - idx - len) != n->revIdx.end()) {
                    res.push_back(idx - len + 1);
                    return;
                }
            }
            return; // Глубже двигаться нет смысла
        }

        for (auto& child : n->children) {
            if (child.second.node != nullptr) {
                getMaxPalindromes(child.second.node, res, len);
            }
        }
    }
public:
    void FillPath() {
        fillPath(root, 0);
    }

	void FillLeaves() {
		fillLeaves(root, 0);
	}

    void FillNodes() {
        if (root == nullptr) return;
        fillNodes(root, 0);
    }

    int MaxPalindromeLen() {
        return maxPalindromeLen(root, 0);
    }

    void GetPalindromes(list<int> &res, int len) {
        getMaxPalindromes(root, res, len);
    }

    void PrintPalindromes(int len) {
        list<int> palindromes;
        GetPalindromes(palindromes, len);

        if (palindromes.empty()) {
            cout << "No palindromes of length " << len << " found." << endl;
        } else {
            cout << "Palindromes of length " << len << ":" << endl;
            for (int idx : palindromes) {
//                if (isPalindrome(input, idx, len))
                {
                    cout.write(input + idx, len);
                    cout << endl;
                }
            }
        }
    }

#pragma endregion
private:
	void showActivePoint() {
		if (ap.edge >= 0)
			cout << '(' << ap.node->id << ", " << input[ap.edge] << ", " << ap.length << ')';
		else
			cout << '(' << ap.node->id << ", " << "undef, " << ap.length << ')';
	}

	void showEdge(Edge& e, int level)
	{
		for (int i = 0; i < edgeLen(e); i++)
			cout << input[e.start + i];
		if(e.isLeaf())
			cout << '|' << e.sufIdx;	// Значит ребро представлет собой и лист
		cout << endl;
	}

    void showNode(Node* n, int level) {
        string shift(level, '\t');
        cout << shift << n->id;
        if (n->suffix_link)
            cout << " --> " << n->suffix_link->id;
        cout << " (pathLen: " << n->pathLen << ")";

        // Вывод idx и revIdx
        cout << " (";
        for (auto it = n->idx.begin(); it != n->idx.end(); ++it) {
            if (it != n->idx.begin()) cout << " ";
            cout << *it;
        }
        cout << ") [";
        for (auto it = n->revIdx.begin(); it != n->revIdx.end(); ++it) {
            if (it != n->revIdx.begin()) cout << " ";
            cout << *it;
        }
        cout << "]";

        cout << endl;

        for (auto& e : n->children) {
            cout << shift << "    ";
            showEdge(e.second, level);
            if (!e.second.isLeaf()) {
                showNode(e.second.node, level + 1);
            }
        }
    }


public: 
	void ShowTree()
	{
        std::cout << "|T|: " << modT << std::endl;
		showNode(root, 0);
	}

};
