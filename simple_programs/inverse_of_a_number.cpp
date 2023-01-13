#include<bits/stdc++.h>
using namespace std;

int inverse(int val){
    int dividend = val;
    int temp = 0;
    int index = 1;
    int res = 0;
    while(dividend!=0){
        temp = dividend%10;
        // cout<<index<<"-->"<<temp<<endl;
        int base = 1;
        while(temp != 1){
            base *= 10;
            temp--;
        }
        res += index*base;
        dividend = dividend/10;
        index++;
    }
    return res;
}

int main(){
    cout<<inverse(15234);
}