// tll.tpp
#include <iostream>
using namespace std;

// ******** CLASS NODE TEMPLATE
//default constructor
template<typename TYPE>
Node<TYPE>::Node() : data(TYPE()), prev(nullptr), next(nullptr)
{}
template<typename TYPE>
Node<TYPE>::Node(const TYPE& the_data, n_ptr the_prev, n_ptr the_next): data(the_data), prev(the_prev), next(the_next) 
{}


template<typename TYPE>
int Node<TYPE>::SetData(const TYPE& new_data)
{
    data = new_data;
    return 0;
}

template<typename TYPE>
int Node<TYPE>::SetPrev(Node<TYPE>* new_prev)
{
    prev = new_prev;
    return 1;
}

template<typename TYPE>
int Node<TYPE>::SetNext(Node<TYPE>* new_next)
{
    next = new_next;
    return 1;
}


template<typename TYPE>
TYPE Node<TYPE>::GetData()
{ return data; }

template<typename TYPE>
Node<TYPE>* Node<TYPE>::GetPrev()
{ return prev; }

template<typename TYPE>
Node<TYPE>* Node<TYPE>::GetNext()
{ return next; }



// ******* DECK CLASS TEMPLATE
template<typename TYPE>
Deck<TYPE>::Deck() : head(nullptr), tail(nullptr)
{}

template<typename TYPE>
Deck<TYPE>::Deck(n_ptr new_head, n_ptr new_tail): head(new_head), tail(new_tail)
{}

template<typename TYPE>
Deck<TYPE>::~Deck()
{

}

template<typename TYPE>
int Deck<TYPE>::insertAtHead(const TYPE& data)
{
    if(!head) {
        head = new Node<TYPE>(data, nullptr, nullptr);
        tail = head;
        return 1;
    }
    else {
        Node<TYPE>* temp = head;
        Node<TYPE>* new_node = new Node<TYPE>(data, nullptr, nullptr);
        head = new_node;
        head->SetNext(temp);
        temp->SetPrev(head);
        return 1;
    }

}


template<typename TYPE>
int Deck<TYPE>::insertAtTail(const TYPE& data)
{
    if(!tail) {
        tail = new Node<TYPE>(data, tail, nullptr);
        head = tail;
        return 1;
    }
    else {
        Node<TYPE>* temp = tail;
        Node<TYPE>* new_node = new Node<TYPE>(data, nullptr, nullptr);
        tail = new_node;
        tail->SetPrev(temp);
        temp->SetNext(tail);
        return 1;
    }
}


template<typename TYPE>
TYPE Deck<TYPE>::grabAtHead(void)
{ return head->GetData(); }

template<typename TYPE>
TYPE Deck<TYPE>::grabAtTail(void)
{ return tail->GetData(); }



template<typename TYPE>
int Deck<TYPE>::popAtHead()
{
    if(head != nullptr)
    {
        Node<TYPE>* temp = head;
        head = head->GetNext();
        delete temp;
        return 1;
    }
    else
        return 0;
}

template<typename TYPE>
int Deck<TYPE>::popAtTail()
{
    if(tail != nullptr)
    {
        Node<TYPE>* temp = tail;
        tail = tail->GetPrev();
        delete temp;
        return 1;
    }
    else
        return 0;

}

template<typename TYPE>
int Deck<TYPE>::displayAll()
{
    if(!head) return 0; // empty list

    return displayAllHelper(head);
}


template<typename TYPE>
int Deck<TYPE>::displayAllHelper(Node<TYPE>* head)
{
    if(!head)
        return 0;


    cout << head->GetData();
    cout << endl;

    return displayAllHelper(head->GetNext());
}

template<typename TYPE>
int Deck<TYPE>::removeAll()
{
    if(!head) return 1;

    return removeAllHelper(head);
}

template<typename TYPE>
int Deck<TYPE>::removeAllHelper(Node<TYPE>* head)
{
    if(!head) return 1;
    
    Node<TYPE>* temp = head;
    head = head->GetNext();
    delete temp;
    return removeAllHelper(head);
}


template<typename TYPE>
Deck<TYPE>& Deck<TYPE>::operator=(const Deck<TYPE>& other)
{
    head = other.head;
    tail = other.tail;
}



