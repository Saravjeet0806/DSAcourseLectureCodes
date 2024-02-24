#include <iostream>
using namespace std;
class hero{
public:
int roll;
char name;
hero(int roll, char name){
  this->roll = roll;
  this->name= name;
}
hero( hero & temp){
  cout<<"copy constructor called"<<endl;
  this->roll = temp.roll;
  this->name= temp.name;
}
void print(){
    cout<<" roll no is "<<roll<<endl;
    cout<<" name is "<<name<<endl;
}
};
int main(){
hero obj(23, 'A');
obj.print();
hero *obj2 = new hero(45, 'B');
obj2->print();
hero R(34,'C');   //copy constructor
hero S(R);
S.print();
return 0;
}