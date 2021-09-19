let stTime = [], edTime = [], chkSongs = []

function numToTime(num){
  let hour = Math.floor(num/3600)
  num -= hour*3600

  let min = Math.floor(num/60)
  num -= min*60

  let seconds = Math.floor(num)
  return `${hour.toString().padStart(2,0)}:${min.toString().padStart(2,0)}:${seconds.toString().padStart(2,0)}`
}

function timeToNum(time){
  let [hour, min, seconds] = time.split(":")
  return parseInt(hour)*3600 + parseInt(min)*60 + parseInt(seconds)
}

function solution(play_time, adv_time, logs) {
  let totalLength = timeToNum(play_time)
  for(let i = 0; i <= totalLength+1; i++){
    stTime.push(0)
    edTime.push(0)
    chkSongs.push(0)
  }

  logs.forEach(log => {
    let [logStart, logEnd] = log.split("-")
    logStart = timeToNum(logStart)
    logEnd = timeToNum(logEnd)

    stTime[logStart]++
    edTime[logEnd+1]--
  })

  let playTerm = timeToNum(adv_time)
  let nowSongs = 0;
  for(let ed = 0; ed <= totalLength; ed++){
   let st = ed-playTerm
   
   nowSongs += stTime[ed]
   if(st >= 0){
     nowSongs += edTime[st]
   }
   chkSongs[ed] = nowSongs
  };

  let testSongs = []
  let accTime = 0, ans = 0, res = 0;
  for(let ed = 0; ed <= totalLength; ed++){
    let st = ed-playTerm
   
    accTime += chkSongs[ed]
    if(st >= 0){
      accTime -= chkSongs[st]
    }

    if(accTime > res){
      ans = st
    }
    if(st >= 2000)
      testSongs.push({st:numToTime(st), ed:numToTime(ed), accTime:numToTime(accTime)})
  }
  console.log(testSongs);
  console.log(numToTime(ans));
}


solution(	"02:03:55", "00:14:15", ["01:20:15-01:45:14", "00:25:50-00:48:29", "00:40:31-01:00:00", "01:37:44-02:02:30", "01:30:59-01:53:29"])