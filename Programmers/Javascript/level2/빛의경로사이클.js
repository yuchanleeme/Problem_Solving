let visitChk = [], N, M
let dx = [0, 1, 0, -1], dy = [1, 0, -1, 0]

const convertX = (x) =>{
  if(x < 0) return N-1
  else if(x >= N) return 0
  else return x
}

const convertY = (y) =>{
  if(y < 0) return M-1
  else if(y >= M) return 0
  else return y
}

const findNextDir = (word, dir) =>{
  if(word === 'S'){
    return dir
  }else if(word === 'L'){
    return (dir+3) % 4
  }else if(word === 'R'){
    return (dir+1) % 4
  }
}

const defineArr = (N, M) =>{
  for(let i = 0; i < N; i++){
    visitChk.push([])
    for(let j = 0; j < M; j++){
      visitChk[i].push([])
      visitChk[i][j] = [0, 0, 0, 0]
    }
  }
}

const cntCycle = (grid, x, y, dir) =>{
  let res = 0;
  while(true){
    if(visitChk[x][y][dir] !== 0) break;
    visitChk[x][y][dir] = 1;
    res++;
    
    // console.log(x, y, dir, "==>");

    let nextX = convertX(x + dx[dir])
    let nextY = convertY(y + dy[dir])
    let nextDir = findNextDir(grid[nextX][nextY], dir)
    
    // console.log(nextX, nextY, nextDir);
    x = nextX
    y = nextY
    dir = nextDir
  }
  return res
}

function solution(grid) {
  let answer = []
  N = grid.length, M = grid[0].length
  
  defineArr(N, M)
  for(let x = 0; x < N; x++){
    for(let y = 0; y < M; y++){
      for(let dir = 0; dir< 4; dir++){
        if(visitChk[x][y][dir] !== 0) continue;
        let cntValue = cntCycle(grid, x, y, dir)
        answer.push(cntValue)
      }
    }
  }
  
  answer.sort((a,b)=>{return a-b})

  return answer
}

solution(["R","R"])
// solution(["SL","LR"])
// solution(["SL","LR"])