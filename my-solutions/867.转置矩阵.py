#
# @lc app=leetcode.cn id=867 lang=python3
#
# [867] 转置矩阵
#
# https://leetcode.cn/problems/transpose-matrix/description/
#
# algorithms
# Easy (69.10%)
# Likes:    300
# Dislikes: 0
# Total Accepted:    139.2K
# Total Submissions: 201.4K
# Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
#
# 给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。
# 
# 矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
# 
# 
# 
# 
# 
# 示例 1：
# 
# 
# 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
# 输出：[[1,4,7],[2,5,8],[3,6,9]]
# 
# 
# 示例 2：
# 
# 
# 输入：matrix = [[1,2,3],[4,5,6]]
# 输出：[[1,4],[2,5],[3,6]]
# 
# 
# 
# 
# 提示：
# 
# 
# m == matrix.length
# n == matrix[i].length
# 1 
# 1 
# -10^9 
# 
# 
#

# @lc code=start
class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        return [[matrix[i][j] for i in range(m)] for j in range(n)]
# @lc code=end

