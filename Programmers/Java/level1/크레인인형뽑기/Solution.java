/*
<크레인 인형 뽑기>
//https://programmers.co.kr/learn/courses/30/lessons/64061
주요: 큐, 스택
1. 우선 큐로 각 라인의 인형들을 모아서 넣는다.
2. 움직일 인형들을 스택에 비교하면서 넣는다.
3. 이 때 인형이 터지면 answer++를 한다.
4. 최종 answer에 *2를 해서 리턴한다.
*/

package level1.크레인인형뽑기;
import java.util.*;

public class Solution {

    public static int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> stack = new Stack<>();
        Queue<Integer>[] queue = new Queue[50];
        for (int i = 0; i < 50; i++) {
            queue[i] = new LinkedList<>();
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if(board[i][j] != 0) queue[j+1].add(board[i][j]);
            }
        }

        for (int move : moves){
            if(queue[move].isEmpty()) continue;
            int next = queue[move].peek();
            queue[move].poll();
            if(stack.isEmpty()) stack.push(next);
            else{
                if(stack.peek() == next) {
                    stack.pop();
                    answer++;
                }
                else stack.push(next);
            }
        }
        return answer*2;
    }
}
