#include<bits/stdc++.h>
using namespace std;

void test(int (*p)[3],int n){
    int a = sizeof(p[0])/sizeof(p[0][0]);
    for(int i=0; i<n; i++){
        for(int j=0;j<a;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int data[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // cout<<data<<endl;
    // cout<<data[0]<<endl;
    // cout<<data+1<<endl;
    // cout<<data[1]<<endl;
    // cout<<**(data)+1;
    test(data,sizeof(data)/sizeof(data[0]));
}