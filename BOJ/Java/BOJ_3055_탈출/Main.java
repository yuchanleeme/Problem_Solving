package BOJ_3055_탈출;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {
    static class Info{
        int x, y;
        public Info(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int R, C, Dx, Dy;
    static int board[][];
    static int tx[] = {-1, 0, 1, 0};
    static int ty[] = {0, 1, 0, -1};
    static Queue<Info> water = new LinkedList<>();  // 물
    static Queue<Info> G = new LinkedList<>();      // 고슴도치


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tc = br.readLine();
        StringTokenizer st = new StringTokenizer(tc, " ");
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        board = new int[R][C];

        // board 초기화
        for (int i = 0; i < R; i++) {
            Arrays.fill(board[i], 0);
        }

        for (int i = 0; i < R; i++){
            String line = br.readLine();
            for (int j = 0; j < line.length(); j++) {
                char d = line.charAt(j);
                if(d == 'D'){
                    // 비버 굴
                    Dx = i; Dy = j;
                    board[i][j] = -1;
                }else if(d == 'S'){
                    // 고슴도치
                    G.add(new Info(i, j));
                }else if(d == '*'){
                    // 물이 찬 곳
                    board[i][j] = -1;
                    water.add(new Info(i, j));
                }else if(d == 'X'){
                    board[i][j] = -1;
                }
            }
        }

        int ans = 0;
        boolean findAns = false;
        while (!G.isEmpty()){
            ans++;
            // 물 먼저 이동
            int water_size = water.size();
            for (int i = 0; i < water_size; i++) {
                Info val = water.poll();
                for (int j = 0; j < 4; j++) {
                    int nx = val.x + tx[j];
                    int ny = val.y + ty[j];

                    if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                    if(board[nx][ny] == -1) continue;
                    board[nx][ny] = -1;
                    water.add(new Info(nx, ny));
                }
            }

            int G_size = G.size();
            for (int i = 0; i < G_size; i++) {
                Info val = G.poll();
                for (int j = 0; j < 4; j++) {
                    int nx = val.x + tx[j];
                    int ny = val.y + ty[j];

                    if(nx == Dx && ny == Dy){
                        findAns = true;
                        break;
                    }
                    if(nx <0 || ny < 0 || nx >=R || ny >= C) continue;
                    if(board[nx][ny] == -1) continue;
                    board[nx][ny] = -1;
                    G.add(new Info(nx, ny));
                }

                if(findAns) break;
            }
            if(findAns) break;
        }

        // 결과 출력
        if(findAns) System.out.println(ans);
        else System.out.println("KAKTUS");
    }
}
