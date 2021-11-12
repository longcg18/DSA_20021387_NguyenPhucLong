#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int main () {
    fstream infile;
    infile.open("matrix.txt");
    int m, n;

    infile >> m >> n;

    int a[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            infile >> a[i][j];
        }
    }

    int sum = 0;
	vector<int> allsum;
	vector<int> row1;
	vector<int> col1;
	vector<int> row2;
	vector<int> col2;
	for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
    for (int c = i + 1; c < m; c++) {
    for (int d = j + 1; d < n; d++) {
        for (int h = i; h <= c; h++) {
            for (int k = j; k <= d; k++) {
                sum += a[h][k];
                row1.push_back(i);
                col1.push_back(j);
                row2.push_back(c);
                col2.push_back(k);
                allsum.push_back(sum);
            }
        }
        sum = 0;
    }
    }
    }
	}

    int max = allsum[0];
	for (int i = 0; i < allsum.size(); i++) {
		if (allsum[i] > max) max = allsum[i];
	}
	int index;
	for (int i = 0; i < allsum.size(); i++) {
		if (allsum[i] == max) {
			index = i;
			break;
		}
	}
	ofstream output;
	output.open("matrix.out");
	output << row1[index] + 1 << " " << col1[index] + 1 << " " << row2[index] + 1 << " " << col2[index] + 1 << " " << max;
    return 0;
}
