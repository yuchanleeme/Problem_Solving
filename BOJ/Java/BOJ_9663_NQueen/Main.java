package BOJ_9663_NQueen;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int N, ans = 0;
    static int[] arr;

    static void backtracking(int level){

        if(level == N+1){
            ans++;
            return;
        }

        for (int i = 1; i <= N; i++) {
            arr[level] = i; // level 행에는 i번째 열에 퀸을 배치함
            if(isPossible(level)){
                backtracking(level+1);
            }
        }

    }

    static boolean isPossible(int level){

        for (int i = 1; i < level; i++) {
            // i번째 행에 level행과 같은 열에 퀸이 위치하면 false
            if(arr[i] == arr[level]) return false;

            // 대각선 판단 (x축 증가량 과 y축 증가량이 같은지 판단)
            if(Math.abs(arr[level] - arr[i]) == Math.abs(level - i)) return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N+1];

        backtracking(1);
        System.out.println(ans);
    }
}
