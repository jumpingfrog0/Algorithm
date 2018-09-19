/************************************************
 * Author        : jumpingfrog0
 * Created Time  : 2018/09/17
 * File Name     : main_2.cpp
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
#include <stdlib.h>

using namespace std;

/**
 * 使用哈希链表实现
 */

struct Node {
	int val;
	struct Node *next;
};

struct Set {
	int bucketSize;
	struct Node **table;
};

void initSet(struct Set *set, int bucketSize) {
	set->bucketSize = bucketSize;
	set->table = (struct Node **)malloc(sizeof(struct Node *) * bucketSize);
	memset(set->table, 0, sizeof(struct Node *) * bucketSize);
}

void releaseSet(struct Set *s) {
	struct Node *ptr, *tmp;
	for (int i = 0; i < s->bucketSize; i++) {
		ptr = s->table[i];
		while(ptr != NULL) {
			tmp = ptr;
			ptr = ptr->next;
			free(tmp);
		}
	}
	free(s->table);
	s->table = NULL;
	s->bucketSize = 0;
}

bool addValue(struct Set *s, int val) {
	int idx = 0;
	// -INT_MIN overflow in expression -val
	if (INT_MIN == val) {
		idx = 0;
	} else {
		idx = val > 0 ? val : -val;
	}

	idx = idx % s->bucketSize;
	struct Node *ptr = s->table[idx];
	while (ptr != NULL) {
		if (ptr->val == val) {
			return false;
		}
		ptr = ptr->next;
	}

	// add new value
	ptr = (struct Node *)malloc(sizeof(struct Node *));
	ptr->val = val;
	// update the new added value as the first in list
	ptr->next = s->table[idx];
	s->table[idx] = ptr;
	return true;
}

bool containsDuplicate(int* nums, int numsSize) {
	if (numsSize < 2) {
		return false;
	}

	struct Set set;

	// here numsSize/2 && numsSize both ok
	initSet(&set, numsSize/2);

	for (int i = 0; i < numsSize; i++) {
		if (!addValue(&set, nums[i])) {
			// free memory
			releaseSet(&set);
			return true;
		}
	}
	releaseSet(&set);
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int nums[10000];
	int n;

	while(scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}

		int res = containsDuplicate(nums, n);
		if (res) {
			printf("true\n");
		} else {
			printf("false\n");
		}
	}

	return 0;
}
