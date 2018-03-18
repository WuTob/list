#pragma once

template<typename T>
struct node
{
    node(T newData) : data(newData), next(nullptr), last(nullptr) {}

    node<T>* next;
    node<T>* last;
    T data;
};

template<typename T>
class list
{
    typedef node<T> _node;

public:
    list();
    explicit list(T newData);

public:
    void append (T newData);
    void append (T newData, int id);
    void prepend(T newData);
    void prepend(T newData, int id);

    int getLenght();
    _node* getNode(int id);
    T getData(int id);

private:
    _node* head;
    _node* tail;

    int lenght;
};

template<typename T>
inline list<T>::list()
    :lenght(0), head(nullptr), tail(nullptr)
{
}

template<typename T>
inline list<T>::list(T newData)
{
    lenght = 1;

    _node* newNode = new _node(newData);
    head = newNode;
    tail = head;
}


//return: _node*
//getNode By id
template<typename T>
node<T>* list<T>::getNode(int id)
{
    _node* temPtr = head;

    for(int i = 1; i < id; i++)
    {
        temPtr = temPtr->next;
    }

    return temPtr;
}

//return T //a data
//getData By id
template<typename T>
inline T list<T>::getData(int id)
{
    return getNode(id)->data;
}

//return int
//getLength
template<typename T>
inline int list<T>::getLenght()
{
    return lenght;
}

template<typename T>
void list<T>::append(T newData)
{
    _node* newNode = new _node(newData);

    lenght++;

    if (lenght == 0)
    {
     head = newNode;
     tail = newNode;
     head->next = tail;
     tail->last = head;
     return;
    }

    if (lenght == 1)
    {
      head->next = newNode;
      delete tail;
      tail = newNode;
      tail->last = head;
      return;
    }

    tail->next = newNode;
    tail = newNode;
    lenght++;
}

template<typename T>
void list<T>::append(T newData, int id)
{
    if(id == lenght){ append(newData); return; }

    _node* currentNode = getNode(id);

    _node* newNode = new _node(newData);

    newNode->next = currentNode->next;
    newNode->last = currentNode;

    currentNode->next
               ->last = newNode;
    currentNode->next = newNode;
}

template<typename T>
void list<T>::prepend(T newData)
{
    _node* newNode = new _node(newData);
    lenght++;

    if (lenght == 0)
    {
        head = newNode;
        tail = newNode;
        head->next = tail;
        tail->last = head;
      return;
    }

    if (lenght == 1)
    {
      newNode->next = tail;
      head = newNode;
      tail->last = head;
      return;
    }

    head->last = newNode;
    head = newNode;
    lenght++;
}

template<typename T>
void list<T>::prepend(T newData, int id)
{
    if(id == 1){ append(newData); return; }

    _node* currentNode = getNode(id);

    _node* newNode = new _node(newData);

    newNode->last = currentNode->last;
    newNode->next = currentNode;

    currentNode->last
               ->next = newNode;
    currentNode->last = newNode;
}


