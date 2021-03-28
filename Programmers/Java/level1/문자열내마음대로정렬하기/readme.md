# <두 개 뽑아서 더하기>
### https://programmers.co.kr/learn/courses/30/lessons/12915

***

## 주요 알고리즘  
* 정렬

## 풀이과정
1. Comparator을 이용해 compare 메소드 오버라이드를 이용한다.
2. 비교하려는 값이 같으면 그냥 사전순으로 정렬하고 다르면 음수값으로 값을 비교한다.

## 참고사항
* 정렬 예시
    * 리턴 결과가 음수이면 첫번째 인자의 정렬 순위가 낮음
    * 리턴 결과가 같으면 첫번째 인자의 정렬 순위가 같음
    * 리턴 결과가 양수이면 첫번째 인자의 정렬 순위가 높음
```java
Arrays.sort(strings, new Comparator<String>(){
            @Override
            public int compare(String s1, String s2){
                // return s1 - s2; // 사전순 ( 오름차순 )
                // return (s1 - s2) * -1; // 역사전순 (내림차순)
            }
        });
```
* compareTo
    * A.compareTo(B)
    * A == B
      * 0리턴
    * A < B
      * 음수 리턴
    * A > B
      * 양수 리턴
```java
3.compareTo(4) // -1
3.compareTo(3) // 0
5.compareTo(4) // 1
```    