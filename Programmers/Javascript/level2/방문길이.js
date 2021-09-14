let arr = []
let dx = [1, -1, 0, 0]
let dy = [0, 0, -1, 1]
let directions = {R : 0, L: 1, D:2, U:3}

function makeHash(px, py, nx, ny){
  return [`${px}${py}${nx}${ny}`, `${nx}${ny}${px}${py}`]
}

function solution(dirs) {
  let prevX = 0, prevY = 0;

  for(let i = 0; i <dirs.length; i++){
    let nx = prevX + dx[directions[dirs[i]]]
    let ny = prevY + dy[directions[dirs[i]]]
    let [hash1, hash2] = makeHash(prevX, prevY, nx, ny)

    if(nx < -5 || ny < -5 || nx >5 || ny >5) continue;
    if(!arr.includes(hash1) && !arr.includes(hash2)){
      arr.push(hash1)
      arr.push(hash2)
    }
    prevX = nx, prevY = ny
  }
  return arr.length/2
}