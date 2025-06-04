#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val){
    int k = 0;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] != val){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main(){
    int n, val;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<"Enter value to remove: ";
    cin>>val;

    int newLength = removeElement(nums, val);
    cout<<"New length: "<<newLength<<endl;
    cout<<"Modified array: ";
    for(int i=0; i<newLength; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}