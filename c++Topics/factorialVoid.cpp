#include<bits/stdc++.h>
using namespace std;


void factor(int n){
int fac = n;

for(int i = n ; i>1; i--){
    fac = fac*(i-1);
}


if(n==0){
    cout<<1<<endl;
}else{
cout<<fac<<endl;
}

}




int main()
{
factor(5);


    return 0;
}