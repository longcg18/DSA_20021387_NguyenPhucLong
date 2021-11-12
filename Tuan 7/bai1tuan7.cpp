#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ifstream file;
    file.open("numbers.txt");
    vector <int> a;
    while(!file.eof()) {
        int temp;
        file >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    ofstream out_file;
    out_file.open("numbers.sorted");

    for (int i = 0; i < a.size(); i++) {
        //cout << a[i] << " ";
        out_file << a[i] << " ";
    }
}
