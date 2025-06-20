// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
       
        int n = start.size();
        vector<pair<int, int>> meetings;

        // Pair up each meeting with (end, start)
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        // Sort meetings by end time
        sort(meetings.begin(), meetings.end());

        int count = 0;
        int lastEndTime = -1;

        // Select meetings greedily
        for (auto& meeting : meetings) {
            if (meeting.second > lastEndTime) {
                count++;
                lastEndTime = meeting.first;
            }
        }

        return count;
        
    }
};