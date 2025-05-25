//  O(n^2) time complexity: with function

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    int n = nums.size();

    for(int i =0; i<n; ++i){
        for(int j = i+1; j<n; ++j){
            if(nums[i]+ nums[j] == target){
                return{i, j};
            }
        }
    }
    return{};
}

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

    vector<int> result = twoSum(nums, target);
    if(!result.empty()){
        cout<<"Indices: ["<<result[0]<<", "<<result[1]<<"]\n";
    }else{
        cout<<"No valid pair found.\n";
    }
    return 0;
}