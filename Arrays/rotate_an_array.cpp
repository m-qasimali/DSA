#include<bits/stdc++.h>
using namespace std;

// void rotate(int data[], int size, int k){
//     int temp = 0;
//     k = k%size;
//     if(k<0){
//         k = k+size;
//     }
//     while( k > 0 ){
//         temp = data[size-1];
//         for(int i=size-1;i>0;i--){
//             data[i] = data[i-1];
//         }
//         data[0] = temp;
//         k--;
//     }
// }

// Array rotation by partition
void reverse(int data[], int s, int e){
    while(s<e){
        swap(data[s],data[e]);
        s++;
        e--;
    }
}

void rotate(int data[], int size, int k){
    k = k%size;
    if(k<0){
        k = k+size;
    }
    int pivot = size-k;
    reverse(data,0,pivot-1);
    reverse(data,pivot,size-1);
    reverse(data,0,size-1);
}

int main(){
    int data[] = {1,2,3,4,5};
    int size = sizeof(data)/sizeof(data[0]);
    // rotate(data,size,-499);
    rotate(data, size, -2);
    for(int i=0;i<size;i++){
        cout<<data[i]<<" ";
    }
}