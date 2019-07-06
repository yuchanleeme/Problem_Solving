/*
////////////////////////////////
main : 2개짜리 로마숫자부터 고려한다.
1. 문자들과 매치되는 숫자 값(ans)들을 더해준다.
2. 그 위치의 string 값들을 지워준다.
3. 입력받은 string이 빌때까지 반복한다.
4. 계산된 ans를 출력한다.

////////////////////////////////
*/

class Solution {
public:
    int romanToInt(string s) {

      int location, ans = 0;

      while(!s.empty()){
        location = 0;
        if ((location = s.find("IV")) != -1) {
          ans += 4;
          s.erase(location,2);
        }
        else if((location = s.find("IX")) != -1){
          ans += 9;
          s.erase(location,2);
        }
        else if((location = s.find("XL")) != -1){
          ans += 40;
          s.erase(location,2);
        }
        else if((location = s.find("XC")) != -1){
          ans += 90;
          s.erase(location,2);
        }
        else if((location = s.find("CD")) != -1){
          ans += 400;
          s.erase(location,2);
        }
        else if((location = s.find("CM")) != -1){
          ans += 900;
          s.erase(location,2);
        }
        else if((location = s.find("I")) != -1){
          ans += 1;
          s.erase(location,1);
        }
        else if((location = s.find("V")) != -1){
          ans += 5;
          s.erase(location,1);
        }
        else if((location = s.find("X")) != -1){
          ans += 10;
          s.erase(location,1);
        }
        else if((location = s.find("L")) != -1){
          ans += 50;
          s.erase(location,1);
        }
        else if((location = s.find("C")) != -1){
          ans += 100;
          s.erase(location,1);
        }
        else if((location = s.find("D")) != -1){
          ans += 500;
          s.erase(location,1);
        }
        else if((location = s.find("M")) != -1){
          ans += 1000;
          s.erase(location,1);
        }
     }
    return ans;
  }
};
