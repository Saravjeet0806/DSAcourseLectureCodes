class Solution {
public:
    int hammingWeight(uint32_t n) {
      int count = 0;
      while(n!=0){
          if (n&1){    // agar and karne pe 1 aya toh count badhao aur right shift maro
              count ++;
          }
          n=n>>1;
      }
     return count;
    }
    
};