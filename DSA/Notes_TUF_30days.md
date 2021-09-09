# Day1: (Arrays)
---------------------------------------------------------------
---------------------------------------------------------------
4. Kadane’s Algorithm

Ques: Maximum Subarray - Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

* Optimal Soultion using Kadane algorithm: TC: O(N), SC: O(1)
class Solution {
public:
    static int max(int a,int b)
    {
       return a>b?a:b; 
    }
    int maxSubArray(vector<int>& nums) {
        int sum = 0,maxx=nums[0];
        for(int i=0;i<nums.size();i++){ 
            sum += nums[i];
            maxx = max(sum,maxx);
             if(sum<0){
                 sum=0;
             }
        }
        return maxx;
    }
};

- The brute force approch takes O(N^3) cause we run 3 for loops as below:
for i in range(n):
    for j in range(i,n):
        sum=0
        for k in range(i,j):
            sum += a[k]       
        maxx = max(sum,maxx)

- If we need to optimize this then remove 3rd loop and then redefine sum before 2nd loop.
for i in range(n):
    sum=0
    for j in range(i,n):
        sum += a[j]       
        maxx = max(sum,maxx)

---------------------------------------------------------------

5. Merge Overlapping Subintervals (Leetcode-56)

Ques: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Solution:
In brute force approach we will maintain separate array and then 
Most Optimal: TC: O(Nlog(N))[sorting] + O(N)[loop]


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        l = []
        if len(intervals)==0:
            return l
        intervals.sort()
        minn = intervals[0][0]
        maxx = intervals[0][1]
        pair = [minn,maxx]
        for j in range(1,len(intervals)):
            if pair[1] >= intervals[j][0]:
                minn = min(intervals[j][0],minn)
                maxx = max(intervals[j][1],maxx)
                pair = [minn,maxx]
            else:
                l.append(pair)
                minn = intervals[j][0]
                maxx = intervals[j][1]
                pair = intervals[j]
        l.append(pair)
        return l
            
---------------------------------------------------------------

6. Find the duplicate in an array of N+1 integers. 

Ques: Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2


Solution:
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        d = {}
        for i in nums:
            if i in d.keys():
                return i
            else:
                d[i] = 1
        return -1

---------------------------------------------------------------
---------------------------------------------------------------
# Day2: (Arrays)
---------------------------------------------------------------
---------------------------------------------------------------
1. Set Matrix Zeros 

Ques: Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
Follow up:

    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?
Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Solution:

* Brute force:
when you get 0 then we change all values except 0 from that col and row to -1 and then just change the -1 to 0 by traversing the matrix. TC: O(N*M)*(N+M) SC: O(1)

** Code below has TC: O(N*M)*(N+M) SC: O(M+N)
class Solution:
    def getcorr(self,i,j,m,n):
        a = []
        for k in range(m):
            a.append([i,k])
        for k in range(n):
            a.append([k,j])
        return a
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        l = []
        m = len(matrix[0])
        n = len(matrix)
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    l += self.getcorr(i,j,m,n)
        for i in l:
            matrix[i[0]][i[1]] = 0
        return matrix

* Optimized 
- Take two dummy array: one size of columns and other size of row
- Then we traverse the array and if encounter 0 we mark that index of dummy column and dummy row array to 0, Then we traverse the array again and chek the indexes if at that particular index it shows 0 at any of the dummy array its 0 otherwise the number that is.
- TC: O(NM) SC: O(N+M) [due to dummy array]

* Optimizing SC to O(1)
- Take the first row and col to be dummy row and col 
- we take one col0 variable that would give us the value for the (0,0) index as it comes in both the array.
- if there is zero in any one of the 1st row or col col0 = 0 

TC: O(NM) SC: O(1)
Checkout the code :

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        col0,rows,cols = 1,len(matrix),len(matrix[0])
        for i in range(rows):
            if matrix[i][0] == 0:
                col0 = 0
            for j in range(1,cols):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0
        for i in reversed(range(rows)):
            for j in reversed(range(1,cols)):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
            if col0 == 0:
                matrix[i][0] = 0
        return matrix

