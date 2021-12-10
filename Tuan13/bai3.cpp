#include <iostream>
#include <algorithm>
using namespace std;

class Item {
    public:
    int value;
    int weight;
    double scale = (double) value/ (double)weight;
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

int knapsack(Item M[], int V, int n) {
    int maxValue = 0;
    int currentW = 0;
    sort(M, M+n, compare);
    int i = 0;
    while(i < n) {
        if (currentW + M[i].weight <= V) {
            maxValue += M[i].value;
            currentW += M[i].weight;
        } else {
            i++;
        }
    }
    return maxValue;
}

int main () {

    int n;
    cin >> n;

    int baloSize;
    cin >> baloSize;

    Item a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].weight >> a[i].value;
    }
    cout << knapsack(a, baloSize, n);
    return 0;
}
