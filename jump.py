def jump(nums: list[int]) -> int:
    '''
    Jump Game II leetcode problem 45
    You are given a 0-indexed array of integers nums of length n.
    You are initially positioned at nums[0].
    Each element nums[i] represents the maximum length of a 
    forward jump from index i. In other words, if you are at nums[i], 
    you can jump to any nums[i + j] where:
        0 <= j <= nums[i] and
        i + j < n
    Return the minimum number of jumps to reach nums[n - 1]. 
    The test cases are generated such that you can reach nums[n - 1].
    '''
    def minJumps_to(i):
        # Base case when you can't jump further
        if i == 0:
            return 0
        j = 0
        # See how far we can jump from j
        while nums[j] + j < i:
            j += 1
        # We've completed 1 jump, start from wherever j is
        return minJumps_to(j) + 1
    return minJumps_to(len(nums)- 1)

print(jump([1]), jump([2, 3, 0, 1, 4]), jump([2, 3, 1, 1, 4]))