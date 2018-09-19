/************************************************
 * Author        : jumpingfrog0
 * Created Time  : 2018/09/19
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

const int N = 10000;

int findDuplicate(int *nums, int numsSize) {
	int slow = nums[0], fast = nums[slow];
	while(slow != fast) {
		slow = nums[slow];
		fast = nums[fast];
		fast = nums[fast];
	}

	fast = 0;
	while (slow != fast) {
		slow = nums[slow];
		fast = nums[fast];
	}
	return slow;
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	int nums[N];

	while(scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}
		int res = findDuplicate(nums, n);
		printf("%d\n", res);
	}

	return 0;
}
