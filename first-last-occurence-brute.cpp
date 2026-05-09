pair<int,int> firstLast(vector<int>& arr, int x) {

    int first = -1;
    int last = -1;

    for(int i = 0; i < arr.size(); i++) {

        if(arr[i] == x) {

            if(first == -1)
                first = i;

            last = i;
        }
    }

    return {first, last};
}
