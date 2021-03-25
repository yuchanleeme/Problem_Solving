# <두 개 뽑아서 더하기>
### https://programmers.co.kr/learn/courses/30/lessons/12910

***

## 주요 알고리즘  
* Arraylist
* 구현

## 풀이과정
### 풀이1
1. divisor로 나눠지는 값들만 Arraylist로 받는다.
2. Arraylist를 정렬한다.
3. ArrayList를 array로 바꿔서 리턴한다.

### 풀이2
1. stream, filter, lamda를 이용해 arr값을 필터링해서 받는다.
2. Arrays 정렬을하고 그 값을 리턴한다.

## 참고사항
* stream을 사용하면 시간이 좀 걸린다. (Arraylist로 바꿔서 하는것이 좋다)
* 정렬
```java
Arrays.sort(arr);
// int[] 꼴의 정렬

Collections.sort(list);
// Arraylist의 정렬
```
* filter, map, sorted
```java
int answer[] = Arrays.stream(arr).filter(item -> item % divisor == 0).toArray();
```