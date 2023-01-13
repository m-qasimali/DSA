#include <bits/stdc++.h>
using namespace std;



//   int maxArea(vector<int>& height) {
//         int a=0;
//         int b=0;
//         int h = 0;
//         int Max = 0;
//         int area = 0;
//         int w=0;
//         for(int i=0;i<height.size()-1;i++){
//             for(int j=i+1;j<height.size();j++){
//                 a = height[i];
//                 b = height[j];
//                 h = min(a,b);
//                 w = j-i;
//                 area = h*w;
//                 Max = max(area,Max);
//             }
//         }
//         return Max;
//     }

    // int trap(vector<int>& height) {
    //     vector<int> left;
    //     vector<int> right;
    //     int mx = 0;
    //     for(int i=0;i<height.size();i++){
    //         mx = max(mx,height[i]);
    //         left.push_back(mx);
    //     }
    //     mx = 0;
    //     for(int i=height.size()-1;i>=0;i--){
    //         mx = max(mx,height[i]);
    //         right.insert(right.begin(),mx);
    //     }


    //     int water = 0;
    //     for(int i=0;i<height.size();i++){
    //         water += (min(left[i],right[i])-height[i]);
    //     }

    //     return water;

        
    // }


// int trap(vector<int>& height) {
//     int maxL = height[0];
//     int maxR = height[height.size()-1];
//     int l = 0;
//     int r = height.size()-1;
//     int m=0;
//     int v = 0;
//     int water = 0;
//     while(l<r){
//         if(maxL<maxR){
//             l++;
//             maxL = max(height[l],maxL);
//             water += maxL - height[l];
//         }
//         else{
//             r--;
//             maxR = max(height[r],maxR);
//             water += maxR - height[r];
//         }
//     }
//     return water;
// }

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.size()<3){
        return res;
    }        
    vector<int> v;
    for(int i=0;i<nums.size()-2;i++){
        for(int j=1;j<nums.size()-1;j++){
            for(int k=2;k<nums.size();k++){
                if(i != j && i!=k && j!=k){
                    if(nums[i] + nums[j] + nums[k] == 0){
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    sort(v.begin(),v.end());
                    res.push_back(v);
                    v.clear();  
                    }
                }
                
            }
        }
    }
    set<vector<int>> s(res.begin(),res.end());
    res.assign(s.begin(),s.end());
    return res;
}

vector <int> calculateSpan(int price[], int n)
    {
        vector<int> res;
        stack<int> s;
       for(int i=0;i<n;i++){
           while(!s.empty() && price[s.top()]<price[i]){
               s.pop();
           }
           if(s.empty()){
                s.push(i);
                res.push_back(i+1);
           }
           else{
               res.push_back(i-s.top());
               s.push(i);
           }
       }
       return res;
    }

int largestRectangleArea(vector<int>& heights) {
    vector<int> lb;
    lb.push_back(-1);
    for(int i=1;i<heights.size(); i++){
        int p = i-1;
        while(p>=0 && heights[p] >= heights[i]){
            p = lb[p];
        }
        lb.push_back(p);
    } 

    int rb[heights.size()];
    rb[heights.size()-1] = heights.size();
    for(int i=heights.size()-2;i>=0; i--){
        int p = i+1;
        while(p<heights.size() && heights[p] >= heights[i]){
            p = rb[p];
        }
        rb[i] = p;
    }

    int maxArea = INT_MIN;
    for(int i=0;i<heights.size();i++){
        int width = rb[i] - lb[i] -1;
        int area = width * heights[i];
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> res;
//     for(int i=0;i<=nums.size()-k;i++){
//         int Max = INT_MIN;
//         for(int j=i;j<i+k;j++){
//             Max = max(Max,nums[j]);
//         }
//         cout<<" ---> "<<Max<<endl;
//         res.push_back(Max);
//     }
//     return res;
// }

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    int nextGreater[nums.size()];
    nextGreater[nums.size()-1] = INT_MAX;
    for(int i=nums.size()-2;i>=0;i--){
        int p = i+1;
        while(p<nums.size() && nums[i]>=nums[p]){
            p = nextGreater[p];
        }
        nextGreater[i] = p;
    }
    
    for(int i=0;i<=nums.size()-k;i++){
        int limit = i+k;
        if(nextGreater[i]>=limit){
            res.push_back(nums[i]);
        }
        else{
            int p = i;
            while(nextGreater[p]<limit){
                p = nextGreater[p];
            }
            res.push_back(nums[p]);
        }
    }

    return res;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){ return a[0]<b[0]; });
    stack<vector<int>> s;
    s.push(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        vector<int> a = s.top();
        vector<int> b = intervals[i];
        if(b[0]<=a[1]){
            s.pop();
            s.push({a[0],max(a[1],b[1])});
        }
        else{
            s.push(b);
        }
    }
    vector<vector<int>> res;
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    sort(res.begin(),res.end());
    return res;
}

string smallestNumberFollowingPattern(string data){
    stack<int> s;
    string res="";
    int j =1;
    for(int i=0;i<data.length();i++){
        if(data[i] == 'd'){
            s.push(j);
        }
        else if(data[i] == 'i'){
            s.push(j);
            while(!s.empty()){
                res += s.top()+48;
                s.pop();
            }
        }
        j++;
    }
    
    s.push(j);
    while(!s.empty()){
        res += s.top()+48;
        s.pop();
    }
    return res;
}


int main(){
    int span[] = {1,2,3,1,2,1,2,3,9,1,1,2,3,5,1};
    // vector<int> res = calculateSpan(span,sizeof(span)/sizeof(span[0]));
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }
    // vector<int> histogram = {6,2,5,4,5,1,6};
    // cout<<"Maximium area of histogram is : "<<largestRectangleArea(histogram);


    // sliding window max
    // vector<int> data = {1,3,-1,-3,5,3,6,7};
    // vector<int> maxWindow = maxSlidingWindow(data,3);
    // for(int i=0;i<maxWindow.size();i++){
    //     cout<<maxWindow[i]<<" ";
    // }
    // vector<vector<int>> data = {{1,4},{4,5}};
    // data = merge(data);
    // for(int i=0;i<data.size();i++){
    //     for(int j=0;j<2;j++){
    //         cout<<data[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<smallestNumberFollowingPattern("ddidddid");
}