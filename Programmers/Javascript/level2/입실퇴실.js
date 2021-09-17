function solution(enter, leave) {
  let inRoom = []
  let res = []
  for(let i = 0; i < enter.length; i++){
    res.push(0)
  }

  let idx = 0;
  for (const whoLeave of leave) {
    while(!inRoom.includes(whoLeave)){
      inRoom.push(enter[idx++])
    }
    
    let idxOfRoom = inRoom.indexOf(whoLeave);
    inRoom.splice(idxOfRoom,1)

    res[whoLeave-1] += inRoom.length
    for (const whoInRoom of inRoom) {
      res[whoInRoom-1]++
    }
  }

  return res
}