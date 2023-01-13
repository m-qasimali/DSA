#include<bits/stdc++.h>

using namespace std;

vector<int> add(vector<int> a,vector<int> b){
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
        res.insert(res.begin(),(x+y+c)%10);
        c = (x+y+c)/10;
    }
    return res;
} 

int main(){
    vector<int> a = {9,9,9};
    vector<int> b = {2,8};
    vector<int> c = add(a,b);
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<" ";
    }
}