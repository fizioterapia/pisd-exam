#include "kontener.h"
#include "dane.h"
#include <fstream>

ostream &operator<<(ostream &os, Podatnik &p) {
    os << p.getNazwisko()
    << endl
    << p.getImie()
    << endl
    << p.getNIPFormatted()
    << endl;
    if (p.getVerify() == true) {
        os << "DO WERYFIKACJI";
    } else {
        os << p.getRozliczenie();
    }
    os << endl
    << endl;
    return os;
}

int main() {
    LinkedList<Podatnik> list;

    ifstream podatnicy{"podatnicy.txt"};
    ifstream rozliczenia{"rozliczenia.txt"};
    ofstream wyniki;
    wyniki.open("wyniki.txt", ios::trunc);

    while(podatnicy) {
        Podatnik p;
        string dane;

        getline(podatnicy, dane);
        try {
            p.setNIP(dane);
        } catch (logic_error &e) {
            cout << "BŁĄD! " << e.what() << endl;
            
            getline(podatnicy, dane);
            getline(podatnicy, dane);
            getline(podatnicy, dane);
            getline(rozliczenia, dane);
        }

        string imie = "";
        string nazwisko = "";
        bool typ = false;

        getline(podatnicy, dane);

        for(int i = 0; i < dane.length(); i++) {
            if (dane[i] == ' ' && typ == false) {
                typ = true;
                continue;
            }
            if (typ == false) {
                nazwisko = nazwisko + dane[i];
            } else {
                imie = imie + dane[i];
            }
        }

        if (imie == "" || nazwisko == "") {
            getline(podatnicy, dane);
            getline(rozliczenia, dane);
            continue;
        }

        p.setImie(imie);
        p.setNazwisko(nazwisko);

        getline(podatnicy, dane);

        getline(rozliczenia, dane);
        p.addRozliczenie(dane);
        
        list.add(p);
    }

    Node<Podatnik>* s = list.head;
    while(s != nullptr) {
        Podatnik p = s->value;

        wyniki << p;

        s = s->next;
    }

    return 0;
}