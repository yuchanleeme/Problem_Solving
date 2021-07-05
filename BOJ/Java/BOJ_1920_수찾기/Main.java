package BOJ_1920_수찾기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int A[], B[];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        A = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++){
            A[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        B = new int[M];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++){
            B[i] = Integer.parseInt(st.nextToken());
        }

        // 정렬
        Arrays.sort(A);

        for(int target : B){
            System.out.println(binary_search(target));
        }
    }

    // 이분탐색 구현
    // 있으면 1
    // 없으면 0
    public static int binary_search(int key){
        int left, right, mid;
        left = 0;
        right = N-1;
        while(left <= right){
            mid = (left + right)/2;
            if(key == A[mid]){
                return 1;
            }
            else if(key < A[mid]){
                right = mid -1;
            }
            else{
                left = mid+1;
            }
        }
        return 0;
    }
}
