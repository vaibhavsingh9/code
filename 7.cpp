#include<bits/stdc++.h>
using namespace std;

/*String Solution for 450 DSA Sheet:*/
// Q1.) Best Time to sell stock

class Solution{
    public:
        void sell(vector<string> &str){
            int minPrice = INT_MAX;
            int maxProfit = 0;
            for(int i = 0; i < str.size(); i++){
                if(str[i]<minPrice){
                    minPrice = str[i];
                }
                else if((str[i]-minPrice)>maxProfit){
                    maxProfit = str[i]-minPrice;
                }
            }
        }
};

// Q2.) Merge Intervals for two sorted Arrays:

class Solution{
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merge;
        for(auto itr: intervals){
            if(merge.empty()||merge.back()[1] < itr[0]){
                merge.push_back(itr);
            }
            else{
                merge.back()[1] = max(merge.back()[1],itr[1]);
            }
        }
        return merge;
    }
}

// Q3.) Kadane Algorithm Maximum SubArray Sum:

int subArray(int arr[], int n){
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    for(int i = 0; i < n; i++){
        maxEndingHere += arr[i];
        if(maxSoFar<maxEndingHere)
            maxSoFar = maxEndingHere;
        if(maxEndingHere<0)
            maxEndingHere = 0;
    }
    return maxSoFar;
}

// Q4. ) Merging Two sorted(increasing order) Array's 
//       without using O(1) Extra Space: (Can be done using
//       **GAP** Algorithm also)

int mergeTwoArray(int arr1[], int arr2[], int m, int n ){
    int i = 0, int j = 0, int k = n-1;
    while(j<n||i<=k){
        if(arr[i]<arr[j]){
            i++;
        }
        else{
            swap(arr2[j++],arr1[k--]);  //if the arr2 element is bigger 
                                        //then shift it to the last of arr1 using pointer k
        }
        sort(arr1,arr1+m);//then for proper application again sort both the arrays
        sort(arr2,arr2+n);//requires O( nlog n + mlog m ) == O(n+m)(log(n+m))
    }
}

// Q5. )   Array's kth Smallest/ largest Element using Random QuickSelect:
        // As normal QuickSelect fails here so we use Rand() QuickSelect

int kthSmallestElement( int arr[], int l, int r, int k){
    if(k>0 && k<=r-l+1){
        int pos = randPartition(arr,l,r);

        if(pos - l == k - 1)
            return arr[pos];
        if(pos - l > k - 1)
            return kthSmallestElement(arr, l, pos-1, k);
        
        return kthSmallestElement(arr, pos+1, k-pos+l-1);
    }
    return INT_MAX;
}

