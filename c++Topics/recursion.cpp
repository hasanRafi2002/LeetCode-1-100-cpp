#include <iostream>

using namespace std;

void printNums(int n){

    if(n == 1){
        cout<<1<<endl;
        return;
    }
    cout<<n<<" ";
    printNums(n-1);

}

int main(){
    printNums(4);
    return 0;
}