#include <vector>

template<typename T>
auto solution(std::vector<T> nums, int k) {
    // 初始化变量
    T ans = T();
    int n = nums.size();

    // 初始化窗口
    for (int i = 0; i < k; i++) {
        ans += nums[i];
    }

    // 滑动窗口
    for (int i = k; i < n; i++) {
        int OUT = i - k, IN = i;
        ans += nums[IN];
        ans -= nums[OUT];
    }
    
    return ans;
}