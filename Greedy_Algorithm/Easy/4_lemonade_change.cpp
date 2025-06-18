class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5){ // if we get 5 
                five++;
            }

            else if(bills[i]==10){ //giving change for 10, ten++, 5--
                if(five){
                    five--;
                    ten++;
                }
                else return false;
            }
            else{  //giving change for 20
                if(five && ten){      //if we have both five and then
                    five--;
                    ten--;
                }
                else if( five>=3){  //if we have only fives
                    five-=3;
                }
                else  //return false if we dont have change for 20s
                return false;
            }
        }
        return true; //return true;
    }
};