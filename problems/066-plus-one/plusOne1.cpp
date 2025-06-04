#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits){
    int n = digits.size();

    for(int i = n-1; i>=0; --i){
        if(digits[i]<9){
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(),1);

    return digits;
}

int main(){
    int n;
    cout<<"Enter the number of digits: ";
    cin>>n;

    vector<int> digits(n);
    cout<<"Enter the digits (space separated): ";
    for(int i = 0; i<n; ++i){
        cin>>digits[i];
    }
    vector<int> result = plusOne(digits);
    cout<<"Result after adding onr: ";
    for(int digit: result){
        cout<<digit<<" ";
    }
    cout<<endl;

    return 0;
}