int maximumFrequency(vector<int> &arr, int n)
{
   unordered_map<int, int> M;

    int maxi = INT_MIN;

    for(int i=0; i<n; i++) {
        M[arr[i]]++;
        maxi = max(maxi, M[arr[i]]);
    }

    for(int i=0; i<n; i++) {
        if(M[arr[i]] == maxi) {
            return arr[i];
        }
    }
}