#include <stdio.h>

/**
 * 二分查找
 *
 * 题意：在一个有序不重复的长度为n的数组nums[]中，是否能找到数字m，
 * 		 若能找到输出m在数组中的位置，若不能找到输出-1。
 * 输入：每组测试用例2行，第一行有2个数字n和m，第二行是数组nums[]中每个元素的值。
 * 输出：数字m在数组nums[]中的位置或-1。
 */

const int MAXN = 100;

int binarySearch(int n, int m, int nums[]) {
	int l = 0, h = n - 1;
	while (l <= h) {
		// 防止溢出，等价于 (l + h) / 2
		int mid = l + (h - l) / 2;
		if (nums[mid] == m) {
			return mid;
		} else if (nums[mid] > m) {
			h = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return -1;
}

int main() {
	int n, m;
	int nums[MAXN];

	// 使用文件输入输出测试数据
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	while(scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++)
			scanf("%d", &nums[i]);
		int res = binarySearch(n, m, nums);
		printf("%d\n", res);
	}
	return 0;
}
