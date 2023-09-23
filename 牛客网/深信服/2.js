// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

function calc(a,b) {
    let ret = 1;
    if (b===0) return 1;
    if (b===1) return a;
    ret = calc(a,Math.floor(b/2));
    if (b%2===0) { 
        return (ret*ret)%100;
    } else {
        return (((ret*ret)%100)*a)%100;
    }
}

void async function () {
    // Write your code here
    line = await readline();
    let ans='';
    for (let i=0;i<line.length;i ++) {
        let st = line.slice(0,i);
        let en = line.slice(i);
        let s = en+st
        if (s>ans) ans = s;        
    }
    console.log(ans);

}()