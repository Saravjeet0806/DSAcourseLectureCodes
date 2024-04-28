queue<int> modifyQueue(queue<int> q, int k) {
    //step1 pop first k elements from Q and put into stack
    stack <int> s;
    for(int i=0; i<k; i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }
    
    //step2 fetch from stack and push into q
    while(!s.empty()){
        int val=s.top();
        s.pop();
        q.push(val);
    }
    
    //step3 fetch first n-k elemnts from queue and pushback
    
    int t=q.size()-k;
    while(t--){
        int val=q.front();
        q.pop();
        q.push(val);
    }
    return q;
}