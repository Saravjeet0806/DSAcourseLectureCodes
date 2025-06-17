class Solution {
public:
 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Each element in the heap is a pair: (frequency, element)

   //The heap is ordered by the first element of the pair, because of greater<> → it becomes a min-heap, meaning the smallest frequency stays at the top.
        for(auto &i : nums){
            mp[i]++  ;  
        }

        for(auto &it : mp){
             int value = it.first;
             int freq = it.second;

             pq.push({freq,value}); //push according to frequeny and value

             if(pq.size()>k){
                pq.pop();
             }
        }

        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second); //push the value into result array
            pq.pop();
        }
        return result;

    }
};