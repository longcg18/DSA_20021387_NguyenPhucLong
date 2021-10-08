/**Cho dãy số nguyên và một số nguyên k, tìm và in ra số nhỏ nhất lớn hơn k, số lớn nhất nhỏ hơn(hoặc bằng) k */

#include <iostream>
#include <set>

using namespace std;

int main () {
    cout << "Nhap so phan tu cua day: " ;
    int n;
    cin >> n;
    cout << "Nhap " << n << " phan tu: ";
    int a[n];
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    cout << "Nhap k = ";
    int k;
    cin >> k;
    set<int> :: iterator it;
    it = s.upper_bound(k);
    int upper = (it != s.end()) ? *it: -1;

    it = s.lower_bound(k);
    int lower = (it != s.end()) ? *it: -1;

    cout << "So nguyen nho nhat lon hon k la: " << upper << endl;
    cout << "So nguyen lon nhat nho hon(hoac bang) k la: " << lower;
    return 0;
}
