# You are given an integer array nums and an integer target.

# You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

# For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
# Return the number of different expressions that you can build, which evaluates to target.

# Example 1:

# Input: nums = [1,1,1,1,1], target = 3
# Output: 5
# Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
# -1 + 1 + 1 + 1 + 1 = 3
# +1 - 1 + 1 + 1 + 1 = 3
# +1 + 1 - 1 + 1 + 1 = 3
# +1 + 1 + 1 - 1 + 1 = 3
# +1 + 1 + 1 + 1 - 1 = 3
# Example 2:

 

# Input: nums = [1], target = 1
# Output: 1

 

# Test case 1: [1,2,3,2,1,2,3,2,1,2,3,2,1] target=6 
# Test case 2: [2,2,2,2,2,2,2,2,2] target = 6

class Solution:    
    def findTargetSumWays(self, nums: List[int], target: int) -> int:      
        def dfs(index=0, total=0):          
            if index == len(nums): 
				# 2
                return 1 if total == target else 0
            else:
				# 
                return dfs(index+1, total + nums[index]) + dfs(index+1, total - nums[index])                                                               

        return dfs()