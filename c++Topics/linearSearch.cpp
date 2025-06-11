#include<bits/stdc++.h>
using namespace std;


    int linearSearch(int* arr, int n, int key ){
        for (int i = 0; i<n; i++){
            if(arr[i] == key){
                return i;
            }
        }
        return -1;
    }

int main(){

    int arr1[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n = sizeof(arr1)/sizeof(int);

    int key;
    cin>>key;

    int index = linearSearch(arr1,n,key);

    if (index != -1){
        cout<<key <<" is present at index "<< index<<endl;
    }else{
        cout<<key<<" is not found"<<endl;
    }


    return 0;
}