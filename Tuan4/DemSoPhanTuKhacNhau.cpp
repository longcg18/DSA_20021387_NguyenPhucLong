/** bài toán đếm số phần tử khác nhau trong một mảng được nhập từ bàn phím */
#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cout << "Nhap so phan tu:" ;
    cin >> n;
    cout << "Nhap " << n << " phan tu:" << endl;
    int a[10000];
    set<int> a_set;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a_set.insert(a[i]);
    }
    cout << n << " phan tu tren co " << a_set.size() << " phan tu khac nhau!" << endl;
    return 0;
}
