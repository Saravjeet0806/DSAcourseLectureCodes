https://www.geeksforgeeks.org/problems/count-the-reversals0401/1
class Solution {
  public:
    int countMinReversals(string s) {
        int n = s.length();
        if(n&1) return -1;
        int l=0; int r=0;
        
        for(char c: s){
            if(c=='{'){
                l++;
            }
            else{
                if(l==0){
                    r++;
                }
                else{
                    l--;
                }
            }
        }
        int ans = ceil(l/2.0)+ceil(r/2.0);
        
        return ans;
    }
};