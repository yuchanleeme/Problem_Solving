#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/17683

/*
<방금 그 곡>
주요: 문자열, 정렬
1. 우선 모든 입력값의 A#, B#... G# 이 값들을 각각 하나의 문자열로 바꾼다. (replaceAll)
2. 이제 시간, 제목, 악보를 각각 res[x][0] res[x][1] res[x][2]에 분류해 넣는다.
3. res[x][2]를 시간(res[x][0]) 만큼 string 이어붙이기를 한다.
4. 입력 문자열 m 이 그 안에 있는지를 판단해 결과값을 리턴한다.
==========
* 시간 구할 때 [12:50 , 13:14] 이런거 조심
* C#같이 #이 붙은 것은 하나의 멜로디이다.

*/

vector<vector<string>> res;
// 시간 순 정렬 할 때 쓰임
bool comp(const vector<string> &A, const vector<string> &B) {
  return stoi(A[0]) > stoi(B[0]);
}

// 문자열 치환하기
void replaceAll(string &str){
  int temp = 0;
  int check = 0;
  while (check != 5) {
    check = 0;
    temp = str.find("A#");
    if(temp != string::npos) str.replace(temp, 2, "H");
    else check++;

    temp = str.find("C#");
    if(temp != string::npos) str.replace(temp, 2, "I");
    else check++;

    temp = str.find("D#");
    if(temp != string::npos) str.replace(temp, 2, "J");
    else check++;

    temp = str.find("F#");
    if(temp != string::npos) str.replace(temp, 2, "K");
    else check++;

    temp = str.find("G#");
    if(temp != string::npos) str.replace(temp, 2, "L");
    else check++;
  }
}

string solution(string m, vector<string> musicinfos) {
  replaceAll(m);
  for (int i = 0; i < musicinfos.size(); i++) {
    vector<string> dummy;
    replaceAll(musicinfos[i]);

    int shour = stoi(musicinfos[i].substr(0, 2)), ehour = stoi(musicinfos[i].substr(6, 2));
    int smin = stoi(musicinfos[i].substr(3, 2)), emin = stoi(musicinfos[i].substr(9, 2));
    int time = 0;
    if(shour == ehour) time = (emin-smin);
    else{
      time += (ehour-shour-1)*60;
      time += (60-smin) +emin;
    }

    dummy.push_back(to_string(time));

    string title = "";
    for (int j = 12; j < musicinfos[i].length(); j++) {
      if (musicinfos[i][j] == ',') {
        dummy.push_back(title);
        dummy.push_back(musicinfos[i].substr(j + 1));
        break;
      }
      title += musicinfos[i][j];
    }
    res.push_back(dummy);
  }
  stable_sort(res.begin(), res.end(), comp); // stable sort

  for (int i = 0; i < res.size(); i++) {
    string temp = "";
    int idx = 0;
    while (temp.length() != stoi(res[i][0])) {
      if (idx == res[i][2].length()) {
        idx = 0;
      }
      temp += res[i][2][idx];
      idx++;
    }
    cout << temp << endl;
    if (temp.find(m) != string::npos) {
      int checkidx = temp.find(m) + m.length();
      if (checkidx >= temp.length() || temp[checkidx] != '#') return res[i][1];
    }
  }

  return "(None)";
}
