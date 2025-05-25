#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> & nums, int target){
    unordered_map<int, int> map;

    for(int i =0; i<nums.size(); ++i){
        int complement = target-nums[i];
        if(map.count(complement)){
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

int main(){
    int n, target;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements: \n";
    for(int i=0; i<n; ++i){
        cin>>nums[i];
    }

    cout<<"Enter target: ";
    cin>>target;

    for(int i =0; i<n; ++i){
        for(int j= i+1; j<n; ++j){
            if(nums[i]+nums[j] == target){
                cout<<"Indices: ["<<i<<", "<<j<<"]\n";
                return 0;
            }
        }
    }

    cout<<"No valid pair found.\n";
    return 0;

}