Practice: https://leetcode.com/problems/game-of-life/

---------------------------------------------------------------

2. 


---------------------------------------------------------------
---------------------------------------------------------------
# Day4: (Hashing)
---------------------------------------------------------------
---------------------------------------------------------------
1. 2sums

---------------------------------------------------------------
2. 4 sums

Ques: Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:

    1 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109

Solution:

* Brute force:
 - Sort the array and then use 3 pointer and binary search.
 - take 3 pointers i ,j and k and initialize as i=0,j=i+1 and k=j+1 now target2 = target - nums[i] - nums[j] - nums[k]
 - now perform a binary search from k+1 to n for target2.
 - repeat for all i,j,k. also check for duplicate.
 - TC: N^3log(N) where N^3 is for 3 loops and log(N) for binary search.
 - SC: O(1) as we don't calculate the space of the result array.

* Optimized approach
- Sort the array and use two pointers i,j.
- initialize i=0 and j=i+1.
- now target2 = target - nums[i] - nums[j]
- now take two pointers front and back and initialize them as front = j+1 and back = n-1
- now iterate while front < back. If yes then calculate sum = nums[front] + nums[back].
- if sum == target2 then insert the quad [i,j,front,back] into result.
- now to avoid duplicate increment front and back until they are not equal to the previous values.
- same thing for j and i.
- TC: N^3 for the 3 loops 
- SC: O(1)

Code:

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.empty())   {
            return res;
        }
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for( int i = 0 ; i < n-1 ; i++ )  {
            for ( int j = i+1 ; j < n ; j++)    {
                int target_2 = target - nums[i] - nums[j];
                int front = j+1;
                int back = n-1;
                while(front < back) {
                    int sum = nums[front] + nums[back];
                    if (sum < target_2) {
                        front++;
                    }
                    else if(sum > target_2) {
                        back--;
                    }
                    else    {
                        vector <int> quad;
                        quad.push_back(nums[i]);
                        quad.push_back(nums[j]);
                        quad.push_back(nums[front]);
                        quad.push_back(nums[back]);
                        res.push_back(quad);
                        while(front < back && nums[front] == quad[2]) ++front;
                        while(front < back && nums[back] == quad[3]) --back;
                    }
                }
                while(j+1 < n && nums[j+1] == nums[j]) ++j;
            }
            while(i+1 < n-1 && nums[i+1] == nums[i]) ++i;
        }
        return res;
    }
};

---------------------------------------------------------------
3. Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109

Solution:

* Brute force:
 - Sort the array.
 - Initialize a counter c = 1 and max_seq = -1 
 - iterate over the array and and check for sequence and get the max sequence.
 - TC: O(Nlog(N)) + O(N) where nlog(n) is for the sort. 

Code:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())   {
            return 0;
        }
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int max_seq = -1;
        int c = 1;
        for(int i = 0 ; i < n-1 ; i++) {
            if(nums[i+1] - nums[i] == 1)    c++;
            else if(nums[i+1] - nums[i] == 0)   {
                continue;
            }
            else    {
                if (max_seq <= c)    {
                    max_seq = c;  
                }
                c = 1;
            }   
        }
        if (max_seq <= c)    {
            max_seq = c;
        }
        return max_seq;
    }
};

* Optimized approach
- Declare a hashset and insert all elements in the hashset.
- now iterate over the array and check if num-1 is present in hashset. if present then do nothing
- if element is not present then initialize count =1, current number = num and then check and increase count until curr+1 is present in the hashset. 
- TC: O(n) + O(n) + O(n) = O(3n) 
- SC: O(n)

Code:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())   {
            return 0;
        }
        int max_seq = 0;
        set<int> hashSet;
        for (int num : nums)   {
            hashSet.insert(num);
        }
        for(int num:nums){
            if(!hashSet.count(num-1))   {
                int count = 1;
                int curr = num;
                while(hashSet.count(curr+1)) {
                    count++;
                    curr++;
                }
                max_seq = max(max_seq,count);
            }
        }
        return max_seq;
    }
};

---------------------------------------------------------------
4. 
