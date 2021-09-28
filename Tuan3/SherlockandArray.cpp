/**Complexity O(n^2) */
string balancedSums(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int sumLeft = 0;
        int sumRight = 0;
        for (int j = 0; j < i; j++) {
            sumLeft += arr[j];
        }
        for (int k = i+1; k < n; k++) {
            sumRight += arr[k];
        }
        if (sumLeft == sumRight) {
            return "YES";
        }
    }
    return "NO";
}
/**Complexity O(n) */
string balancedSums(vector<int> arr) {
    int n = arr.size();
    int sum = 0;
    int sumLeft = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (2 * sumLeft == sum - arr[i]) {
            return "YES";
        }
        sumLeft += arr[i];
    }
    return "NO";
}
