class Solution {
  public:
    string decToBinary(int n) {
        if (n == 0) {
            return "0";
        }

        string res = "";
        while (n > 0) {
            if (n % 2 == 0) {
                res += '0';
            } else {
                res += '1';
            }
            n = n / 2;
        }

        // Since we add bits from LSB to MSB, we need to reverse the result
        reverse(res.begin(), res.end());
        return res;
    }
};
