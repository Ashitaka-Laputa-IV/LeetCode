#
# @lc app=leetcode.cn id=643 lang=python3
#
# [643] 子数组最大平均数 I
#
# https://leetcode.cn/problems/maximum-average-subarray-i/description/
#
# algorithms
# Easy (44.15%)
# Likes:    422
# Dislikes: 0
# Total Accepted:    209.4K
# Total Submissions: 474.3K
# Testcase Example:  '[1,12,-5,-6,50,3]\n4'
#
# 给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。
# 
# 请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。
# 
# 任何误差小于 10^-5 的答案都将被视为正确答案。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：nums = [1,12,-5,-6,50,3], k = 4
# 输出：12.75
# 解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
# 
# 
# 示例 2：
# 
# 
# 输入：nums = [5], k = 1
# 输出：5.00000
# 
# 
# 
# 
# 提示：
# 
# 
# n == nums.length
# 1 <= k <= n <= 10^5
# -10^4 <= nums[i] <= 10^4
# 
# 
#

# @lc code=start
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        tmp, ans, n= 0, 0, len(nums)
        # 初始化窗口
        ans = tmp = sum(nums[0 : k])
        # 滑动窗口: sum = sum - left + right 
        for i in range(k, n):
            tmp += nums[i] - nums[i - k]
            ans = max(tmp, ans)
        return ans / k
# @lc code=end

