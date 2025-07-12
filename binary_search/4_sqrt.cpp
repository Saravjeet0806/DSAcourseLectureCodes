// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int n) {
        int s = 0;
        int e = n;
        
        long long int ans = -1;
        while(s<=e) {
            int mid = s + (e-s)/2;
            long long int square = 1LL *mid*mid;
            
            if(square == n)
                return mid;
            
            if(square < n ){
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            } 
        }
        return ans;
    
    }
};

