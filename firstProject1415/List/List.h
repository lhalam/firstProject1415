#pragma once

template <typename T>
struct Node
{
	Node* prev;
	Node* next;
	T value;
	Node(const T& value_ = T(), Node* next_ = nullptr, Node* prev_ = nullptr) :
		value(value_), next(next_), prev(prev_){}
};

template<typename T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
	int s;

public:
	List() : head(nullptr), tail(nullptr), s(0)
	{

	}

	~List();

	void pushFront(const T&);

	void pushBack(const T&);

	T front() const
	{
		return head->value;
	}

	T back() const
	{
		return tail->value;
	}

	//не шарю як написати прототип ф-ції з аргументами за замовчуванням, тому зразу тіло
	Node<T>* find(const T& value, Node<T>* startPtr = nullptr, Node<T>* endPtr = nullptr) const 
	{
		if (!startPtr) startPtr = head;

		Node<T> *ptrToSearch = startPtr;

		do
		{
			if (ptrToSearch->value == value)
			{
				return ptrToSearch;
			}
			ptrToSearch = ptrToSearch->next;
		} while (ptrToSearch != endPtr);

		return nullptr;
	}

	void insert(Node<T>*, const T&);

	void erase(Node<T>*);

	int size() const
	{
		return s;
	}
};

template <typename T>
List<T>::~List()
{
	Node<T> *ptrToDel = head;
	while (head)
	{
		Node<T> *ptrToDel = head;
		head = head->next;
		delete ptrToDel;
	}
}

template <typename T>
void List<T>::pushBack(const T & value)
{
	s++;
	if (tail)
	{
		tail->next = new Node<T>(value, nullptr, tail);
		tail = tail->next;
	}

	else
	{
		tail = head = new Node<T>(value);
	}
}

template <typename T>
void List<T>::pushFront(const T & value)
{
	s++;
	if (head)
	{
		head->prev = new Node<T>(value, head, head->next);
		head = head->prev;
	}
	else
	{
		tail = head = new Node<T>(value);
	}
}

template <typename T>
void List<T>::insert(Node<T>* ptrToInsert, const T& value)
{
	if (ptrToInsert == head)
	{
		pushFront(value);
		return;
	}

	Node<T>* insertNode = new Node<T>(value, ptrToInsert);

	ptrToInsert->prev->next = insertNode;
	insertNode->prev = ptrToInsert->prev;
	ptrToInsert->prev = insertNode;
}

template <typename T>
void List<T>::erase(Node<T>* ptrToErase)
{
	if (ptrToErase != head)
	{
		ptrToErase->prev->next = ptrToErase->next;
	}
	else
	{
		head = ptrToErase->next;
	}
	if (ptrToErase != tail)
	{
		ptrToErase->next->prev = ptrToErase->prev;
	}
	else
	{
		tail = ptrToErase->prev;
	}
	delete ptrToErase;
}


