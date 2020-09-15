/************************************************
 * Author        : jumpingfrog0
 * Created Time  : 2018/09/20
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

bool hasCycle(struct ListNode *head) {
	if (head == NULL) {
		return false;
	}
	struct ListNode *slow = head;
	struct ListNode *fast = head->next;

	while (fast) {
		if (slow->val == fast->val) {
			return true;
		}
		slow = slow->next;
		fast = fast->next;
		if (fast) {
			fast = fast->next;
		}
	}
	return false;
}

bool hasCycle2(struct ListNode *head) {
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;
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

			bool res = hasCycle(head);
			printf("%d\n", res);
		}
		}
		return 0;
	}
