function solution(n, words) {
  let arr = []
  let cmpAlph = ""

  for(let idx = 0; idx < words.length; idx++){
    let word = words[idx]
    let firstAlph = word[0]
    let lastAlph = word[word.length-1];
    let player = idx%n +1
    let turn = Math.floor(idx/n)+1;

    if(arr.includes(word)) return [player, turn]
    if(cmpAlph === "" || cmpAlph === firstAlph){
      cmpAlph = lastAlph;
      arr.push(words[idx])
    }else{
      return [player, turn]
    }
  }

  words.forEach((word, idx) => {
    
  });

  return [0, 0]
}
