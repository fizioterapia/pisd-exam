#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct Company {
    private:
        int NIP[10];
        string IRS = "";
        string name = "";
    public:
        Company() = default;
        ~Company() = default;
        void load(string data);
        int* getNIP();
        bool checkNIP();
        bool checkIRS();
        string getName();
        string getIRS();
};

bool Company::checkNIP() {
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

    return sum % 11 != 10;
}

bool Company::checkIRS() {
    return (IRS == "771" || IRS == "772" || IRS == "773");
}

void Company::load(string data) {
    for(int i = 0; i < data.length(); i++) {
        if (i < 10) {
            NIP[i] = data[i] - '0';
        }

        if (i < 3) {
            IRS = IRS + data[i];
        }

        if (i > 10) {
            name = name + data[i];
        }
    }

    if (checkNIP() == false)
        throw logic_error("BAD NIP!");
    if (checkIRS() == false)
        throw logic_error("BAD IRS!");
};

int* Company::getNIP() {
    return NIP;
}

string Company::getName() {
    return name;
}

string Company::getIRS() {
    return IRS;
}

ostream &operator<<(ostream &os, Company &f) {
    for(int i = 0; i < 10; i++) {
        os << f.getNIP()[i];
    }
    os << " " << f.getName();

    return os;
}