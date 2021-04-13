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

Ques: 
Solution:

* Brute force:
when you get 0 then we change all values except 0 from that col and row to -1 and then just change the -1 to 0 by traversing the matrix. TC: O(N*M)*(N+M) SC: O(1)
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
