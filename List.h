#include <iostream>
using namespace std;

template<typename T>
class List
{
    template<typename P>
	struct Node
	{
		Node * pNext;
		P data;

		Node(P data=P(), Node *pNext=NULL)
		{
			this->data=data;
			this->pNext=pNext;
		}
	};
	int Size;
	Node<T> *head;
public:
	List();
	List(const int size, const List * head);
	List(const List &list);
	~List();

	void print() const;

	void deleteFirst();

	void deleteLast();

    void deleteAtPos(const int index);

    void Delete(const int val);

	void insertFirst(const T data);

	void insertLast(const T data);

	void insertAtPos(const T data, const int index);

	void clear();

	int GetSize() const;

	bool isContains(const int index) const;

	bool isEmpty() const;

	T getFirst() const;

	T getLast() const;

	T& operator[](const int index);

	friend std::ostream& operator << (std::ostream &out, const List<T> &list);
};

template<typename T>
List<T>::List()
{
	Size=0;
	head=NULL;
}

template<typename T>
List<T>::List(const int size, const List * head)
{
	this->Size=size;
	this->head=*head;
}

template<typename T>
List<T>::List(const List &list)
{
	this->Size=list.size;
	this->head=list.head;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::print() const
{
    Node<T> *p=head;
    for (int i=0; i<Size; i++)
    {
        cout << p->data << endl;
        p=p->pNext;
    }
}

template<typename T>
void List<T>::deleteFirst()
{
	Node<T> *temp=head;
	head=head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::insertLast(const T data)
{
	if (head==NULL)
	{
		head=new Node<T>(data);
	}
	else
	{
		Node<T> *current=this->head;
		while (current->pNext!=NULL)
		{
			current=current->pNext;
		}
		current->pNext=new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		deleteFirst();
	}
}


template<typename T>
T & List<T>::operator[](const int index)
{
	int counter=0;
	Node<T> *current=this->head;
	while (current!=NULL)
	{
		if (counter==index)
		{
			return current->data;
		}
		current=current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::insertFirst(const T data)
{
	head=new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insertAtPos(const T data, const int index)
{
	if (index==0)
	{
		insertFirst(data);
	}
	else
	{
		Node<T> *previous=this->head;
		for (int i=0; i<index-1; i++)
		{
			previous=previous->pNext;
		}
		Node<T> *newNode=new Node<T>(data, previous->pNext);
		previous->pNext=newNode;
		Size++;
	}
}

template<typename T>
void List<T>::deleteAtPos(const int index)
{
	if (index==0)
	{
		deleteFirst();
	}
	else
	{
		Node<T> *previous=this->head;
		for (int i=0; i<index-1; i++)
		{
			previous=previous->pNext;
		}
		Node<T> *toDelete=previous->pNext;
		previous->pNext=toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::deleteLast()
{
	deleteAtPos(Size-1);
}

template<typename T>
void List<T>::Delete(const int val)
{
    int index=0;
	Node<T> *p=head;
    for (int i=0; i<Size-1; i++)
    {
        if (p->data==val)
        {
            p=p->pNext;
            deleteAtPos(index);
            continue;
        }
        p=p->pNext;
        index++;
    }
}

template<typename T>
int List<T>::GetSize() const
{
     return Size;
}

template<typename T>
bool List<T>::isContains(const int index) const
{
     if (index>0&&index<=this->Size) return true;
        else return false;
}

template<typename T>
bool List<T>::isEmpty() const
{
     if (this->Size==0) return true;
        else return false;
}

template<typename T>
T List<T>::getFirst() const
{
    return head->data;
}

template<typename T>
T List<T>::getLast() const
{
    Node<T> *p=head;
    for (int i=0; i<Size-1; i++) p=p->pNext;
    return p->data;
}

template<typename T>
std::ostream& operator << (std::ostream &out, const List<T> &list)
    {
        out << list.data;
        return out;
    }