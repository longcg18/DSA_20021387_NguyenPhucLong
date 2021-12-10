#include <bits/stdc++.h>

/*
test case 1:
m = 4, n = 4
1 0 0 0
1 1 0 1
0 1 0 1
0 1 1 1


*/
using namespace std;


// Số hàng, số cột
int m, n;

// Ma trận lưu bản đồ
int a[100][100];

// Kiểm tra đã ra khỏi chưa
bool isOut = false;

// Lưu các đường tới đích
vector<string> ways;

// Tạo và nhập vào bản đồ
void createMap() {
    cout << "Rows: ";
    cin >> m;
    cout << "Cols: ";
    cin >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

// Tìm đường: x, y toạ độ hiện tại, way: lưu cách đi
void Try(int x, int y, string way) {

    // Nếu a[1][1] = 0 => false
    if (x == 1 && y == 1 && a[x][y] == 0) {
        isOut = false;
        return;
    }

    // Nếu đứng ở ô cuối cùng, mà ô đó = 1 => cách này có thể đi
    if (x == m && y == n && a[m][n] == 1) {
        ways.push_back(way);
        isOut = true;
        return;
    }

    //Nếu có thể đi xuống dưới x + 1
    if (x < m && a[x+1][y] == 1) {
        Try(x+1, y, way + "Down ");
    }

    // Nếu có thể đi sang phải y + 1
    if (y < n && a[x][y+1] == 1) {
        Try(x, y+1, way + "Right ");
    }
    //Nếu phải hoặc dưới mà không đi được => dừng
    //Nếu đi hết bản đồ (x > m, y > n) => dừng
    if ((x < m && y < n && a[x+1][y] == 0 && a[x][y+1] == 1) || x > m || y > n) {
        return;
    }
}

int main () {
    createMap();
    Try(1, 1, "");
    if (isOut == false) {
        cout << -1;
    } else {
        for (int i = 0; i < ways.size(); i++) {
            cout << ways[i] << endl;
        }
    }
    cout << endl;
    return 1;
}
