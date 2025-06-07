https://www.geeksforgeeks.org/problems/implementation-of-priority-queue-using-binary-heap/1

class Solution {
  public:
    int extractMax() {
        swap(H[0],H[s]);
        s--;
        shiftDown(0);
        return H[s+1];
    }
};
