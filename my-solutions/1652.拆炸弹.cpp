/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 *
 * https://leetcode.cn/problems/defuse-the-bomb/description/
 *
 * algorithms
 * Easy (71.46%)
 * Likes:    207
 * Dislikes: 0
 * Total Accepted:    77.5K
 * Total Submissions: 108.5K
 * Testcase Example:  '[5,7,1,4]\n3'
 *
 * 你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 n 的 循环 数组 code 以及一个密钥 k 。
 * 
 * 为了获得正确的密码，你需要替换掉每一个数字。所有数字会 同时 被替换。
 * 
 * 
 * 如果 k > 0 ，将第 i 个数字用 接下来 k 个数字之和替换。
 * 如果 k < 0 ，将第 i 个数字用 之前 k 个数字之和替换。
 * 如果 k == 0 ，将第 i 个数字用 0 替换。
 * 
 * 
 * 由于 code 是循环的， code[n-1] 下一个元素是 code[0] ，且 code[0] 前一个元素是 code[n-1] 。
 * 
 * 给你 循环 数组 code 和整数密钥 k ，请你返回解密后的结果来拆除炸弹！
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：code = [5,7,1,4], k = 3
 * 输出：[12,10,16,13]
 * 解释：每个数字都被接下来 3 个数字之和替换。解密后的密码为 [7+1+4, 1+4+5, 4+5+7, 5+7+1]。注意到数组是循环连接的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：code = [1,2,3,4], k = 0
 * 输出：[0,0,0,0]
 * 解释：当 k 为 0 时，所有数字都被 0 替换。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：code = [2,4,9,3], k = -2
 * 输出：[12,5,6,13]
 * 解释：解密后的密码为 [3+9, 2+3, 4+2, 9+4] 。注意到数组是循环连接的。如果 k 是负数，那么和为 之前 的数字。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == code.length
 * 1 
 * 1 
 * -(n - 1) 
 * 
 * 
 */
using namespace std;
#include <vector>
// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        
        if (k == 0) {
            return ans;
        }
        
        // 统一处理 k > 0 和 k < 0 的情况
        int w = abs(k);
        int tmp = 0;
        
        // 初始化第一个窗口
        if (k > 0) {
            // k > 0: 计算当前元素后面k个元素的和
            for (int i = 1; i <= w; i++) {
                tmp += code[i % n];
            }
        } else {
            // k < 0: 计算当前元素前面k个元素的和
            for (int i = n - w; i < n; i++) {
                tmp += code[i];
            }
        }
        
        ans[0] = tmp;
        
        // 滑动窗口
        for (int i = 1; i < n; i++) {
            if (k > 0) {
                // 移除左边元素：code[i]
                // 添加右边元素：code[(i + w) % n]
                tmp = tmp - code[i] + code[(i + w) % n];
            } else {
                // 移除左边元素：code[(i - w - 1 + n) % n]  
                // 添加右边元素：code[i - 1]
                tmp = tmp - code[(i - w - 1 + n) % n] + code[i - 1];
            }
            ans[i] = tmp;
        }
        
        return ans;
    }
};
// @lc code=end

