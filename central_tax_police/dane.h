#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct Podatnik {
    private:
        int NIP[10];
        string imie = "NULL";
        string nazwisko = "NULL";
        double rozliczenie = 0;
        bool toVerify = false;
    public:
        Podatnik() = default;
        void setNIP(string data);
        int* getNIP();
        void setImie(string data);
        string getImie();
        void setNazwisko(string data);
        string getNazwisko();
        void addRozliczenie(string data);
        int getRozliczenie();
        string getNIPFormatted();
        bool getVerify();
        void setVerify(bool data);
};

void Podatnik::setNIP(string data) {
    for(int i = 0; i < 10; i++) {
        NIP[i] = data[i] - '0';
    }

    int sum = 0;
    sum += NIP[0] * 6;
    sum += NIP[1] * 5;
    sum += NIP[2] * 7;
    sum += NIP[3] * 2;
    sum += NIP[4] * 3;
    sum += NIP[5] * 4;
    sum += NIP[6] * 5;
    sum += NIP[7] * 6;
    sum += NIP[8] * 7;
    if(sum % 11 == 10) {
        throw logic_error("Suma kontrola NIPu się nie zgadza!");
    }
}
int* Podatnik::getNIP() { return NIP; }
void Podatnik::setImie(string data) { imie = data; }
string Podatnik::getImie() { return imie; }
void Podatnik::setNazwisko(string data) { nazwisko = data; }
string Podatnik::getNazwisko() { return nazwisko; }
int abs(int val) {
    return (val > 0) ? val : -val;
}
void Podatnik::addRozliczenie(string data) {
    for(int i = 0; i < data.length(); i++) {
        if ((data[i] >= '0' && data[i] <= '9') || data[i] == '.' || data[i] == '-') {
            continue;
        } else {
            setVerify(true);
            break;
        }
    }

    int len = data.length();
    int multiplier = 0;
    bool ujemne = false;
    int start = 0;
    if (data[0] == '-') {
        start = 1;
        ujemne = true;
    }
    for(int i = start; i < len; i++) {
        if (data[i] >= '0' && data[i] <= '9') {
            multiplier++;
        }
        if (data[i] == '.') {
            break;
        }
    }
    double amount = 0;

    for(int i = start; i < len; i++) {
        double number = data[i] - '0';
        double pomnoz = 1;
        if (data[i] == '.') {
            multiplier = -1;
            continue;
        }

        if (multiplier < 0)
            pomnoz = 0.1;

        for(int i = start; i < abs(multiplier) - (1 - start); i++) {
            if (multiplier > 0) {
                pomnoz *= 10;
            } else {
                pomnoz *= 0.1;
            }
        }

        amount += (number * pomnoz);

        multiplier--;
    }

    rozliczenie = amount;
    if(ujemne == true)
        rozliczenie = -rozliczenie;
}
string Podatnik::getNIPFormatted() {
    string out = "";
    for(int i = 0; i < 10; i++) {
        char l = '0' + getNIP()[i];
        out = out + l;
    }
    return out;
}
int Podatnik::getRozliczenie() { 
    int val = rozliczenie;
    double check = val;
    if (rozliczenie > 0) {
        check = check + 0.5;
        if (rozliczenie >= check)
            val++;
    } else {
        check = check - 0.5;
        if (rozliczenie <= check)
            val--;
    }
    return val;
}
void Podatnik::setVerify(bool data) { toVerify = data; };
bool Podatnik::getVerify() { return toVerify; }