int search(vector<int>& arr, int x) {

    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        // target found
        if(arr[mid] == x)
            return mid;

        // LEFT HALF SORTED
        if(arr[low] <= arr[mid]) {

            // target exists in left half
            if(arr[low] <= x && x < arr[mid]) {
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        // RIGHT HALF SORTED
        else {

            // target exists in right half
            if(arr[mid] < x && x <= arr[high]) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }
    }

    return -1;
}
