lc 31
void nextPermutation(vector<int>& arr) {
    int n = arr.size();
    int ind = -1;

    // Step 1: find breakpoint
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            ind = i;
            break;
        }
    }

    // Step 2: if no breakpoint
    if (ind == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

    // Step 3: find next greater element
    for (int i = n - 1; i > ind; i--) {
        if (arr[i] > arr[ind]) {
            swap(arr[i], arr[ind]);
            break;
        }
    }

    // Step 4: reverse suffix
    reverse(arr.begin() + ind + 1, arr.end());
}
