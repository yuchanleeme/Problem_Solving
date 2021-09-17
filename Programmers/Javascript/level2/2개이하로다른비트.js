function solution(numbers) {
  let answer = [];

  for (const num of numbers) {
    if(num & 1 == 0) answer.push(num+1)
    else{
      let findNumBit = BigInt(1);
      while((findNumBit & BigInt(num)) == findNumBit){
        findNumBit <<= BigInt(1);
      }
      answer.push(BigInt(num)+findNumBit-(findNumBit>>BigInt(1)));
    }
  }
  return answer;
}