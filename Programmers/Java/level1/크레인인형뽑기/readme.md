# <크레인 인형 뽑기>
### https://programmers.co.kr/learn/courses/30/lessons/64061
***

## 주요 알고리즘  
* 큐
* 스택

## 풀이과정
1. 우선 큐로 각 라인의 인형들을 모아서 넣는다.
2. 움직일 인형들을 스택에 비교하면서 넣는다.
3. 이 때 인형이 터지면 answer++를 한다.
4. 최종 answer에 *2를 해서 리턴한다.

