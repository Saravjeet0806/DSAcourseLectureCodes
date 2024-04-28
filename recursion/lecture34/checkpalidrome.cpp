// checking palidrome using recursion

#include <iostream>
using namespace std;

bool checkPalidrome(string str, int i, int j){

    //base case
    if(i>j){
        return true;
    }
    if(str[i]!=str[j])
    return false;

    else{
        //recursive call   ek case solve karo baki recursion se ho jayega
        return checkPalidrome(str, i+1,j-1);
    }

}
int main(){
string name= "AbbA";
cout<<endl;
bool isPalidrome= checkPalidrome(name,0, name.length()-1);

if(isPalidrome){
    cout<<"valid palidrome"<<endl;
}
else{
    cout<<"invalid palidrome"<<endl;
}
return 0;
}