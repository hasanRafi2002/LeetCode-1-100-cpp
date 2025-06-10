#include<bits/stdc++.h>
using namespace std;

int factor(int n){
    if(n==0){
        return 1;
    }

    return n*factor(n-1);
}

int main(){
cout<<factor(5)<<endl;

    return 0;
}