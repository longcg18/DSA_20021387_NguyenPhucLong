#include <iostream>
#include <vector>
using namespace std;

/**
1000
2000
5000
 */

class moneyInATM {
public:
    int quantity; // so luong
    int value; // 1000 2000 or 5000

    //constructor
    moneyInATM() {}

    moneyInATM(int _q, int _v) {
        quantity = _q;
        value = _v;
    }

    int getTotal() {
        return quantity * value;
    }

};

class ATM {
public:
    //int numbersOfValue = 3;

    moneyInATM polimes[3];

    ATM () {}

    int totalMoney() {
        return polimes[0].getTotal() + polimes[1].getTotal() + polimes[2].getTotal();
    }

    void getMoneys(moneyInATM mg1, moneyInATM mg2, moneyInATM mg3) {
        polimes[0] = mg1; //1000
        polimes[1] = mg2; //2000
        polimes[2] = mg3; //5000
    }

    void withdraw(int money) {
        int re = money;
        if (re > totalMoney()) {
            cout << "Sorry, we don't have enough money!";
            return;
        }
        vector <int> withdr;
        while(re > 0) {
            if (re >= 5000 && polimes[2].quantity > 0) {
                re -= 5000;
                polimes[2].quantity -= 1;
                withdr.push_back(5000);
            } else {
                if (re >= 2000 && polimes[1].quantity > 0) {
                    re -= 2000;
                    polimes[1].quantity -= 1;
                    withdr.push_back(2000);
                } else {
                    if(re >= 1000 && polimes[0].quantity > 0) {
                        re -= 1000;
                        polimes[0].quantity -= 1;
                        withdr.push_back(1000);
                    } else if (money > 0) {
                        cout << "Sorry, we don't have enough money!";
                        return;

                    }
                }

            }
        }

        cout << "Your money here: \n";
        for (int  i = 0 ; i < withdr.size(); i++) {
            cout << " " << withdr[i];
        }
}

};

int main () {
    int q1, q2, q3;
    cout << "Nhap so luong cho to tien 1000: ";
    cin >> q1;
    cout << "Nhap so luong cho to tien 2000: ";
    cin >> q2;
    cout << "Nhap so luong cho to tien 5000: ";
    cin >> q3;
    moneyInATM mg1(q1, 1000);
    moneyInATM mg2(q2, 2000);
    moneyInATM mg3(q3, 5000);
    ATM atm;
    atm.getMoneys(mg1, mg2, mg3);

    int withdrawmoney;
    do {
        cout << "Nhap so tien muon rut(lam tron 1000): " ;

        cin >> withdrawmoney;
    } while (withdrawmoney < 0 || withdrawmoney % 1000 != 0);
    atm.withdraw(withdrawmoney);
    return 0;
}
