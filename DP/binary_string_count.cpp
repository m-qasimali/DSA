#include<bits/stdc++.h>
using namespace std;

// // using arrays
// int binaryCount(int count){
//     int dp0[count+1];
//     int dp1[count+1];

//     for(int i=0;i<=count;i++){
//         dp0[i] = 0;
//         dp1[i] = 0;
//     }

//     dp0[1] = 1;
//     dp1[1] = 1;

//     for(int i=2;i<=count;i++){
//         dp1[i] = dp1[i-1] + dp0[i-1];
//         dp0[i] = dp1[i-1];
//     }
//     return dp1[count]+dp0[count];
// }


// using variables
int binaryCount(int count){
    int oc0 = 1;
    int oc1 = 1;
    for(int i=2; i<=count; i++){
        int nc0 = oc1;
        int nc1 = oc0 + oc1;

        oc0 = nc0;
        oc1 = nc1;
    }
    return oc0 + oc1;
}

int main(){
    cout<<binaryCount(6);
}