/**Complexity: O(nlogn)**/
vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end()); // nlogn
    int n = arr.size();
    int min_diff = arr[1] - arr[0];
    int diff[n];
    for (int i = 0; i < n-1; i++)
        diff[i] = arr[i+1] - arr[i];
    for (int i = 0; i < n-1; i++) {
        if (diff[i] < min_diff) {
            min_diff = diff[i];
        }
    }
    //cout << "min_diff = " << min_diff;
    vector<int> outPut;
    for (int i = 0; i < n - 1; i++) {
        if (diff[i] == min_diff) {
            outPut.push_back(arr[i]);
            outPut.push_back(arr[i+1]);
        }
    }
    return outPut;
}

/**Complexity: O(nlogn) */
bool myf(int i, int j) {
    return i < j;
}
vector<int> closestNumbers(vector<int> arr) {
    vector<int> closest;
    sort(arr.begin(), arr.end()); //nlogn
    int MIN = arr[1] - arr[0];
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i+1] - arr[i] < MIN) {
            MIN = arr[i+1] - arr[i];
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        int temp = arr[i] + MIN;
        if (binary_search(arr.begin(), arr.end(), temp, myf)) {
            closest.push_back(arr[i]);
            closest.push_back(arr[i] + MIN);
        }
    }
}

