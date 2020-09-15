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

const int N = 100000;

int cmp(const void *a, const void *b) {
	return *((int *)a) > *((int *)b);
}

bool containsDuplicate(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), cmp);
	for (int i = 0; i < numsSize; i++) {
		if (i+1 >= numsSize) {
			return false;
		}
		if (nums[i] == nums[i+1]) {
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int nums[N];
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
