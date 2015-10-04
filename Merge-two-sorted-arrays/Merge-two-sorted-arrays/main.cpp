//
//  main.cpp
//  Merge-two-sorted-arrays
//
//  Created by Lionel Messi on 6/14/15.
//  Copyright (c) 2015 Lionel Messi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 Merge 2 sorted arrays
start at begining of the arrays and then add to new array depending on which index value is smaller
 
 
 */
void printvec(vector<int> nums);
void mergesorted(vector<int>& nums1,vector<int>& nums2, vector<int>& result);
int main(int argc, const char * argv[])
{
    vector<int> nums1;
    vector<int> nums2;
    for (int i=0; i<10; i+=2) {
        nums1.push_back(i);
    }
    for (int i=1; i<10; i+=2) {
        nums2.push_back(i);
    }
    
    printvec(nums1);
    printvec(nums2);
    
    vector<int>result;
    
    mergesorted(nums1, nums2, result);
    cout<<endl;
    printvec(result);
    return 0;
}


void printvec(vector<int> nums)
{
    for (int i=0; i<nums.size(); i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    
}


void mergesorted(vector<int>& nums1,vector<int>& nums2, vector<int>& result)
{
    int i=0;
    int j=0;
    while (i<nums1.size() && j<nums2.size()) {
        
        if (nums1[i] < nums2[j])
        {
            result.push_back(nums1[i]);
            i++;
        }
        else
        {
            result.push_back(nums2[j]);
            j++;
        }
    }
    if (i==nums1.size())
    {
        for (j; j<nums2.size(); j++) {
            result.push_back(nums2[j]);
        }
    }
    else if (j==nums2.size())
    {
        for (i; i<nums1.size(); i++) {
            result.push_back(nums1[i]);
        }
    }

}