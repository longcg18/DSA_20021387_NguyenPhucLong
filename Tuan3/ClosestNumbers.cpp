vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());
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
    cout << "min_diff = " << min_diff;
    vector<int> outPut;
    for (int i = 0; i < n - 1; i++) {
        if (diff[i] == min_diff) {
            outPut.push_back(arr[i]);
            outPut.push_back(arr[i+1]);
        }
    }
    return outPut;
}
