/************************************************
 * Author        : jumpingfrog0
 * Created Time  : 2018/09/17
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

bool containsDuplicate2(vector<int>& nums) {
	map<int, int> hash;
	for (int i = 0; i < nums.size(); i++) {
		if (hash.find(nums[i]) != hash.end()) {
			return true;
		} else {
			hash.insert(pair<int, int>(nums[i], nums[i]));
		}
	}

	return false;
}

bool containsDuplicate(vector<int>& nums) {
	set<int> hash;
	for (int i = 0; i < nums.size(); i++) {
		if (hash.find(nums[i]) != hash.end()) {
			return true;
		} else {
			hash.insert(nums[i]);
		}
	}

	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n, num;

	while(cin >> n) {
		vector<int> nums;
		for (int i = 0; i < n; i++) {
			cin >> num;
			nums.push_back(num);
		}
		bool res = containsDuplicate(nums);
		if (res) {
			cout << "true" << endl;
		} else {
			cout << "false" << endl;
		}
	}

	return 0;
}
