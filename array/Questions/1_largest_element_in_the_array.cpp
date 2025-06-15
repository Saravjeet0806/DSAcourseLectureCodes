// https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279

#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    int max=arr[0];
    for(int i=0; i<arr.size(); i++){
        if(max<arr[i])
        max=arr[i];
    }
    return max;
}
