
#include <stdio.h>

/**
 * 二分查找变种
 *
 * 题意：在一个有序的有重复的长度为n的数组nums[]中，查找key的最左位置
 * 		 若能找到输出key在数组中的位置，若不能找到输出-1。
 * 输入：每组测试用例2行，第一行有2个数字n和key，第二行是数组nums[]中每个元素的值。
 * 输出：数字key在数组nums[]中的位置或-1。
 */

const int MAXN = 100;

int binarySearch(int n, int key, int nums[]) {
	int l = 0, h = n - 1;
	while (l < h) {
		// 防止溢出，等价于 (l + h) / 2
		int mid = l + (h - l) / 2;
		if (nums[mid] >=  key) {
			h = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

int main() {
	int n, key;
	int nums[MAXN];

	// 使用文件输入输出测试数据
	freopen("input_2.in", "r", stdin);
	freopen("output_2.out", "w", stdout);

	while(scanf("%d%d", &n, &key) != EOF) {
		for (int i = 0; i < n; i++)
			scanf("%d", &nums[i]);
		int loc = binarySearch(n, key, nums);
		if (nums[loc] == key) {
			printf("%d\n", loc);
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
