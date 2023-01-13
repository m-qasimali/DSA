#include<bits/stdc++.h>
using namespace std;

int* inverse(int data[], int size){
    int j=0;
    int *res = new int[size];
    for(int i=0;i<size;i++){
        j = data[i];
        res[j] = i;
    }
    return res;
}

int main(){
    int data[] = {3,4,1,2,0};
    int size = sizeof(data)/sizeof(data[0]);
    int *res = inverse(data,size);
    for(int i=0; i<size;i++){
        cout<<res[i]<<" ";
    }
}