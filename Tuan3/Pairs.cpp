/**Complexity: O(nlogn) */
int pairs(int k, vector<int> arr) {
    sort(arr.begin(), arr.end()); //nlogn
    int cnt = 0;
    int i = 0, j = 1;
    while(j < arr.size()) { //2n
        int diff = arr[j] - arr[i];
        if (diff == k) {
            cnt++;
            j++;
        } else if (diff > k) {
            i++;
        } else if (diff < k) {
            j++;
        }
    }
    return cnt;
}

/**Complexity: O(n^2) */
int pairs(int k, vector<int> arr) {
    int temp = 0;
    for (int i = 0; i < arr.size() - 1; i++){
        for (int j = i + 1; j < arr.size(); j++){
            if (abs(arr[i] - arr[j]) == k) temp++;
        }
    }
    return t;
}
