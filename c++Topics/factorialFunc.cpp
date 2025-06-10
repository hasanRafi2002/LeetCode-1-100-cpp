#include<bits/stdc++.h>
using namespace std;


int factor(int n){
int fac = n;

    if(n==0){
        return 1;
    }

for(int i = n ; i>1; i--){
    fac = fac*(i-1);
}

return fac;
}




int main(){
cout<<factor(0)<<endl;

    return 0;
}