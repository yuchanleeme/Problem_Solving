#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/10427

/*
<빚>
주요: 정렬
1. 입력받은 배열을 오름차순으로 정렬한다.
  => 앞에서 부터 조사하면 각 idx가 최댓값
2. 누적합을 이용해 최솟값을 구한다.
3. 최솟값들을 다 더하고 결과를 출력한다.

*/

int T;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr;
        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        sort(arr.begin(), arr.end());

        long long answer = 0;
        for (int idx = 2; idx <= N; idx++) {
            long long sum = 0, res = arr[idx - 1] * idx;

            // 초기 sum
            for (int j = 0; j <= idx - 2; j++) {
                sum += arr[j];
            }
            for (int j = idx - 1; j < arr.size(); j++) {
                int now = arr[j];
                sum += now;
                res = min(res, (now * idx) - sum);
                sum -= arr[j - (idx - 1)];
            }
            answer += res;
        }
        cout << answer << "\n";
    }
    return 0;
}