int partition(){
    int i = l;
    int x = arr[r];
    for(int j = l; j <= r-1; j++){
        if(arr[j] < x)
        {
            swap( &arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int randPartition(int arr[], int l, int r){
    int n = r - l + 1;
    int pivot = rand() % n;     //this makes the time complexity better in worst case O(N)
    swap( &arr[pivot - l], &arr[r]);
    return partition(arr,l,r);
}

// Q6.) Sort 0 , 1 , 2 in linear time:

void sort012(int arr[], int n){
    int low = 0, mid = 0, high = n-1;
    while( mid <= high ){
        switch (arr[mid])
        {
        case : 0
            swap( &arr[low++], &arr[mid++] );
            break;
        case : 1
            mid++;
            break;
        case : 2
            swap( &arr[mid], &arr[high--] );
            break;
        }
    }
}

// Q7. ) Moving all elements (-ve) to one side of array and (+ve) to one side

int moveNegatives(int arr[], int n){
    int j = 0;
    for( int i = 0; i < n; i++ ){
        if(arr[i]<0)
            {
                if( i != j )
                    swap(arr[i],arr[j]);
            }
            j++;
    }
}

// Q8. ) Finding Union and Intersection of two arrays using sets.

int doUnion(int arr1[], int m, int arr2[], int n){
    set<int> s;
    for(int i = 0; i < m; i++){
        s.insert(arr1[i]);
    }
    for(int i = 0; i < n; i++){
        s.insert(arr2[i]);
    }
    return s.size();
}

// Second part for this is Intersection which is done through hashing

int intersection(int arr1[], int m, int arr2[], int n){
    set<int> s;
    for(int i = 0; i < m; i++){
        s.insert(arr1[i]);
    }
    for(int i = 0; i < n; i++){
        if(s.find(arr2[i]) != s.end())
            s.insert(arr2[i]);
    }
}

// Q9. ) cyclically rotate an array
int rotation(int arr[], int n){
    int x = arr[n-1];
    for(int i = 1; i < n; i++){
        arr[i] = arr[i-1];
    }
    arr[0] = x;
}

// Q.10 ) Largest contiguous Sub Array with maximum sum
        // which is direct implementation of Kadane Algo

int subSumArray(int arr[], int n){
    int maxEnd = 0, maxFar = INT_MIN;
    for(int i = 0; i < n; i++){
        maxEnd += arr[i];
        if(maxFar < maxEnd){
            maxFar = maxEnd;
        }
        if(maxEnd<0)
            maxEnd = 0;
    }
    return maxFar;
}

// Q11.) Minimize the Heights II possible minimum difference 
       //of height by 

int kDiff(int arr[], int n, int k){
    sort(arr, arr+n);
    // function to find the minimum possible difference
    // between maximum and minimum elements when we have to
    // add/subtract every number by k
    int maxEle, minEle; 
    int result = arr[n-1] - arr[0]; //maximum difference stored
    for(int i = 1; i <= n - 1; i++){
        if(arr[i] >= k && arr[ n-1 ] >= k){
            maxEle = max(arr[i-1] + k, arr[n-1] -k);
            minEle = min(arr[0] + k, arr[i] - k);
            result = min(result, maxEle - minEle);
        }
    }
    return result;
}

// Q12. ) Minimum number of jumps required to reach end 
        // end of an Array

int minJump(int arr[], int n){
    
    if( n <= 1 )    return 0;
    if( n == 0 )  return 1;
    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;
    for (int i = 1; i < n; i++){
        if( i == n-1 ){
            return jump;
        }
        maxReach = max(maxReach, arr[i]+i);
        step--;
        if(step == 0){
            jump++;
            if( i >= maxReach)
                return -1;
            step = maxReach - i;
        }
    }
    return -1;
}

// Q13.) Finding the Duplicate number in Array using 
      // Linked List Cycle method, Floyd Tortoise Method
    //   Map Approach is also considered. LeetCode No. 287

int findDup(vector<int> &nums){
    map<int,int> mp;
    for(int i = 0; i < nums.size(); i++){
        mp[nums[i]] = mp[nums[i]]+1;
        if(mp[nums[i]] > 1 && mp[nums[i]] < 3)
            return mp[nums[i]];
    }
    return 0;
}
// Floyd Totoise method
int findDup_tortoise_method(vector<int> &nums){
    int slow = nums[0];
    int fast = nums[0];
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);
    fast = nums[0];
    while(slow != fast ){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

// /*Matrix Part Begining*/

// Q 14.) printing a matrix in spiral GFG
// This is my solution but the questions 
// on the site requires 2D vector based solution
// I couldn't understand it so didn't write it.

// below is very intutive solution.
void Matrix(int arr[R][C], int i, int j, int m, int n){
    
    if( i >= m || j >= n){
        return;
    }
    for(int p = j; p < n; i++){
        cout<<arr[0][p];
    }
    for(int p = i+1; p < m; p++){
        cout<<arr[p][n-1];
    }
    if( (m-1) != i ){
        for(int p = n-2; p >= j; p--){
            cout<<arr[m-1][p];
        }
    }
    if((n-1) != j){
        for(int p = m-2; p > i; p--){
            cout<<arr[p][j];
        }
    }
    Matrix(arr,i+1,j+1,m-1,n-1);
}

// Q.15 ) Searching an element in matrix in which is 
        // row-wise sorted and column wise GFG problem

int matrix(int mat[4][4], int n, int search){
    int (n==0){
        return 0;
    }
    int smallest = mat[0][0], largest[n-1][n-1];
    if(x < smalles || x > largest)
        return 0;
    int i = 0; 
    int j = n-1;
    while( i < n && j >= 0 ){
        if( x == mat[i][j]){
            return 1;
        }
        if( x < mat[i][j]){
            j--;
            return 1;
        }
        else
            i++;
    }
    return 0;
}

// same problem on LeetCode with condition that the first 
// element in second row is greater than the last element 
// of first row. Problem number 74

bool searchMatrix(vector<vector<int>> &matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, high = (n*m)-1;
    while ( low <= high)
    {
        int mid = (low + (high - low)/2);
        if(matrix[mid/m][mid%m] == target)
            return true;
        if(matrix[mid/m][mid%m] < target)
            low = mid + 1;
        else
            r = mid - 1;
    }
    return false;
    
}

// Q16. ) finding median in a row-wise sorted matrix
// O(32 * r * log(c))
int med(vector<vector<int>> &matrix, int r, int c){
    //giving the minimum and maximum elements for
    //comparisions
    int min = INT_MAX, max = INT_MIN;


    for(int i = 0; i < r; i++){
        if(matrix[i][0] < min){
            min = matrix[i][0];
        }
        if(matrix[i][c-1] > max){
            max = matrix[i][c-1];
        }
    }
    int desired = (r*c+1)/2;
    while(min < max){
        int mid = min + (max - min)/2;
        int place = 0;

        for(int i = 0; i < r; ++i){
            place += upper_bound(matrix[i], matrix[i]+c, mid) - matrix[i];
        }
        if(place < desired)
            min = mid + 1;
        else
            max  = mid;
    }
    return min;
}

// Q15.) finding maximum number of one's present in a row of
    // column wise sorted matrix

int max1(vector<vector<int>> &mat, int M, int N){
    int i = 0, j = N-1;
    int row = -1;
    while(i <= M-1 && j >= 0){
        if(mat[i][j]){
            row = i;
            j--;
        }
        else
            i++;
    }
    return row;
}

// Q16.) printing the sorted matrix

vector<vector<int>> sortMat(vector<vector<int>> mat, int N){
    int temp[N*N];
    int k = 0;
    for(int i =0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp[k++] = mat[i][j];
        }
    }
    sort(temp, temp+k); // sorting the aux array.
    vector<vector<int>> v;
    for(int i = 0; i < N; i++){
        vector<vector<int>> v1;
        for(int j = 0; j < N; j++){
            v1.push_back(temp[k++]) //add the first vector
                                    //key kind of for the dict
        }
        v.push_back(v1); //very important a basic method for 
                        //for adding 2D vectors, adding
                        //value in the 2d vector {{0,1,2},{223,45,2},......}
    }
}
