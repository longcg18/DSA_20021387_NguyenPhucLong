#include <iostream>
#include <algorithm>
using namespace std;

class Item {
    public:
    int value; // trị giá của vật
    int weight; // khối lượng của vật
    double scale = (double) value/ (double)weight; // tỉ lệ giá trị / khối lượng
    Item() {}

    Item(int _v, int _w) {
        value = _v;
        weight = _w;
    }

    double getScale() {
        return (double) value / weight;
    }
};

bool compare(Item i1, Item i2) {
    if (i1.getScale() > i2.getScale()) return true;
    return false;
}

// M[]: Các đồ vật hiện có
// V: kích thước tối đa của cái túi
// n: số đồ vật đang có
int knapsack(Item M[], int V, int n) {
    int maxValue = 0; // giá trị tối đa lấy được
    int currentW = 0; // khối lượng đang chứa của balo
    // sắp xếp theo thứ tự giảm độ ưu tiên về tỉ lệ
    sort(M, M+n, compare);

    //for (int i = 0; i < n; i++) {.
    int i = 0;
    while(i < n) {
        if (currentW + M[i].weight <= V) { // đồ vật nào mà có khối lượng + khối lượng hiện tại của balo < khối lượng tối đa của balo
            maxValue += M[i].value; // nhét vào balo, tăng giá trị nhận được lên
            currentW += M[i].weight; // tăng khối lượng ba lo lên
            // tiếp tục nhặt vật đó đến khi nào k nhặt được nữa
        } else { // thì xét sang vật tiếp theo
            i++;
        }
    }
    return maxValue;
}

int main () {

    int n;
    cout << "Nhap so do vat = ";
    cin >> n;

    int baloSize;
    cout << "Nhap kich thuoc balo = ";
    cin >> baloSize;

    Item a[n];

    cout << "Nhap cac do vat(weight value):\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i].weight >> a[i].value;
    }
    cout << "Gia tri lon nhat co the lay ra la = ";
    cout << knapsack(a, baloSize, n);
    return 0;
}
