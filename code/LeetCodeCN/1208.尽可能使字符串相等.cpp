/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 *
 * https://leetcode.cn/problems/get-equal-substrings-within-budget/description/
 *
 * algorithms
 * Medium (50.09%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    71.8K
 * Total Submissions: 143.3K
 * Testcase Example:  '"abcd"\n"bcdf"\n3'
 *
 * 给你两个长度相同的字符串，s 和 t。
 * 
 * 将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII
 * 码值的差的绝对值。
 * 
 * 用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。
 * 
 * 如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。
 * 
 * 如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abcd", t = "bcdf", maxCost = 3
 * 输出：3
 * 解释：s 中的 "abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abcd", t = "cdef", maxCost = 3
 * 输出：1
 * 解释：s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为 1。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "abcd", t = "acde", maxCost = 0
 * 输出：1
 * 解释：a -> a, cost = 0，字符串未发生变化，所以最大长度为 1。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * s 和 t 都只含小写英文字母。
 * 
 * 
 */

// @lc code=start

/*
每一对下标相等的字符，`s[i]`和`t[i]` ，对应的开销 cost = abs(s[i]-t[i])。
使用滑动窗口，每次向右移动，累加 cost，当 cost > maxCost 时缩小窗口。
这里有个优化，缩小窗口时，只需减掉left位置对应的开销即可，cost = cost - abs(s[left]-s[left])，不用循环遍历。
*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0;
        int result = 0;
        int cost = 0;
        while (right < s.length() && right < t.length()) {
            cost += abs(s[right]-t[right]);
            if (cost > maxCost) {
                cost = cost - abs(s[left]-t[left]);
                left++;
            }

            right++;
            result = max(result, right - left);
        }
        return result;
    }
};
// @lc code=end

