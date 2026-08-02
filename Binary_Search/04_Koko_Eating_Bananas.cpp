/*
==========================================================
              KOKO EATING BANANAS
==========================================================

Problem:
Find the minimum eating speed so Koko can finish
all bananas within h hours.

Approach:
- Binary Search on answer.
- Check whether a speed is feasible.

TC : O(n log(maxPile))
SC : O(1)
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h)
{
    int n=piles.size(),sum=0,maxV=INT_MIN;
    for(int i=0;i<n;i++){
        maxV=max(maxV,piles[i]);
    }

    int low=1,high=maxV,ans=-1;

    while(low<=high){
        int mid=low+(high-low)/2;
        int countSpeed=0;

        for(int i=0;i<n;i++){
            countSpeed+=(piles[i]+mid-1)/mid;
        }
        if(countSpeed>h){
            low=mid+1;
        }else{
            ans=mid;
            high=mid-1;
        }
    }

    return ans;
}

int main()
{
    vector<int> piles = {3,6,7,11};

    cout << minEatingSpeed(piles,8);

    return 0;
}