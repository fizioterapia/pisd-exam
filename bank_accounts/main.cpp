#include "lib_iban.h"
#include "lib_linked_list.h"
#include <fstream>

int main() {
    LinkedList<IBAN> list;
    string filename;

    cout << "[INFO] Enter a file name: " << endl;
    cin >> filename;

    ifstream input;
    input.open(filename);

    if(!input) {
        cout << "[INFO] Invalid file name." << endl;
        return 1;
    }

    while(input) {
        string data;
        getline(input, data);
        IBAN i;
        try {
            cout << "[INFO] Loading bank account: " << data << endl;
            i.load(data);
            list.add(i);

            cout << "[INFO] Loaded account: " << i << endl;
        } catch (const logic_error &e) {
            cout << "[INFO] Loading failed: " << e.what() << endl;
        }
    }

    ofstream data1;
    data1.open("1020.txt", ios::trunc);
    ofstream data2;
    data2.open("1140.txt", ios::trunc);
    ofstream data3;
    data3.open("2490.txt", ios::trunc);

    Node<IBAN>* s = list.head;
    while(s != nullptr) {
        IBAN acc = s->value;
        switch(acc.getBankID()) {
            case 1020:
                data1 << acc << endl;
                break;
            case 1140:
                data2 << acc << endl;
                break;
            case 2490:
                data3 << acc << endl;
                break;
            default:
                break;
        }
        s = s->next;
    }

    return 0;
}