/*
 * @lc app=leetcode.cn id=3694 lang=cpp
 *
 * [3694] 删除子字符串后不同的终点
 *
 * https://leetcode.cn/problems/distinct-points-reachable-after-substring-removal/description/
 *
 * algorithms
 * Medium (56.42%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    2.5K
 * Total Submissions: 4.4K
 * Testcase Example:  '"LUL"\n1'
 *
 * 给你一个由字符 'U'、'D'、'L' 和 'R' 组成的字符串 s，表示在无限的二维笛卡尔网格上的移动。
 * 
 * 
 * 'U': 从 (x, y) 移动到 (x, y + 1)。
 * 'D': 从 (x, y) 移动到 (x, y - 1)。
 * 'L': 从 (x, y) 移动到 (x - 1, y)。
 * 'R': 从 (x, y) 移动到 (x + 1, y)。
 * 
 * 
 * 你还得到了一个正整数 k。
 * 
 * 你 必须 选择并移除 恰好一个 长度为 k 的连续子字符串 s。然后，从坐标 (0, 0) 开始，按顺序执行剩余的移动。
 * 
 * 返回可到达的 不同 最终坐标的数量。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入：s = "LUL", k = 1
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 移除长度为 1 的子字符串后，s 可以是 "UL"、"LL" 或 "LU"。执行这些移动后，最终坐标将分别是 (-1, 1)、(-2, 0) 和
 * (-1, 1)。有两个不同的点 (-1, 1) 和 (-2, 0)，因此答案是 2。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：s = "UDLR", k = 4
 * 
 * 输出：1
 * 
 * 解释：
 * 
 * 移除长度为 4 的子字符串后，s 只能是空字符串。最终坐标将是 (0, 0)。只有一个不同的点 (0, 0)，因此答案是 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入：s = "UU", k = 1
 * 
 * 输出：1
 * 
 * 解释：
 * 
 * 移除长度为 1 的子字符串后，s 变为 "U"，它总是以 (0, 1) 结束，因此只有一个不同的最终坐标。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只包含 'U'、'D'、'L' 和 'R'。
 * 1 <= k <= s.length
 * 
 * 
 */
#include <unordered_map>
#include <unordered_set>
#include <string>
 using namespace std;
// @lc code=start
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()(p.first * 1LL + p.second * 1LL);
    }
};

class Solution {
public:
    int distinctPoints(string s, int k) {
        // 设置参数
        int n = s.size();
        unordered_map<char, pair<int, int>> c2a = {{'U',{0,1}},{'D',{0,-1}},{'L',{-1,0}},{'R',{1,0}}};
        pair<int, int> tmp = {0, 0};
        unordered_set<pair<int, int>, PairHash> ans;
        ans.reserve(n - k + 1);

        // 初始化窗口
        for (int i = 0; i < k; i++) {
            tmp.first += c2a[s[i]].first;
            tmp.second += c2a[s[i]].second;
        }
        ans.insert(tmp); 

        // 滑动窗口
        for (int i = k; i < n; i++) {
            tmp.first += c2a[s[i]].first - c2a[s[i-k]].first;
            tmp.second += c2a[s[i]].second - c2a[s[i-k]].second;
            ans.insert(tmp);
        }
        
        return ans.size();
    }
};
// @lc code=end

