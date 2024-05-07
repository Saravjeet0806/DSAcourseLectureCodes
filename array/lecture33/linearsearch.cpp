//linear search using recursion
#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int k){
    //base case
    if(size==0){
        return false;
    }
    if(arr[0]==k){return true;}
    else{
        int search=linearSearch(arr+1,size-1, k);
        return search;
    }
}
int main(){
int arr[5]={1,3,5,6,7};
int key= 8;
int size=5;
int ans=linearSearch(arr, size, key);
if(ans){
    cout<<"key found"<<endl;

}
else{cout<<"key not found"<<endl;}
return 0;
}