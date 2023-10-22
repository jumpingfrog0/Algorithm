/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode.cn/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (73.67%)
 * Likes:    3397
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：[2,1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 
 * 
 * 
 * 
 * 
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 * 
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
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (head == nullptr) {
//             return nullptr;
//         }

//         ListNode *p = head;
//         ListNode *p1, *p2;
//         p1 = new ListNode(p->val);
//         p2 = p1;
//         while (p != nullptr) {
//             if (p->next == nullptr) {
//                 break;
//             }

//             p = p->next;
//             p2 = new ListNode(p->val);
//             p2->next = p1;
//             p1 = p2;
//         }
//         return p2;
//     }
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (head == nullptr) {
//             return nullptr;
//         }

//         ListNode *p, *pre, *next;
//         p = next = head;
//         pre = nullptr;
//         while (next != nullptr) {
//             next = next->next;
//             p->next = pre;
//             pre = p;
//             if (next != nullptr) {
//                 p = next;
//             }
//         }
//         return p;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *cur, *prev, *next;
        prev = nullptr;
        cur = head;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

// @lc code=end

