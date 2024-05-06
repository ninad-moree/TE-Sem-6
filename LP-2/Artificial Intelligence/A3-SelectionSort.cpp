#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& nums) {
    for(int i=0; i<nums.size()-1; i++) {
        int minIdx = i;
        for(int j=i+1; j<nums.size(); j++) {
            if(nums[minIdx] > nums[j])
                minIdx = j;
        }

        int temp = nums[i];
        nums[i] = nums[minIdx];
        nums[minIdx] = temp;
    }
}