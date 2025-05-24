#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> age;

    age["Alice"] = 25;
    age["Bob"] = 30;
    age["Charlie"] = 22;

    cout<<"Alice's age: "<<age["Alice"]<<endl;
    if(age.find("Bob") != age.end()){
        cout<<"Bob is in the map."<<endl;
    }
    for(auto pair : age){
        cout<<pair.first<<" => "<<pair.second<<endl;
    }
    return 0;
}