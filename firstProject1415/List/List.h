#pragma once
#include <exception>

template<typename T>
class List
{
private:
	struct Node
	{
		Node* prev;
		Node* next;
		T value;
		Node(const T& value_ = T(), Node* next_ = nullptr, Node* prev_ = nullptr) :
			value(value_),
			next(next_),
			prev(prev_)
		{
		}
	};

	Node* head;
	Node* tail;

	//have to save pointer to element after last 
	//because this one is always existing
	//as alternative I can omit saving tail ptr
	//because emptyNode->prev is tail
	//but then will be complication in writing and reading code

	//if I make nullptr as empty node
	//I won't come back to tail
	//because nullptr->prev doesnt make sense
	//For instance, I cant write "listObject.end()--"

	//I also cant save empty Node as tail->next (not to save it explicitly)
	//because if list is empty, tail equals nullptr (nullptr->next is error!)

	Node* emptyNode;
	int s;

public:
	List() :
		head(nullptr),
		tail(nullptr),
		emptyNode(new Node()),
		s(0)
	{
	}

	List(const List&);

	class iterator
	{
	private:
		Node* ptr;

	public:
		friend List<T>;

		iterator() :
			ptr(nullptr)
		{
		}

		explicit iterator(Node* ptr_) :
			ptr(ptr_)
		{
		}

		iterator(const iterator& copy) :
			ptr(copy.ptr)
		{
		}

		T& operator*()
		{
			return ptr->value;
		}

		const T& operator*() const
		{
			return ptr->value;
		}

		iterator operator++()
		{
			if (ptr->next == nullptr)
			{
				throw std::out_of_range("Iterator is out of range");
			}
			ptr = ptr->next;
			return *this;
		}

		iterator operator++(int)
		{
			if (ptr->next == nullptr)
			{
				throw std::out_of_range("Iterator is out of range");
			}
			ptr = ptr->next;
			return *this;
		}

		iterator operator--()
		{
			if (ptr->prev == nullptr)
			{
				throw std::out_of_range("Iterator is out of range");
			}
			ptr = ptr->prev;
			return *this;
		}

		iterator operator--(int)
		{
			if (ptr->prev == nullptr)
			{
				throw std::out_of_range("Iterator is out of range");
			}
			ptr = ptr->prev;
			return *this;
		}

		bool operator==(const iterator& cmp)
		{
			return ptr == cmp.ptr;
		}

		bool operator!=(const iterator& cmp)
		{
			return ptr != cmp.ptr;
		}
	};

	//returns iterator to first element
	iterator begin() const
	{
		if (head)
		{
			return iterator(head);
		}
		return iterator(emptyNode);
	}

	//returns iterator to element after last one
	iterator end() const
	{
		return iterator(emptyNode);
	}

	~List();

	void pushFront(const T&);

	void pushBack(const T&);

	//returns first element's value
	T front() const { return head->value; }

	//returns last element's value
	T back() const { return tail->value; }

	//returns iterator containing value to find
	//uses interval to find value (gets also iterator to begin, and iterator to element after last on interval)
	iterator find(const T& value, const iterator& startSearch, const iterator& endSearch) const;

	//inserts value before element in list
	void insert(iterator&, const T&);

	//removes element
	void erase(iterator&);

	T popBack();
	T popFront();

	int size() const { return s; }

	bool isEmpty() const
	{
		return s == 0;
	}
};

template <typename T>
List<T>::List(const List& copy) :
emptyNode(new Node()),
s(0)
{
	const Node* ptrToCopy = copy.head;

	if (ptrToCopy)
	{
		s++;
		head = tail = new Node(ptrToCopy->value);
		ptrToCopy = ptrToCopy->next;

		while (ptrToCopy->next)
		{
			s++;
			tail->next = new Node(ptrToCopy->value, nullptr, tail);
			tail = tail->next;
			ptrToCopy = ptrToCopy->next;
		}
		tail->next = emptyNode;
		emptyNode->prev = tail;
	}
	else
	{
		head = tail = nullptr;
	}
}

template <typename T>
List<T>::~List()
{
	while (head)
	{
		Node* ptrToDel = head;
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
		tail->next = new Node(value, emptyNode, tail);
		tail = tail->next;
	}
	else
	{
		tail = head = new Node(value, emptyNode);
	}

	emptyNode->prev = tail;
}

template <typename T>
void List<T>::pushFront(const T & value)
{
	s++;
	if (head)
	{
		head = head->prev = new Node(value, head);
	}
	else
	{
		tail = head = new Node(value, emptyNode);
		emptyNode->prev = tail;
	}
}

template <typename T>
typename List<T>::iterator List<T>::find(const T& value, const iterator& startSearch, const iterator& endSearch) const
{
	iterator iterToSearch = startSearch;

	do
	{
		if (*iterToSearch == value)
		{
			return iterToSearch;
		}
		iterToSearch++;
	} while (iterToSearch != endSearch);

	return endSearch;
}

template <typename T>
void List<T>::insert(iterator& iterToInsert, const T& value)
{
	if (iterToInsert == begin())
	{
		pushFront(value);
		return;
	}

	if (iterToInsert == end())
	{
		pushBack(value);
		return;
	}

	s++;
	Node* insertNode = new Node(value, iterToInsert.ptr);

	iterToInsert.ptr->prev->next = insertNode;
	insertNode->prev = iterToInsert.ptr->prev;
	iterToInsert.ptr->prev = insertNode;
}

template <typename T>
void List<T>::erase(iterator& iterToDel)
{
	if (iterToDel.ptr == head)
	{
		popFront();
		return;
	}
	if (iterToDel.ptr == tail)
	{
		popBack();
		return;
	}
	s--;
	iterToDel.ptr->next->prev = iterToDel.ptr->prev;//".prt" added
	iterToDel.ptr->prev->next = iterToDel.ptr->next;//".prt" added
	
	delete iterToDel.ptr;
}

template <typename T>
T List<T>::popBack()
{
	if (isEmpty())
	{
		throw exception("List is empty.");
	}

	s--;
	T valueToReturn = tail->value;
	Node* ptrToDel = tail;

	tail = tail->prev;
	if (tail)
	{
		tail->next = emptyNode;
	}
	else
	{
		head = nullptr;
	}
	emptyNode->prev = tail;

	delete ptrToDel;
	return valueToReturn;
}

template <typename T>
T List<T>::popFront()
{
	if (isEmpty())
	{
		throw exception("List is empty.");
	}

	s--;
	T valueToReturn = head->value;
	Node* ptrToDel = head;

	//if head is last value in list
	//head cant move to emptyNode
	if (head == tail)
	{
		tail = head = nullptr;
	}
	else
	{
		head = head->next;
	}
	delete ptrToDel;
	return valueToReturn;
}
