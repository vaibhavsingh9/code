#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// *********SOLVING THE QUESTIONS FROM HERE*********
// q1.reverse an array
// void reverse(int arr[], int n){
//     int i = 0, j = n-1;
//     while (i<j){
//         swap(arr[i],arr[j]);
//         i++; j--;
//     }
//     // return arr;
// }
// int main(){
//     int n; cout<<"Input the size: "; cin>>n;
//     int arr[n];
//     for(int i = 0; i < n; i++){
//         cin>>arr[i];
//     }
//     reverse(arr,n);
//     for(int i= 0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
// return 0;
// }
// *********SOLVING THE QUESTIONS FROM HERE*********
// q2.find max and min element in array
// int main(){
//     int n; cout<<"Input the size: "; cin>>n;
//     int arr[n];
//     for(int i = 0; i < n; i++){
//         cin>>arr[i];
//     }
//     for(int i= 0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
//     //finding min and max element using STL:
//     // cout<<*max_element(arr,arr+n);
//     // cout<<*min_element(arr,arr+n);
// return 0;
// }

// *********SOLVING THE QUESTIONS FROM HERE*********
// q3.Q1 From LEETCODE TwoSum Problem
// class Solution {
// public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//       map<int, int> map;
//       vector<int> pairs;
//       for(int i = 0; i < nums.size(); i++) {
//           int complement = target - nums[i];
//           if(map.find(complement) != map.end()) {
//               pairs.push_back(map.find(complement)->second);
//               pairs.push_back(i);
//               break;
//           }
//           map.insert(pair<int, int>(nums[i], i));
//       }
//       return pairs;
//    }
// };











