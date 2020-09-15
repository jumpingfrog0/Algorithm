
/************************************************
 * Author        : jumpingfrog0
 * Created Time  : 2018/09/22
 * File Name     : main.cpp
 *************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			break;
		}
	}

	if (fast == NULL || fast->next == NULL) { // no cycle
		return NULL;
	}

	fast = head;
	while(slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t, n;
	int nums[10000];

	while(scanf("%d", &t) != EOF) {
		for (int j = 0; j < t; j++) {
			struct ListNode *head = NULL;
			struct ListNode *preNode = head;
			struct ListNode *cycleNode = NULL;
			scanf("%d", &n);
			for (int i = 0; i < n; i++) {
				scanf("%d", &nums[i]);
			}

			// 建立链表
			int num = nums[0];
			int k = 0;
			while(num != 0) {
				if (j >= 2) {
					if (k >= n-1) { // 有环
						break;
					}
				}
				struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode *));
				node->val = num;
				node->next = NULL;
				//	printf("-----%p %d\n", node, num);
				if (preNode == NULL) {
					head = node;
				} else {
					preNode->next = node;
				}
				preNode = node;

				if ((j == 2 && k == 0) ||
						(j == 3 && k == 2)) { // 第3组测试用例，有环
					cycleNode = node;
				}
				num = nums[num];
				k++;
			}
			if (j >= 2) {
				preNode->next = cycleNode;
			}

			// 遍历
			//struct ListNode *nextNode = head;
			//int i = 0;
			//while(nextNode) {
			//	//if (j >= 2 && i >= n-1) {
			//	if (j >= 2 && i >= 10) {
			//		break;
			//	}
			//	printf("%p - %d\n", nextNode, nextNode->val);
			//	nextNode = nextNode->next;
			//	i++;
			//}
			//printf("--%d--sss\n", j);

			struct ListNode *node = detectCycle(head);
			if (node == NULL) {
				printf("null\n");
			} else {
				printf("%d\n", node->val);
			}
		}
		}
		return 0;
	}
