/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (46.39%)
 * Likes:    2715
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.7M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1], n = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中结点的数目为 sz
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 * 
 * 
 * 
 * 
 * 进阶：你能尝试使用一趟扫描实现吗？
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

/**
使用数组存储节点，遍历一次链表，计算链表长度为m，此时m-n就是倒数第n个节点的前驱节点，删除第n个节点即可
注意边界条件：
1.删除的节点是第一个节点
2.删除的节点是最后一个节点

算法复杂度：O(n)
空间复杂度：O(n)
*/

/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *arr[31];
        int m = 0;
        ListNode *p = head;
        while (p != nullptr) {
            m++;
            arr[m] = p;
            p = p->next;
        }
        ListNode *t = arr[m-n];
        if (m == n) {
            head = head ->next;
        } else if (n == 1) {
            t->next = nullptr;
        } else {
            t->next = t->next->next;
        }
        return head;
    }
};
*/

/*
解法：快慢指针

- 添加一个哑节点（dummy node），它的 next 指针指向链表的头节点
- 快指针指向头节点，慢指针指向哑节点
- 先让快指针先前进n步
- 同时移动快慢指针，直到快指针指向最后一个节点，此时，慢指针则指向倒数第n+1个节点，我们删去慢指针的后继节点即可

注意边界条件：删去头节点的情况
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast, *slow;
        ListNode *dummy = new ListNode(0, head);    // 哑结点
        fast = head;
        slow = dummy;

        while (n > 0) {
            fast = fast->next;
            n--;
        }
        if (fast == nullptr) {  // 删除的是第一个节点
            return head->next;
        }
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

// @lc code=end

