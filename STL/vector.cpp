#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums;
    int n=5;
    for (int i = 0; i < n; i++)
    {
        nums.push_back(i); //0, 1, 2, 3, 4
    }
    
    auto it = nums.begin();
    cout<<*it<<endl; //0

    for(auto i : nums){
        cout<<i<<endl; //print whole vector
    }
    if(nums.empty()){
        cout<<"vector is empty"<<endl;
    }
    else{
        cout<<"vector is not empty"<<endl;
    }

    cout<<nums.at(2)<<endl; //2 is present at 2 position
    nums.erase(nums.begin()+2);

    
    for(auto i : nums){
        cout<<i<<endl;  //0, 1, 3, 4
    }
    
    return 0;
}