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
    if (s == nullptr || elem > s->value) {
        Node<T>* n = new Node<T>(elem);
        n->next = head;
        head = n;
    } 
    else {
        while(s->next != nullptr && s->next->value > elem) {
            s = s->next;
        }

        if (s->next != nullptr) {
            cout << elem << endl;
            cout << s->next->value << endl;
        }

        Node<T>* n = new Node<T>(elem);
        n->next = s->next;
        s->next = n;
    }
}