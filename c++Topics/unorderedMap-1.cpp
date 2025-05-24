#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> age;
    age["rafi"] = 20;
    age["sara"] = 25;
     cout<<"rafi's age is: "<<age["rafi"]<<endl;
     cout<<"sara's age is: "<<age["sara"]<<endl;

     return 0;

}