/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.21%)
 * Likes:    2625
 * Dislikes: 0
 * Total Accepted:    519.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回 滑动窗口中的最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start

/*
方法一：优先队列

初始时，我们将数组 nums 的前 k 个元素放入优先队列中。
每当我们向右移动窗口时，我们就可以把一个新的元素放入优先队列中，此时堆顶的元素就是堆中所有元素的最大值。
然而这个最大值可能并不在滑动窗口中，在这种情况下，这个值在数组 nums 中的位置出现在滑动窗口左边界的左侧。
因此，当我们后续继续向右移动窗口时，这个值就永远不可能出现在滑动窗口中了，我们可以将其永久地从优先队列中移除。

我们不断地移除堆顶的元素，直到其确实出现在滑动窗口中。此时，堆顶元素就是滑动窗口中的最大值。
为了方便判断堆顶元素与滑动窗口的位置关系，我们可以在优先队列中存储二元组 `(num,index)`，表示元素 num 在数组中的下标为 index。
*/
/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            q.push(make_pair(nums[i], i));
        }

        vector<int> ans;
        ans.push_back(q.top().first);

        int right = k;
        int left = 0;
        while (right < nums.size()) {
            q.push(make_pair(nums[right], right));
            left = right - k;
            while (q.top().second <= left) {
                q.pop();
            }
            
            ans.push_back(q.top().first);
            right++;
        }
        return ans;
    }
};
*/

/*
方法二：单调队列

首先窗口向右滑动的过程就是将窗口最左侧的元素删除，同时在窗口的最右侧添加一个新的元素，这就要用到双端队列，然后找双端队列中的最大元素。

那剩下就是如何找到滑动窗口中的最大值。

那我们就可以只在队列中保留可能成为窗口最大元素的元素，去掉不可能成为窗口中最大元素的元素。

想象一下，如果要进来的是个值大的元素，那一定会比之前早进去的值小的元素晚离开队列，而且值大的元素在，都没值小的元素啥事，所以值小的元素直接弹出队列即可。

这样队列里其实是**维护一个单调递减的单调队列**。

本题的解法，数组被从头到尾扫描一遍，每个元素的下标最多进出队列一次，所以时间复杂度为 O(n)。

因为创建了一个额外的大小为 k 的队列存储，所以本题空间复杂度为 O(k)。
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < nums.size(); i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

/*
// 分块+预处理
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixMax(n), suffixMax(n);
        for (int i = 0; i < n; i++) {
            if (i % k == 0) {
                prefixMax[i] = nums[i];
            } else {
                prefixMax[i] = max(prefixMax[i-1], nums[i]);
            }
        }
        for (int i = n-1; i >= 0; i--) {
            if (i == n - 1 || (i+1) % k == 0) {
                suffixMax[i] = nums[i];
            } else {
                suffixMax[i] = max(suffixMax[i+1], nums[i]);
            }
        }

        vector<int> ans;
        for (int i = 0; i <= n - k; i++) {
            ans.push_back(max(suffixMax[i], prefixMax[i+k-1]));
        }
        return ans;
    }
};
*/

// @lc code=end

