//classes and objects
#include <iostream>
using namespace std;
class Hero{
    public:
    int health;
    char level;
    int power;
};
int main(){
Hero h1;
h1.health=100;
h1.level = 'A';
h1.power= 600;
cout<<h1.health<<" "<<h1.level<<" "<<h1.power<<" "<<endl;
return 0;
}