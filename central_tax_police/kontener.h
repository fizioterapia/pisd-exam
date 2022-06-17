#include <iostream>

template<typename T>
struct Node {
    T value;
    Node<T>* next = nullptr;
    Node<T>(T newValue, Node<T>* next = nullptr) {
        value = newValue;
    }
};

template<typename T>
struct LinkedList {
    LinkedList() = default;
    ~LinkedList();
    Node<T>* head = nullptr;
    void add(T elem);
};

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* s = head;
    Node<T>* h = nullptr;
    while(s != nullptr) {
        h = s;
        s = s->next;
        delete h;
    }
}

template<typename T>
void LinkedList<T>::add(T elem) {
    Node<T>* s = head;
    if (s == nullptr) {
        Node<T>* n = new Node<T>(elem);
        head = n;
    } else {
        while(s->next != nullptr) {
            s = s->next;
        }

        s->next = new Node<T>(elem);
    }
}