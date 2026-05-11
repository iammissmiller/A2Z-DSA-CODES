bool search(vector<int>& arr, int x) {

    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        // target found
        if(arr[mid] == x)
            return true;

        // duplicate case
        if(arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        // LEFT HALF SORTED
        if(arr[low] <= arr[mid]) {

            if(arr[low] <= x && x < arr[mid]) {
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        // RIGHT HALF SORTED
        else {

            if(arr[mid] < x && x <= arr[high]) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }
    }

    return false;
}
