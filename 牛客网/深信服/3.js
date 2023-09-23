// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

function cmp(A,B) {
    if (A['s/t']==B['s/t']) {
        return B['t']-A['t'];
    } else {
        return B['s/t']-A['s/t'];
    }
}
// 01背包
// 一共有n个目标，t是攻击这些目标所需的时间，s是攻击这些目标的得分，每个目标只能攻击一次，问在有限时间T，最高拿多少分
void async function () {
    // Write your code here
    line = await readline();
    let t = line.split(',').map(x=>{return parseInt(x)});
    line = await readline();
    let s = line.split(',').map(x=>{return parseInt(x)});
    line = await readline();
    let T = parseInt(line);
    let dic = [];
    for (let i=0;i<t.length;i ++)  {
        dic.push({
            't':t[i],
            's':s[i],
            's/t':s[i]/t[i],
        });
    }
    dic.sort(cmp);
    let ans = 0;
    for (let i=0;i<dic.length;i ++)  {
        if (T-dic[i]['t']>=0) {
            T = T-dic[i]['t'];
            ans += dic[i]['s'];
        }
    }
    console.log(dic,T)
    console.log(ans);

}()

//9,12,10,1
//100,200,300,30
//10