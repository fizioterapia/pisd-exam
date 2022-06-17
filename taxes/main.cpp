#include "lib_linked_list.h"
#include "lib_firma.h"
#include <fstream>

int main() {
    LinkedList<Company> list;

    ifstream input;
    ofstream ptr;
    ofstream rad;
    ofstream tom;

    ptr.open("piotrkow.txt", ios::trunc);
    rad.open("radomsko.txt", ios::trunc);
    tom.open("tomaszow.txt", ios::trunc);

    input.open("nips.dat");

    while(input) {
        string data;
        Company c;
        getline(input, data);
        try {
            c.load(data);
            list.add(c);
        } catch(const logic_error &e) {
            cout << "invalid data: " << data << endl;
        }
    }

    input.close();

    Node<Company>* s = list.head;
    while(s != nullptr) {
        Company c = s->value;

        if (c.getIRS() == "771")
            ptr << c << endl;
        if (c.getIRS() == "772")
            rad << c << endl;
        if (c.getIRS() == "773")
            tom << c << endl;

        s = s->next;
    }

    ptr.close();
    rad.close();
    tom.close();
}