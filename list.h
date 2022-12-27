#ifndef LIST_H
#define LIST_H

template <class T>
struct Node {
    Node* next;
    T val;
};

// ������
template <class T>
class List {
private:

    Node<T>* first;

    void removeAll(); // �Ƴ���������Ԫ��

    void copyhelp(const Node<T>*);

    void copyFrom(const List& l);

public:
    bool isEmpty() const; //�ж������Ƿ�Ϊ�գ�Ϊ���򷵻�true,���򷵻�false

    void insert(T val); //��val���뵽�����У���firstָ���²����Ԫ��

    T removeFirst(); //���������Ƴ���һ��Node��������valֵ

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
        newP->next = first; //�²���Ԫ�ص�nextָ��firstָ���Ԫ��
        first = newP; //firstָ���²����Ԫ��
    }
}

template <class T>
T List<T>::removeFirst()
{
    Node<T>* victim = first;
    T value = victim->val;
    first = first->next;
    delete victim; //firstʼ��ָ��һ�鶯̬������ڴ�
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