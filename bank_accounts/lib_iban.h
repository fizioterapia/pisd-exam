#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

struct IBAN {
    string country;
    int account[26];
    IBAN() = default;
    void load(string data);
    bool checkCountry();
    int getBankID();
    bool checkBank();
};

void IBAN::load(string data) {
    if (data.length() < 28) {
        throw logic_error("INVALID DATA SIZE!");
    }

    for(int i = 0; i < 28; i++) {
        if (i < 2) {
            country = country + data[i];
        }
        if (i >= 2) {
            account[i-2] = data[i] - '0';
        }
    }

    if (!IBAN::checkCountry()) {
        throw logic_error("WRONG COUNTRY!");
    }

    if (!IBAN::checkBank()) {
        throw logic_error("WRONG BANK!");
    }
}

ostream &operator<<(ostream &os, IBAN &iban) {
    os << iban.country;
    for(int i = 0; i < 26; i++) {
        os << iban.account[i];
    }
    return os;
};

bool IBAN::checkCountry() {
    return country == "PL";
}

int IBAN::getBankID() {
    return account[0] * 1000 + account[1] * 100 + account[2] * 10 + account[3];
}

bool IBAN::checkBank() {
    int bid = getBankID();

    return (bid == 1020 || bid == 1140 || bid == 2490);
}

bool operator>(const IBAN iban1, const IBAN iban2) {
    bool result = false;
    for(int i = 0; i < 26; i++) {
       if (iban1.account[i] > iban2.account[i]) {
        result = true;
        break;
       } else if (iban1.account[i] < iban2.account[i]) {
        result = false;
        break;
       } else {
        continue;
       }
    }

    return result;
}