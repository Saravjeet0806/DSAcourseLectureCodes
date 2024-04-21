#include <bits/stdc++.h> 
void sortedInsert(stack<int> &stack, int num){
     //base case
     if (stack.empty() ||
         (!stack.empty() &&
          stack.top() < num)) { // agar empty nhi hai sath me stack top elemnt
                                // chhota hai num se
        stack.push(num);
		return ;
     }
    int n=stack.top();
	stack.pop();

	//recursive call
    
	sortedInsert(stack,  num);
	stack.push(n);
}
void sortStack(stack<int> &stack)
{
	//base case
	if(stack.empty()){
		return;
	}
	int num=stack.top();
	stack.pop();

	//recursive call
	sortStack(stack);
	
	sortedInsert(stack,num);   //wapis aate time sorted insert karna hai
}