const rl = require("readline").createInterface(process.stdin, process.stdout);
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

const dic1 = 'qwertasdfgzxcv',dic2 = 'yuiophjklbnm';

function calc(s1,s2) {
    let ret = 0;
    if (s1.length===s2.length) {
        for (let i=0;i<s1.length;i ++) {
            ret += (s1[i]!=s2[i])?1:0;
        }
    } else ret += 3*Math.abs(s1.length-s2.length)
    return ret;
}

void async function () {
    // Write your code here
    line = await readline()
    let s = line.split(" "), size = s.length;
    let ans = [];
    for (let i = 0; i < size; i++) {
        const score = calc(s[0], s[i]);
        ans.push({
            s: s[i],
            score: score
        })
    }
    ans.sort((a,b)=>{
        return a.score-b.score;
    })
    ans = ans.slice(1,4).map((x)=>{return x.s}).join(" ")
    console.log(ans)
}()
