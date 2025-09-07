class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the graph and indegree array
    vector<vector<int>> adj(numCourses);  // Adjacency list representation of the graph
    vector<int> indegree(numCourses, 0);    // Indegree array
    
    // Step 2: Populate the graph and indegree array
    for (auto& i : prerequisites) {
        int course = i[0];
        int preCourse = i[1];
        adj[preCourse].push_back(course);  // Edge from prerequisiteCourse to course
        indegree[course]++;  // Increase the indegree of course
    }
    
    // Step 3: Initialize the queue with nodes having 0 indegree
    queue<int> zeroIndegree;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            zeroIndegree.push(i);  // No prerequisites, so can be taken first
        }
    }
    
    // Step 4: Process the nodes with 0 indegree
    int coursesProcessed = 0;
    while (!zeroIndegree.empty()) {
        int currentCourse = zeroIndegree.front();
        zeroIndegree.pop();
        coursesProcessed++;  // One course can be taken
        
        // Reduce the indegree of neighbors (i.e., courses dependent on currentCourse)
        for (int neighbor : adj[currentCourse]) {
            indegree[neighbor]--;
            // If indegree becomes 0, it can be taken, so add it to the queue
            if (indegree[neighbor] == 0) {
                zeroIndegree.push(neighbor);
            }
        }
    }
    
    // Step 5: If all courses are processed, return true, otherwise false
    return coursesProcessed == numCourses;
       
    }
};

//using dfs 
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& dfsVisited) {
        visited[node] = 1;
        dfsVisited[node] = 1;  // mark this node in the recursion stack

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, dfsVisited)) {
                    return true;  // cycle found
                }
            }
            else if (dfsVisited[neighbor]) {
                return true; // back edge → cycle
            }
        }

        dfsVisited[node] = 0; // backtrack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: build adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);  // edge: prereq → course
        }

        // Step 2: visited + recursion stack arrays
        vector<int> visited(numCourses, 0);
        vector<int> dfsVisited(numCourses, 0);

        // Step 3: check each component
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, dfsVisited)) {
                    return false; // cycle → cannot finish
                }
            }
        }

        return true; // no cycle → all courses can be finished
    }
};
