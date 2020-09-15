#include <stdio.h>
#include <cmath>

/**
 * 解题思路：
 *
 * 算出披萨的总体积maxVolume, 然后在区间 [0, maxVolume] 进行二分, 计算如果将披萨切割为体积为mid的情况下
 * 是否足够有 f+1 块，足够则将 l = mid，不足够则将 h = mid，一直二分下去，直到精度小于 1e-5 为止。
 */

const int N = 10000;
const double PI = acos(-1.0);

double binary(int n, int m, int ri[]) {
	double maxVolume = 0;
	for (int i = 0; i < n; i++) {
		maxVolume += PI * ri[i] * ri[i];
	}

	double l = 0, h = maxVolume, mid;
	while (h - l > 0.00001) {
		mid = l + (h - l) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int piece = int(PI * ri[i] * ri[i] / mid);
			cnt += piece;
		}
		if (cnt < m) {
			h = mid;
		} else {
			l = mid;
		}
	}
	return l;
}

int main() {
	int t, n, f;
	int ri[N];

	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);

	scanf("%d", &t);
	while (t) {
		scanf("%d%d", &n, &f);
		for (int i = 0; i< n; i++) {
			scanf("%d", &ri[i]);
		}

		double res = binary(n, f + 1, ri);
		printf("%.4f\n", res);

		t--;
	}

	return 0;
}
