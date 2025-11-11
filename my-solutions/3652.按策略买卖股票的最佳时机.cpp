/*
 * @lc app=leetcode.cn id=3652 lang=cpp
 *
 * [3652] 按策略买卖股票的最佳时机
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-using-strategy/description/
 *
 * algorithms
 * Medium (44.06%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 15K
 * Testcase Example:  '[4,2,8]\n[-1,0,1]\n2'
 *
 * 给你两个整数数组 prices 和 strategy，其中：
 * 
 * 
 * prices[i] 表示第 i 天某股票的价格。
 * strategy[i] 表示第 i 天的交易策略，其中：
 * 
 * -1 表示买入一单位股票。
 * 0 表示持有股票。
 * 1 表示卖出一单位股票。
 * 
 * 
 * 
 * 
 * 同时给你一个 偶数 整数 k，你可以对 strategy 进行 最多一次 修改。一次修改包括：
 * 
 * 
 * 选择 strategy 中恰好 k 个 连续 元素。
 * 将前 k / 2 个元素设为 0（持有）。
 * 将后 k / 2 个元素设为 1（卖出）。
 * 
 * 
 * 利润 定义为所有天数中 strategy[i] * prices[i] 的 总和 。
 * 
 * 返回你可以获得的 最大 可能利润。
 * 
 * 注意： 没有预算或股票持有数量的限制，因此所有买入和卖出操作均可行，无需考虑过去的操作。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： prices = [4,2,8], strategy = [-1,0,1], k = 2
 * 
 * 输出： 10
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 修改
 * 策略
 * 利润计算
 * 利润
 * 
 * 
 * 
 * 
 * 原始
 * [-1, 0, 1]
 * (-1 × 4) + (0 × 2) + (1 × 8) = -4 + 0 + 8
 * 4
 * 
 * 
 * 修改 [0, 1]
 * [0, 1, 1]
 * (0 × 4) + (1 × 2) + (1 × 8) = 0 + 2 + 8
 * 10
 * 
 * 
 * 修改 [1, 2]
 * [-1, 0, 1]
 * (-1 × 4) + (0 × 2) + (1 × 8) = -4 + 0 + 8
 * 4
 * 
 * 
 * 
 * 
 * 因此，最大可能利润是 10，通过修改子数组 [0, 1] 实现。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： prices = [5,4,3], strategy = [1,1,0], k = 2
 * 
 * 输出： 9
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 
 * 修改
 * 策略
 * 利润计算
 * 利润
 * 
 * 
 * 
 * 
 * 原始
 * [1, 1, 0]
 * (1 × 5) + (1 × 4) + (0 × 3) = 5 + 4 + 0
 * 9
 * 
 * 
 * 修改 [0, 1]
 * [0, 1, 0]
 * (0 × 5) + (1 × 4) + (0 × 3) = 0 + 4 + 0
 * 4
 * 
 * 
 * 修改 [1, 2]
 * [1, 0, 1]
 * (1 × 5) + (0 × 4) + (1 × 3) = 5 + 0 + 3
 * 8
 * 
 * 
 * 
 * 
 * 因此，最大可能利润是 9，无需任何修改即可达成。
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= prices.length == strategy.length <= 10^5
 * 1 <= prices[i] <= 10^5
 * -1 <= strategy[i] <= 1
 * 2 <= k <= prices.length
 * k 是偶数
 * 
 * 
 */
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {    
public: 
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        // 初始化参数
        int n = prices.size();
        // 修复1：inner_product 使用 0LL
        long long total = inner_product(prices.begin(), prices.end(), strategy.begin(), 0LL);

        // 初始化窗口
        long long left = 0, right = 0, opt = 0;

        for (int i = 0; i < k / 2; i++) {
            // 修复2：确保所有乘法都是 long long
            left += (long long)strategy[i] * -1 * prices[i];
        }
        for (int i = k / 2; i < k; i++) {
            if (strategy[i] == -1) {
                right += (long long)prices[i] * 2;
            }
            else if (strategy[i] == 0) {
                right += (long long)prices[i];
            } 
            // strategy[i] == 1 时不做操作
        }
        opt = max(opt, left + right);

        // 滑动窗口
        for (int i = k; i < n; i++) {  
            int LEFT_OUT = i - k;
            int LEFT_IN = i - k + k / 2;
            int RIGHT_OUT = i - k / 2;  
            int RIGHT_IN = i;

            // 修复3：left 计算中的乘法也转换为 long long
            left += (long long)strategy[LEFT_IN] * -1 * prices[LEFT_IN] 
                  - (long long)strategy[LEFT_OUT] * -1 * prices[LEFT_OUT];
            
            if (strategy[RIGHT_IN] == -1) {
                right += (long long)prices[RIGHT_IN] * 2;
            }
            else if (strategy[RIGHT_IN] == 0) {
                right += (long long)prices[RIGHT_IN];
            }
            
            if (strategy[RIGHT_OUT] == -1) {
                right -= (long long)prices[RIGHT_OUT] * 2;
            }
            else if (strategy[RIGHT_OUT] == 0) {
                right -= (long long)prices[RIGHT_OUT];
            }
            
            opt = max(opt, left + right);
        }

        return total + opt;
    }
};
// @lc code=end

