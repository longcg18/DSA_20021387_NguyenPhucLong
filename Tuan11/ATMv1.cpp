#include <iostream>
#include <algorithm>
#include <vector>

/**
500.000
200.000
100.000
50.000
20.000
10.000
5.000
2.000
1.000
=> tối giản hoá còn 3 mệnh giá: 1000, 2000, 5000
*/
using namespace std;
// ATM v1, số tờ tièn của mỗi loại tiền là vô hạn.
void withdraw(int money) {
    int re = money;
    vector<int> withdr;
    while(re > 0) {
        if (re > 5000) {
            withdr.push_back(5000);
            re -= 5000;
        } else if (re > 2000) {
            withdr.push_back(2000);
            re -= 2000;
        } else {
            withdr.push_back(1000);
            re -= 1000;
        }
    }
    cout << "Your money here: " << endl;
    for (int i = 0 ; i < withdr.size(); i++) {
        cout << withdr[i] << " " ;
    }
}

int main () {
    int money;
    do{
        cout << "Vui long nhap so tien, lam tron 1000: ";
        cin >> money;
    } while(money % 1000 != 0 && money > 0);
    withdraw(money);
    return 0;
}
