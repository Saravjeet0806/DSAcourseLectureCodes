//swap 2 numbers
class Solution {
  public:
    pair<int, int> get(int a, int b) {
        a=a^b;
        b=a^b;
        a=a^b;
        return {a,b};
    }
};

//kth bit is set or not
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        if((n&(1<<k))!=0){
            return true;
        }
        return false;
    }
};

//get, set, clear
class Solution {
  public:
    void bitManipulation(int num, int i) {
        int get = (num & 1<<i-1)?1:0;
        
        int set = (num | 1<<i-1);
        
        int clear = (num & ~(1<<i-1));
        
        cout<<" "<<get<<" "<<set<<" "<<clear;
        
    }
}; //uses one based indexing

//remove rightmost bit
#include <bits/stdc++.h>
using namespace std;

int unsetLSB(int n)  { 
    return (n & (n - 1)); 
} 

int main() { 
    int n = 12; 
    cout << unsetLSB(n); 
    return 0; 
}

//check if no is power of 2
class Solution {
  public:
    bool isPowerofTwo(int n) {
        if((n&n-1)==0){
            return true;
        }
        return false;
    }
};

//count no of set bits
class Solution {
  public:
    int setBits(int n) {
        int count =0;
        while(n){
            n=n&(n-1);
            count++;
        }
        return count;
    }
};