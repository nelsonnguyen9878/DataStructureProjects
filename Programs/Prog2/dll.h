// dll.h


template <typename TYPE>
class Node
{
    public:
    typedef Node<TYPE>* n_ptr; // nickname 
    Node(); // default constructor
    Node(const TYPE& data, n_ptr prev, n_ptr next); // overloaded constructor
    int SetData(const TYPE&);
    int SetPrev(Node<TYPE>*);
    int SetNext(Node<TYPE>*);
    TYPE GetData(void);
    Node<TYPE>* GetPrev(void);
    Node<TYPE>* GetNext(void);
    
    

    private:
    TYPE data;
    n_ptr prev, next;
};

template<typename TYPE>
class Deck
{
    public:
    typedef Node<TYPE>* n_ptr;
    Deck(); // default constructor
    Deck(n_ptr, n_ptr); // overloaded constructor
    ~Deck();  // destructor
    int insertAtHead(const TYPE& data); 
    int insertAtTail(const TYPE& data);
    TYPE grabAtHead(void);
    TYPE grabAtTail(void);
    int popAtHead(void);
    int popAtTail(void);
    int displayAll(void);
    int removeAll(void);
    Deck<TYPE>& operator=(const Deck<TYPE>& other);

    private:
    n_ptr head;
    n_ptr tail;
    int displayAllHelper(n_ptr head);   
    int removeAllHelper(n_ptr head);
};


#include "dll.tpp"
