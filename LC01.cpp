#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// print
void print(vector<int> ans)
{
    for(auto i : ans)
        cout << i << " "<< endl;
    cout << endl;
}

// O(n2)
vector<int> solve(vector<int> &nums,int target){
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for(int j = i + 1;j < n;j++)
        {
            if(nums[i] + nums[j] == target)
                return {i,j};
        }
    }
    return {};
}

// 0(n)
vector<int> solve2(vector<int> &nums,int target)
{
    int n = nums.size();
    for(int i = 0;i < n - 1;i++)
    {
        if(nums[i] + nums[i + 1] == target)
            return {i,i + 1};
    }
    return {}; 
}

// 0(log n)
vector<int> solve3(vector<int> &nums,int target)
{
    int n = nums.size();
    vector<pair<int,int>>nk;
    
    for(int i = 0;i < n;i++)
    {
        nk.push_back({nums[i],i});
    }
    
    sort(nk.begin(),nk.end());
    
    int start  = 0;
    int end = n - 1;
    
    while(start < end)
    {
        int sum = nk[start].first + nk[end].first;
        
        if(target == sum)
            return {nk[start].second,nk[end].second};
        if(sum > target)
            end--;
        else
            start++;
    }
    return {};
}

// 0(1)
vector<int> solve4(vector<int>&nums,int target)
{
    int n = nums.size();
    unordered_map<int,int> mp;

    for(int i = 0;i < n;i++){
        int diff = target - nums[i];
        if(mp.find(diff) != mp.end())
            return {mp[i],i};
        mp[i] = i;
    }
    return {};
}


int main()
{
    vector<int> a = {3,2,4};
    int target = 6;
    
    vector<int> ans = solve3(a,target);
    print(ans);
    return 0;
} 