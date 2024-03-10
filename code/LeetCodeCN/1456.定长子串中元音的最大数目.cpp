/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 *
 * https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
 *
 * algorithms
 * Medium (56.16%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    41.4K
 * Total Submissions: 73.6K
 * Testcase Example:  '"abciiidef"\n3'
 *
 * 给你字符串 s 和整数 k 。
 * 
 * 请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。
 * 
 * 英文中的 元音字母 为（a, e, i, o, u）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "abciiidef", k = 3
 * 输出：3
 * 解释：子字符串 "iii" 包含 3 个元音字母。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "aeiou", k = 2
 * 输出：2
 * 解释：任意长度为 2 的子字符串都包含 2 个元音字母。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "leetcode", k = 3
 * 输出：2
 * 解释："lee"、"eet" 和 "ode" 都包含 2 个元音字母。
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "rhythms", k = 4
 * 输出：0
 * 解释：字符串 s 中不含任何元音字母。
 * 
 * 
 * 示例 5：
 * 
 * 输入：s = "tryhard", k = 4
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 由小写英文字母组成
 * 1 <= k <= s.length
 * 
 * 
 */

// @lc code=start

/*
class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0, right = 0, count = 0;
        set<char> t = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < k; i++) {
            if (t.contains(s[i])) {
                count++;
            }
        }
        right = k;
        int result = count;
        while (right < s.length()) {
            left = right - k;
            if (t.contains(s[left])) {
                count--;
            }
            if (t.contains(s[right])) {
                count++;
            }
            result = max(result, count);
            right++;
        }
        return result;
    }
};
*/

/**
首先计算初始窗口[0,k]中元音字母的个数，然后这个窗口开始向右滑动一格，此时分为三种情况：

1. 右侧新进入窗口的字母为元音字母，左侧移出窗口的字母也是元音字母，这样一进一出抵消掉了
2. 右侧新进入窗口的字母为元音字母，左侧移出窗口的字母非元音字母，此时元音字母个数+1
3. 右侧新进入窗口的字母非元音字母，左侧移出窗口的字母为元音字母，此时元音字母个数-1

综上，vowel_count += isVowel(s[i]) - isVowel(s[i - k]);
*/

class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int left = 0, right = 0, count = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }
        right = k;
        int ans = count;
        while (right < s.length()) {
            left = right - k;
            count = count + isVowel(s[right]) - isVowel(s[left]);
            ans = max(ans, count);
            right++;
        }
        return ans;
    }
};
// @lc code=end

