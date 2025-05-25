#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n, target;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter the elements:\n";
    for(int i =0; i<n; ++i){
        cin>>nums[i];
    }

    cout<<"Enter target: ";
    cin>>target;

    unordered_map<int, int> map;
    for(int i =0; i<nums.size(); ++i){
        int complement = target - nums[i];

        if(map.count(complement)){
            cout<<"Indices: ["<<map[complement]<<", "<<i<<"]\n";
            return 0;
        }
        map[nums[i]] = i;
    }
    cout<<"No valid pair found.\n";
    return 0 ;


}