package BOJ_7453_합이0인네정수;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static int N;
    public static int A[], B[], C[], D[];
    public static long AB[], CD[];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        A = new int[N];
        B = new int[N];
        C = new int[N];
        D = new int[N];
        AB = new long[N*N];
        CD = new long[N*N];

        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            A[i] = Integer.parseInt(st.nextToken());
            B[i] = Integer.parseInt(st.nextToken());
            C[i] = Integer.parseInt(st.nextToken());
            D[i] = Integer.parseInt(st.nextToken());
        }

        int idx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                AB[idx] = A[i] + B[j];
                CD[idx] = C[i] + D[j];
                idx++;
            }
        }

        // 정렬
        Arrays.sort(AB);
        Arrays.sort(CD);

        int ab_i = 0, cd_i = N*N-1;
        long cnt = 0;

        while (ab_i < N*N && cd_i>= 0){
            long sum = AB[ab_i] + CD[cd_i];

            if(sum == 0){
                long ab_cnt = 0, cd_cnt = 0; // 같은 크기의 idx 수 찾기
                long base_ab = AB[ab_i];
                while(ab_i < N*N && AB[ab_i] == base_ab){
                    ab_cnt++;
                    ab_i++;
                }

                long base_cd = CD[cd_i];
                while(cd_i >= 0 && CD[cd_i] == base_cd){
                    cd_cnt++;
                    cd_i--;
                }
                cnt += (ab_cnt * cd_cnt);
            }else if(sum > 0){
                // sum이 0보다 크다는 것은 CD가 아직 크다는 뜻이므로 cd_i-- 해줘야함
                cd_i--;
            }else if(sum < 0){
                // sum이 0보다 작다는 것은 AD가 너무 작다는 뜻이므로 ab_i++ 해줘야함
                ab_i++;
            }
        }

        System.out.println(cnt);

    }
}
