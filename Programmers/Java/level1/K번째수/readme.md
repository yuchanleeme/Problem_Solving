# <K번째수>
### https://programmers.co.kr/learn/courses/30/lessons/42748

***

## 주요 알고리즘  
* ArrayList
* 정렬

## 풀이과정
1. 범위만큼 ArryList에 복사한다.
2. 그 list를 정렬한다.
3. 정렬한 list에서 target idx를 찾아 answer 배열에 넣는다.
4. 모든 과정을 거치고 answer 배열을 리턴한다.

## 참고사항
* Arrays.copyOfRange 사용하는 방법이 있다. (Arrays.copyOf 메소드도 있음) 
[출처(TCPSCHOOL)](http://tcpschool.com/java/java_api_arrays)
``` java
// array[start]~array[end] => list에 복사
int[] list = Arrays.copyOfRange(array, start, end+1);
```
