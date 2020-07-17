#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//https://www.acmicpc.net/problem/17127

/*
<벚꽃이 정보섬에 피어난 이유>
주요: 백트래킹
1. 푯말의 위치에대한 순서를 백트래킹으로 고른다고 생각하면 된다.
	=> seq에 하나씩 넣는데, 한 영역의 끝 idx를 넣는다.
2. 이제 완성된 조합에 관하여 최대값을 구해서 출력한다.
*/

int N, res = 1;
vector<int> tree;
vector<int> seq;

void back_tracking(int level, int maxV) {

	if (level == 4) {
		int mul_a = 1, mul_b = 1, mul_c = 1, mul_d = 1;
		for (int i = 0; i <= seq[0]; i++)
		{
			mul_a *= tree[i];
		}
		for (int i = seq[0]+1; i <= seq[1]; i++)
		{
			mul_b *= tree[i];
		}
		for (int i = seq[1]+1; i <= seq[2]; i++)
		{
			mul_c *= tree[i];
		}
		for (int i = seq[3]; i < N; i++)
		{
			mul_d *= tree[i];
		}
		res = max(res, mul_a + mul_b + mul_c + mul_d);
		return;
	}

	for (int i = maxV; i <N ; i++)
	{
		seq.push_back(i);
		back_tracking(level + 1, i + 1);
		seq.pop_back();
	}

}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		tree.push_back(input);
	}

	back_tracking(0, 0);
	cout << res;

	return 0;

}
