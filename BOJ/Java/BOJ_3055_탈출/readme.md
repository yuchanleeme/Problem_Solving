# <탈출>
### https://www.acmicpc.net/problem/3055

***

## 주요 알고리즘
* BFS

## 풀이과정
1. 물, 고슴도치를 따로 큐로 선언해서 관리한다.
2. 물 -> 고슴도치 ->물 -> 고슴도치 순으로 BFS 탐색을 진행한다.
3. 고슴도치가 비버 굴에 잘 들어갔으면 그 때 결과값을 출력한다.

## 참고사항
* 효율을 위해 고슴도치 방문한 곳도 방문체크를 해주어야 한다.
```java
Queue<Info> water = new LinkedList<>();
// 큐를 만드는 법
```
* 큐 클래스 사용법 숙지하기 [(docs)](https://docs.oracle.com/javase/8/docs/api/)
  * 큐와 add 와 offer의 차이
    * add는 큐에 여유 공간이 없어서 값 추가에 실패하면 illegalStateException 발생 
    * offer은 값 추가에 실패하면 false 반환