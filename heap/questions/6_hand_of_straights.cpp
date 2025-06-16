//lc 846

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> freq;
        priority_queue<int,vector<int>, greater<int>> pq;

        for(int i : hand){
            freq[i]++;
            pq.push(i);
        }
        int lim= n/groupSize;

        for(int i=0; i<lim; i++){
            while(!pq.empty() && freq[pq.top()]<=0){
                pq.pop();
            }
            if(pq.empty())
              return false;

            int small = pq.top();

            freq[small]--;
            for(int j=1; j<groupSize; j++){
                small++; //increating the small to check if there is a consecutive number
                if(freq[small]<=0) //check if the frequency of consecutive number is available
                  return false;

                freq[small]-- ;
            }  
        }
        return true;
    }
};