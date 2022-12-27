#ifndef LIST_H
#define LIST_H

template <class T>
struct Node {
    Node* next;
    T val;
};

// 单链表
template <class T>
class List {
private:

    Node<T>* first;

    void removeAll(); // 移除链表所有元素

    void copyhelp(const Node<T>*);

    void copyFrom(const List& l);

public:
    bool isEmpty() const; //判断链表是否为空，为空则返回true,否则返回false

    void insert(T val); //将val插入到链表中，用first指向新插入的元素

    T removeFirst(); //从链表中移除第一个Node并返回其val值

    Node<T>* returnFirst(); 

    List();                                 // constructor

    List(const List& l);                    // copy constructor

    List& operator=(const List& l);         // assignment operator

    ~List();                                // destructor
};

template <class T>
bool List<T>::isEmpty() const
{
    return !first;
}

template <class T>
void List<T>::insert(T val)
{
    Node<T>* newP = new Node<T>;
    newP->val = val;
    newP->next = nullptr;
    if (!first)
    {
        first = newP;
    }
    else
    {
        newP->next = first; //新插入元素的next指向first指向的元素
        first = newP; //first指向新插入的元素
    }
}

template <class T>
T List<T>::removeFirst()
{
    Node<T>* victim = first;
    T value = victim->val;
    first = first->next;
    delete victim; //first始终指向一块动态分配的内存
    return value;
}

template <class T>
void List<T>::removeAll()
{
    while (!isEmpty())
    {
        removeFirst();
    }
}

template <class T>
Node<T>* List<T>::returnFirst()
{
    return first;
}

template <class T>
List<T>::List()
{
    first = nullptr;
}

template <class T>
void List<T>::copyhelp(const Node<T>* root)
{
    copyhelp = root->next;
    insert = root;
}

template <class T>
void List<T>::copyFrom(const List& l)
{
    copyhelp = l.first;
}

template <class T>
List<T>::List(const List& l)
{
    first = nullptr;
    copyFrom(l);
}

template <class T>
List<T>& List<T>::operator=(const List<T>& l)
{
    if (this != &l)
    {
        removeAll();
        copyFrom(l);
    }
    return *this;
}

template <class T>
List<T>::~List()
{
    removeAll();
}

#endif //LIST_H