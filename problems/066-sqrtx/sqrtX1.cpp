#include <iostream>
using namespace std;

int mySqrt(int x){
    if (x==0 || x==1) return x;
    int left = 1, right = x, ans = 0;
    while(left <= right){
        long long mid = left + (right -left)/2;
        long long square = mid*mid;

        if (square == x){
            return mid;
        }else if (square < x){
            ans = mid;
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }
    return ans;
}

int main(){
    int x;
    cout<<"Enter a non-negative integer: ";
    cin>>x;

    if(x<0){
        cout<<"Invalid input. Must be non-negative."<<endl;
        return 1;
    }
    int result = mySqrt(x);
    cout<<"The integer square root of "<<x<<" is: "<<result<<endl;

    return 0;
}