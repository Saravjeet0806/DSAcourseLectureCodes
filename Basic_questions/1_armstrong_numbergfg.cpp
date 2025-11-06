//https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1

class Solution {
  public:
    bool armstrongNumber(int n) {
        int real = n;
        int digit = 0;
        int ans = 0;
        while(n != 0){
            int rem = n % 10;
            ans += (rem * rem * rem);
            n /= 10;
        }
        return ans == real;
        
    }
};