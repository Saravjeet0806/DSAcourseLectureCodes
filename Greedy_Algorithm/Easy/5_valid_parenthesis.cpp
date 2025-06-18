class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0;

        for(char c : s){
            if(c=='('){
                min++;
                max++;
            }
            else if(c == ')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }

            if(max<0) return false;  //edge case if the string starts with )....
            if(min<0)  min=0;  // decrease min only upto 0;
        }

        return min==0;       //if min =0 return true;
    }
};