https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1
class Solution {
  public:
    int helper(int n){
        if(n%4==1) return 1;
        else if(n%4==2) return n+1;
        else if(n%4==3) return 0;
        else return n;
    }
    int findXOR(int l, int r) {
        int ans = helper(l-1)^helper(r);
        return ans;
    }
};