int pairs(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int cnt = 0;
    int i = 0, j = 1;
    while(j < arr.size()) {
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
