// **********SOLVING QUESTIONS FROM HERE**********

// Questions are filtered on leet code as Array + Easy
// q1. Search Insert from leet code
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {   
//         int low = 0;
//         int high = nums.size()-1;
//         int mid;
//         while(low<=high)
//         {
//             mid = low + (high-low)/2;
//             if(nums[mid]==target)
//                 return mid;
//             else if(nums[mid]<target)
//                 low = mid+1;
//             else
//                 high = mid-1;
//         }
//         return low;
//     }
// };
// ***********Using Kadane’s Algo***********
// q2. Maximum Sum of Sub array
//   int size = nums.size();
//         int max_so_far = INT_MIN, max_ending_here = 0;
        
//         for(int i = 0; i < size; i++){
//             max_ending_here += nums[i]; 
//             if(max_so_far<max_ending_here)
//                 max_so_far = max_ending_here;
//             if(max_ending_here<0)
//                 max_ending_here = 0;
//         }
//         return max_so_far;






