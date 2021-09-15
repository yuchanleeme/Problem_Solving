const cal = (s, unit) => {
  let tokens = [];
  for(let start = 0; start < s.length; start+=unit){
    tokens.push(s.substr(start, unit))
  }

  let res = "", cnt = 1;
  let last = tokens.reduce((prev, cur) =>{
    if(prev === cur){
      cnt++;
      return prev
    }else{
      if(cnt !== 1) res += String(cnt)
      res += prev
      cnt = 1
      return cur
    }
  })

  if(cnt === 1) cnt = ""
  return `${res}${last}${cnt}`.length;
}

function solution(s) {
  let minLen = s.length;
  for(let len = 1; len <= s.length/2; len++){
    minLen = Math.min(cal(s, len), minLen)
  }
  return minLen
}