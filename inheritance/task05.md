## Стек, очередь и очередь с приоритетом через односвязный список.

В задании необходимо реализовать один из контейнеров на основе созданного ранее односвязного списка с использованием механизма наследования.

Требуется, чтобы список реализовывал представленный ниже интерфейс. Интерфейс -  [абстрактный класс](https://ru.cppreference.com/w/cpp/language/abstract_class) , содержащий только чисто виртуальные методы.
```cpp
template <typename T>
struct ILinkedList
{
	virtual void push_back(const T& data) = 0, push_front(const T& data) = 0;
	virtual void pop_back() = 0, pop_front() = 0;
	virtual T front() const = 0, back() const = 0;
	virtual size_t size() const = 0;
	virtual bool empty() const = 0;
	virtual ~ILinkedList() {}
};
```
То есть ваша реализация списка должна начинаться следующим образом.
```cpp
template <typename T>
class LList : public ILinkedList<T>
{
  // конструкторы и методы
};
```

После этого необходимо создать интерфейс, который будет содержать чисто виртуальные функции, обозначающие операции над вашим абстрактным типом данных.
Например, для двухсторонней очереди такой интерфейс будет идентичен `ILinkedList`.
```cpp
template <typename T>
struct IDeque
{
	virtual void push_front(const T& data) = 0,push_back(const T& data) = 0;
	virtual void pop_front() = 0, pop_back() = 0;
	virtual T front() const = 0, back() const = 0;
	virtual size_t size() const = 0;
	virtual bool empty() const = 0;
	virtual ~IDeque() {}
};
```
Затем необходимо реализовать класс, который будет наследником класса `LList` и интерфейса, который вы создали. Например, для двухсторонней очереди `Deque` реализация будет выглядеть следующим образом.
```cpp
template <typename T>
class Deque: public LList<T>, public IDeque<T>
{
public:
	Deque() : LList<T>() {}
	size_t size() const override { return LList<T>::size(); }
	// другие методы
};
```
UML-диаграмма класса `Deque` будет выглядеть следующим образом.

![title](img/classDeque__inherit__graph.png)


### Варианты заданий
1. Стек.
2. Очередь.
3. Очередь с приоритетом.

Проверка для стека.
```cpp
Stack<char> st; // проверка через std::stack<char> st; и #inlcude <stack>
st.push('a');
st.push('b');
st.push('c');

std::cout << st.size() << std::endl;

auto s = st; // нужен конструктор копирования в LList

while(!st.empty()) {
  std::cout << st.top() << '\t';
  st.pop();
}
std::cout << std::endl;
std::cout << st.size() << '\t' << s.size() 
          << '\t' << s.top() << std::endl;

// 3
// c	b	a	
// 0	3	c
```

Проверка для очереди.
```cpp
Queue<char> qe; // проверка через std::queue<char> qe; и #inlcude <queue>
qe.push('a');
qe.push('b');
qe.push('c');

std::cout << qe.size() << std::endl;

auto q = qe; // нужен конструктор копирования в LList

while(!qe.empty()) {
  std::cout << qe.front() << '\t' << qe.back() << std::endl;
  qe.pop();
}
std::cout << qe.size() << '\t' << q.size() << '\t' 
          << q.front() << '\t' << q.back() << std::endl;

// 3
// a	c
// b	c
// c	c
// 0	3	a	c
```

Проверка для очереди с приоритетом.
```cpp
PriorityQueue<char> pq; // проверка через std::priority_queue<char> pq; и #inlcude <queue>
pq.push('a');
pq.push('c');
pq.push('b');
pq.push('e');
pq.push('b');
pq.push('c');

std::cout << pq.size() << std::endl;
auto q = pq; // нужен конструктор копирования в LList
while(!pq.empty()) {
  std::cout << pq.top() << '\t';
  pq.pop();
}
std::cout << std::endl;
std::cout << pq.size() << '\t' << q.size() 
          << '\t' << q.top() << std::endl;
// 6
// e	c	c	b	b	a	
// 0	6	e
```

## UML-диаграммы для вариантов

Стек

![title](img/classStack__inherit__graph.png)

Очередь

![title](img/classQueue__inherit__graph.png)

Очередь с приоритетом

![title](img/classPriority__queue__inherit__graph.png)

