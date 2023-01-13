#include<bits/stdc++.h>

using namespace std;

// a must be greater than that of b
vector<int> difference(vector<int> a,vector<int> b){
    vector<int> res;
    int c = 0;
    int i = a.size()-1;
    int j = b.size()-1;
    while(c!=0 || i>=0 || j>=0){
        int x = 0;
        int y = 0;
        if(i>=0){
            x = a[i];
            i--;
        }
        if(j>=0){
            y = b[j];
            j--;
        }
        x = x+c;
        c=0;
        if(x<y){
            x += 10;
            c = -1;
        }
        res.insert(res.begin(),(x-y));
    }
    return res;
} 

int main(){
    vector<int> a = {9,8,9};
    vector<int> b = {9,0,9};
    vector<int> c = difference(a,b);
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<" ";
    }
}