package BOJ_1072_게임;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static long X, Y, Z;

    // 승률
    static long func(long win){
        long percent;
        percent = (Y + win) * 100 / (X + win);
        return percent;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        X = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());
        Z = func(0);

        long low = 0, high = (long) (1e9 + 1);
        for (int i = 0; i < 40; i++) {
            long mid = (low + high) / 2;

            if(func(mid) <= Z){
                // 승률이 Z보다 작거나 같으면 더 많은 win을 찾아야 하므로 low를 mid로 움직인다.
                low = mid;
            }else{
                // 승률이 Z보다 크다면 Z+1보다는 크거나 같을것으로 예상되므로 high를 mid로 땡긴다.
                high = mid;
            }
        }
        // 이렇게 40번 반복한 뒤 low값이 1e9보다 커지면 승률을 올릴 수 없으므로 -1
        if(low >= (long)1e9){
            System.out.println("-1");
        }else{
            System.out.println(high);
        }
    }
}
