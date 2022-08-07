/*
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 

Constraints:

1 <= nums.length <= 3 * 10^4
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
At most 3 * 10^4 calls will be made to update and sumRange.
*/



/*
NOTE:
    This problem uses Segment trees which is a tree DS that stores the sum of the elements in an array. Somewhat similiar to prefix sum. 
    We have used segment tree to find the sum of the elements in a range and also build and update the tree when constructor and update functions are invoked.
*/

class NumArray {
private:
    int n;
    vector<int> seg;
    
    int build(const vector<int>& nums, int left, int right, int node)
    {
        int middle, leftSum, rightSum;
        if(left == right)
            return seg[node] = nums[left];
        
        middle = (left + right)/2;
        
        leftSum = build(nums, left, middle, 2*node+1);
        rightSum = build(nums, middle+1, right, 2*node+2);
        return seg[node] = leftSum + rightSum;
    }
    
    int sumRange(int left, int right, int ss, int se, int node)
    {
        int leftSum, rightSum, middle;
        
        if(right < ss || left > se)
            return 0;
        
        if(left <= ss && se <= right)
            return seg[node];
        
        middle = (ss+se)/2;
        leftSum = sumRange(left, right, ss, middle, 2*node+1);
        rightSum = sumRange(left, right, middle+1, se, 2*node+2);
        
        return leftSum + rightSum;
    }
    
    int update(int index, int val, int ss, int se, int node)
    {
        int leftSum, rightSum, middle;
        
        if(index<ss || index>se)
            return seg[node];
        
        if(ss==se)
            return seg[node]=val;
        
        middle = (ss+se)/2;
        leftSum = update(index, val, ss, middle, 2*node+1);
        rightSum = update(index, val, middle+1, se, 2*node+2);
        
        return seg[node] = leftSum + rightSum;
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        build(nums, 0, n-1, 0);
    }
    
    void update(int index, int val) {
        update(index, val, 0, n-1, 0);
    }
    
    int sumRange(int left, int right) {
        return sumRange(left, right, 0, n-1, 0);
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
