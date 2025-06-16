class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;// max-heap to track task frequencies
        vector<int>mp(26,0); // array to store task frequencies ('A' to 'Z')

        for(char i : tasks){
            mp[i-'A']++; //count the number of times a task needs to be done
        }
        for(int i=0; i<26; i++){
            if(mp[i])
            pq.push(mp[i]);// push non-zero frequencies into the max-heap
        }
        int time =0;
        while(!pq.empty()){
            vector<int>remain;
            int cycle = n+1;// each cycle can contain n+1 slots for tasks
            while(cycle and !pq.empty()){
                int max_freq = pq.top();// get the task with the highest frequency
                pq.pop();
                if(max_freq>1){
                    remain.push_back(max_freq-1);// if tasks still remain, reduce their count
                }
                time++;
                cycle--;
            }
            for(int count: remain){
                pq.push(count);// push remaining tasks back into the priority queue
            }
            if(pq.empty()) break;// exit if no tasks remain
            time+=cycle; // add idle slots if no tasks remain for the current cycle
        }
        return time;
    }
};