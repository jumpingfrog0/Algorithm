/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (39.13%)
 * Likes:    9396
 * Dislikes: 0
 * Total Accepted:    2.4M
 * Total Submissions: 6.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start

/*
// 双指针法 & set
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int result = 0;
        set<char> set;
        while (left < s.length() && right < s.length()) {
            if (set.contains(s[right])) {
                set.erase(s[left]);
                left++;
            } else {
                set.insert(s[right]);
                right++;
                result = max(result, right - left);
            }
        }
        return result;
    }
};
*/

/*
// 哈希表(map)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int result = 0;  // 用来存放最长子串的长度
        map<char, int> map;

		// 前闭后开，滑动窗口
		// 每次遍历都添加频度
		// 如果不重复就加入哈希表，右边界前进，比较最大长度
		// 如果重复，删除哈希表，左边界前进
	
		// 使用右边界来遍历数组，再判断是否加入哈希表中
        while (right < s.length()) {
            if (map.find(s[right]) != map.end()) {
				// 重复，左边界前进，哈希表删除
                map.erase(s[left]);
                left++;
            } else {
				// 右边界前进，哈希表增加
                map.insert(make_pair(s[right], 1));
                right++;
                result = max(result, right - left);
            }
        }
        return result;
    }
};
*/

/*
// 优化
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int result = 0;
        map<char, int> map;
        while (right < s.length()) {
            if (map.find(s[right]) != map.end()) {
	            // 注意: 因为滑动窗口left只能前进，不能倒退回去，只能取最大的
                left = max(map[s[right]], left);
                map[s[right]] = right + 1;
            }

            map.insert(make_pair(s[right], right + 1));
            right++;
            result = max(result, right - left);
        }
        return result;
    }
};
*/

// 优化2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int result = 0;
        int array[256] = {0};
        while (right < s.length()) {
            if (array[s[right]] > 0) {
                left = max(array[s[right]], left);
                array[s[right]] = right + 1;
            }

            array[s[right]] = right + 1;
            right++;
            result = max(result, right - left);
        }
        return result;
    }
};

// @lc code=end

