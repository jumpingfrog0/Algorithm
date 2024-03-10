/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (53.15%)
 * Likes:    1062
 * Dislikes: 0
 * Total Accepted:    622.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,1,2]
 * 输出：[1,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,1,2,3,3]
 * 输出：[1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目在范围 [0, 300] 内
 * -100 <= Node.val <= 100
 * 题目数据保证链表已经按升序 排列
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *p, *p1, *list;
        p = p1 = head;
        list = p1;
        while (p != nullptr) {
            if (p->next == nullptr) {
                break;
            }

            ListNode *next = p->next;
            if (p->val == next->val) {
                p = next;
            } else {
                p1->next = next;
                p1 = next;
                p = p->next;
            }
        }
        p1->next = nullptr;
        return list;
    }
};

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode *cur = head;
//         while (cur != nullptr && cur->next != nullptr) {
//             if (cur->val == cur->next->val) {
//                 cur->next = cur->next->next;
//             } else {
//                 cur = cur->next;
//             }
//         }
//         return head;
//     }
// };

// @lc code=end

