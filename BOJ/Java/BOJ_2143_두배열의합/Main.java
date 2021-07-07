package BOJ_2143_두배열의합;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static int T, n, m;
    public static int A[], B[];
    public static long preA[], preB[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());

        n = Integer.parseInt(br.readLine());
        A = new int[n];
        preA = new long[n * (n + 1) / 2];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        m = Integer.parseInt(br.readLine());
        B = new int[m];
        preB = new long[m * (m + 1) / 2];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < m; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }

        int idxA = 0;
        for (int i = 0; i < n; i++) {
            long sum = 0;
            for (int j = i; j < n; j++) {
                sum += A[j];
                preA[idxA] = sum;
                idxA++;
            }
        }

        int idxB = 0;
        for (int i = 0; i < m; i++) {
            long sum = 0;
            for (int j = i; j < m; j++) {
                sum += B[j];
                preB[idxB] = sum;
                idxB++;
            }
        }

        Arrays.sort(preA);
        Arrays.sort(preB);

        int preAidx = 0, preBidx = idxB-1;
        long ans = 0;
        while (preAidx < idxA && preBidx >=0) {
            long Avalue = preA[preAidx];
            long Bvalue = preB[preBidx];
            long sum = Avalue + Bvalue;

            if(sum == T){
                long cntA = 0;
                while (preAidx < idxA && Avalue == preA[preAidx]){
                    cntA++;
                    preAidx++;
                }
                long cntB = 0;
                while (preBidx >= 0 && Bvalue == preB[preBidx]){
                    cntB++;
                    preBidx--;
                }
                ans += cntA * cntB;

            }else if(sum < T){
                // sum이 T보다 작다는 것은 Avalue가 좀 더 작아야 한다는 뜻
                preAidx++;
            }else if(sum > T){
                // sum이 T보다 작다는 것은 Bvalue가 너무 크다는 뜻
                preBidx--;
            }
        }
        System.out.println(ans);
    }
}
