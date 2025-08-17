https://www.geeksforgeeks.org/dsa/rabin-karp-algorithm-for-pattern-searching/


class Solution {
  public:
    vector<int> rabinKarp(string &text, string &pattern) {
        const int base = 256;                // Number of possible characters
        const int mod = 1e9 + 7;             // Large prime for mod
        int n = text.size(), m = pattern.size();
        vector<int> result;

        if (m > n) return result;

        long long patternHash = 0, textHash = 0, h = 1;

        // Precompute h = pow(base, m-1) % mod
        for (int i = 0; i < m - 1; i++)
            h = (h * base) % mod;

        // Compute initial hash values for pattern and first window
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * base + pattern[i]) % mod;
            textHash = (textHash * base + text[i]) % mod;
        }

        // Slide the pattern over text
        for (int i = 0; i <= n - m; i++) {
            // If the hash values match, check the actual substrings
            if (patternHash == textHash) {
                if (text.substr(i, m) == pattern) {
                    result.push_back(i);
                }
            }

            // Compute the next hash (rolling)
            if (i < n - m) {
                textHash = (base * (textHash - text[i] * h) + text[i + m]) % mod;

                // Handle negative hash
                if (textHash < 0)
                    textHash += mod;
            }
        }

        return result;
        
    }
};