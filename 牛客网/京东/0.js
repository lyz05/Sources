// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void async function () {
    // Write your code here
    line = await readline()
    let tokens = line.split(' ');
    let n = parseInt(tokens[0]);
    let x = parseInt(tokens[1]);
    let ans = 0;
    while (n --) {
        line = await readline()
        let tokens = line.split(' ');
        let a = parseInt(tokens[0]);
        let b = parseInt(tokens[1]);
        ans = Math.abs(a-b)>=x?ans+1:ans;
    }
    console.log(ans);
}()