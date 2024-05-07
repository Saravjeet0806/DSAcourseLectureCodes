//sum using recursion
#include <iostream>
using namespace std;
int getSum(int arr[], int size){
   //base case
   if(size==0){
    return 0;
   }
   if(size==1){
    return arr[0];
   }
   
   int sum =arr[0]+getSum(arr+1,size-1);
   return sum;
   
}
int main(){
int arr[5]={1,3,5,6,8};
int size=5;
int sum = getSum(arr, 5);
cout<<"sum is "<<sum<<endl;
return 0;
}