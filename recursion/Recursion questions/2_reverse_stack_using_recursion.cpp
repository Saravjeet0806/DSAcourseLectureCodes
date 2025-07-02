class Solution {
  public:
    void Reverse(stack<int> &st) {
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        Reverse(st);
        pushelement(st, x);
        return;
    }
    void pushelement(stack<int>&st , int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int y = st.top();
        st.pop();
        pushelement(st, x);
        st.push(y);
    }
};


//recursive tree -- {3,2,1,7,6} == {6,7,1,2,3}

Reverse(stack)
 |
 x = 6 (popped)
 |
 --> Reverse(stack)
     |
     x = 7 (popped)
     |
     --> Reverse(stack)
         |
         x = 1 (popped)
         |
         --> Reverse(stack)
             |
             x = 2 (popped)
             |
             --> Reverse(stack)
                 |
                 x = 3 (popped)
                 |
                 --> Reverse(stack)
                     |
                     [Stack is empty]
                     |
                 pushelement(stack, 3)
             pushelement(stack, 2)
         pushelement(stack, 1)
     pushelement(stack, 7)
 pushelement(stack, 6)
