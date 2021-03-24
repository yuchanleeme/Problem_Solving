# <3진법 뒤집기>
### https://programmers.co.kr/learn/courses/30/lessons/68935

***

## 주요 알고리즘  
* 수학

## 풀이과정
1. 먼저 뒤집힌 3진법을 string 형태로 만든다.
2. 그 string을 3진법 형태로 변환해 출력한다.

## 참고사항
* Integer.parseInf("str", x) : str을 x진법으로 변환
* Integer.toString(number) : number를 String으로 변환
* String reverse 기능
```java
String str = new StringBuilder("XYZ").reverse().toString();
// str에 "XYZ"를 reverse한 문자열을 저장시킴
```