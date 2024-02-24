#include <bits/stdc++.h> 
//approach 1;
void reverse(queue < int > & q) {
 stack<int> s;

    // step1: put all elements of q into stack
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
    }

    // step2: put all elements from stack to queue
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

}

//approach2
#include <bits/stdc++.h>

void reverse(queue < int > & q) {

// Write your code here.

if(q.empty()){

return;

}

int num=q.front();

q.pop();

reverse(q);

q.push(num);

}