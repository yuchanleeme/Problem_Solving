# <수 찾기>
### https://www.acmicpc.net/problem/1920

***

## 주요 알고리즘
* 정렬, 이분탐색, (HashSet)

## 풀이과정 (#1)
1. 먼저 입력받은 배열을 정렬한다.
2. 이분탐색을 통해 값이 있는지 찾는다.

## 풀이과정 (#2)
1. HashSet에 입력받은 배열을 넣는다.
2. HashSet에 있는 지 확인한다.

## 참고사항
1. Java는 C++ STL 에 있는 upper_bound, lower_bound가 없다.
   * 따라서, 이분탐색을 직접 구현해야 한다. 
   * 구현해 두는 법 참고해 두자.
  ```java
    // 이분탐색 구현
    // 있으면 1
    // 없으면 0
    public static int binary_search(int key){
        int left, right, mid;
        left = 0;
        right = N-1;
        while(left <= right){
            mid = (left + right)/2;
            if(key == A[mid]){
                return 1;
            }
            else if(key < A[mid]){
                right = mid -1;
            }
            else{
                left = mid+1;
            }
        }
        return 0;
    }
```
2. HashSet으로 찾는 방법도 있다.