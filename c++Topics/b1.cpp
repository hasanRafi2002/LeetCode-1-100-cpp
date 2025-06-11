#include<bits/stdc++.h>
using namespace std;


void printArray(int arr[]){      // (int* arr)
cout<<"the size of array inside function : "<<sizeof(arr)<<endl;
}

int main(){

    int arr1[] = {1,2,3,4,5,6};
cout<<sizeof(arr1)<<endl;
cout<<sizeof(int)<<endl;
printArray(arr1);

    return 0;
}