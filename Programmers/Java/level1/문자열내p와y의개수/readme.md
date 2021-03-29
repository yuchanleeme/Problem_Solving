# <문자열 내 p와 y의 개수>
### https://programmers.co.kr/learn/courses/30/lessons/12916

***

## 주요 알고리즘  
* 구현

## 풀이과정
1. toLowerCase를 이용해 s를 소문자로 바꾼다.
2. p와 y의 등장 횟수를 세서 그 값을 비교해 결과로 출력한다.

## 참고사항
* Stream을 이용하는 방법도 있다. (프로그래머스 다른 사람 풀이 참조)
```java
s = s.toLowerCase();
return s.chars().filter( e -> 'p'== e).count() == s.chars().filter( e -> 'y'== e).count();
```