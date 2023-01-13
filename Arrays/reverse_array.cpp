#include<bits/stdc++.h>

using namespace std;

// vector<int>* reverseArray(vector<int> *data){
//     int i=0;
//     int j = data->size()-1;
//     while(i<j){
//         swap((*data)[i],(*data)[j]);
//         i++;
//         j--;
//     }
//     for(int i=0;i<data->size();i++){
//         cout<<(*data)[i]<<" ";
//     }
//     return data;
// }

int* reverseArray(int data[],int n){
    cout<<data<<endl;
    int i=0;
    int j = n-1;
    while(i<j){
        swap((data)[i],(data)[j]);
        i++;
        j--;
    }
    // for(int i=0;i<n;i++){
    //     cout<<(data)[i]<<" ";
    // }
    return data;
}

class Test{
    public:
    int count = 0;
};



int main(){
    // int a[] = {1,2,3,4,5};
    // cout<<(a)<<endl;
    // int n = sizeof(a)/sizeof(a[0]);
    // int *b = reverseArray(a,n);
    // // vector<int> reversed = reverseArray(a);
    // for(int i=0;i<n;i++){
    //     cout<<b[i]<<" ";
    // }
}