class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& i : prerequisites) {
            int course = i[0];
            int preCourse = i[1];
            adj[preCourse].push_back(course);
            indegree[course]++;
        }

        queue<int> zeroIndegree;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                zeroIndegree.push(i); // No prerequisites, so can be taken first
            }
        }

        vector<int> courseOrder;
        while (!zeroIndegree.empty()) {
            int currentCourse = zeroIndegree.front();
            zeroIndegree.pop();
            courseOrder.push_back(currentCourse);

            for (int neighbor : adj[currentCourse]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    zeroIndegree.push(neighbor);
                }
            }
        }
        if (courseOrder.size() == numCourses) {
            return courseOrder; // Valid topological order
        } else {
            return {}; // Cycle detected, return an empty list
        }
    }
};