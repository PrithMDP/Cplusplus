//
//  main.cpp
//  Binary-Search
//
//  Created by Lionel Messi on 6/13/15.
//  Copyright (c) 2015 Lionel Messi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int binarysearch(vector<int> &vec, int num);
int binarysearchfirst(vector<int>&vec,int num); //finding first time a number appears
int binarysearchlast(vector<int>&vec,int num);

int main(int argc, const char * argv[])
{
    vector<int> vec;
    vec.reserve(100);
    for (int i=0; i<100; i++) {
        vec.push_back(i);
    }
    
    cout<<binarysearch(vec, 99)<<endl;
    vec[42]=40;
    vec[41]=40;
    vec[40]=40;
    vec[39]=40;
    vec[38]=40;
    vec[37]=40;
    //cout<<vec[48]<<vec[49]<<vec[50]<<endl;
    //cout<<binarysearchfirst(vec, 40)<<endl;
    //cout<<binarysearchlast(vec, 40)<<endl;

    return 0;
}

int binarysearch(vector<int> &vec, int num)
{
    int left=0;
    int right=int(vec.size())-1;
    while (left<=right) {
        cout<<left<<" "<<right<<endl;
        int mid=(left+right)/2;
        cout<<mid<<endl;
        if(num==vec[mid])
        {
            return mid;
        }
        else if(num>vec[mid])
        {
            left=mid+1;
        }
        else    //num<mid
        {
            right=mid-1;
        }
    }
    cout<<"num not in the vector\n";
    return -1;
}

//find first occourance of a number in a sorted array, given repititions
int binarysearchfirst(vector<int>&vec,int num)
{
    int left=0;
    int right=int(vec.size())-1;
    int index=INT32_MIN;
    while (left<right-1) {
        int mid=(left+right)/2;
        
        if(num==vec[mid])
        {
            index=mid;
            right=mid;
        }
        
        else if (num<vec[mid]) {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return index;
    
}

//find last occourance of a number in a sorted array, given repititions
int binarysearchlast(vector<int>&vec,int num)
{
    int left=0;
    int right=int(vec.size())-1;
    int index=INT32_MIN;
    while (left<right-1) {
        int mid=(left+right)/2;
        
        if(num==vec[mid])
        {
            index=mid;
            left=mid;
        }
        
        else if (num<vec[mid]) {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return index;
    
}