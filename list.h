#ifndef LIST_H
#define LIST_H

template <class T>
struct Node {
    Node* next;
    T val;
};

// µ¥Á´±í
template <class T>
class List {
private:

    Node<T>* first;

    void removeAll();
    // EFFECTS: called by destructor/operator= to remove and destroy
    //          all list elements

    void copyhelp(const Node<T>*);
    void copyFrom(const List& l);
    // MODIFIES: this
    // EFFECTS: called by copy constructor/operator= to copy elements
    //          from a source list l to this list;
    //          if this list is not empty originally,
    //          removes all elements from it before copying

public:
    bool isEmpty() const;
    // EFFECTS: returns true if list is empty, false otherwise

    void insert(T val);
    // MODIFIES: this
    // EFFECTS: inserts val at the front of the list

    T removeFront();
    // MODIFIES: this
    // EFFECTS: removes the first element from
    //          non-empty list and returns its value
    //          throws an instance of EmptyList if empty

    Node<T>* returnFront();
    // EFFECTS: returns first

    List();                                 // constructor
    List(const List& l);                    // copy constructor
    List& operator=(const List& l);         // assignment operator
    ~List();                                // destructor
};

template <class T>
void List<T>::removeAll() {
    while (!isEmpty()) {
        removeFront();
    }
}

template <class T>
void List<T>::copyhelp(const Node<T>* root) {
    copyhelp(root->next);
    insert(root);
}

template <class T>
void List<T>::copyFrom(const List& l) {
    copyhelp(l.first);
}

template <class T>
bool List<T>::isEmpty() const {
    return !first;
}

template <class T>
void List<T>::insert(T val) {
    Node<T>* newP = new Node<T>;
    newP->val = val;
    newP->next = nullptr;
    if (!first) {
        first = newP;
    }
    else {
        newP->next = first;
        first = newP;
    }
}

template <class T>
T List<T>::removeFront() {
    if (!first) throw EmptyList();
    Node<T>* victim = first;
    T value = victim->val;
    first = first->next;
    delete victim;
    return value;

}

template <class T>
Node<T>* List<T>::returnFront() {
    return first;
}

template <class T>
List<T>::List() :first(nullptr) {}

template <class T>
List<T>::List(const List& l) : first(nullptr) {
    copyFrom(l);
}

template <class T>
List<T>& List<T>::operator=(const List<T>& l) {
    if (this != &l) {
        removeAll();
        copyFrom(l);
    }
    return *this;
}

template <class T>
List<T>::~List() {
    removeAll();
}
#endif //LIST_H
