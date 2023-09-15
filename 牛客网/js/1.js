const _max = Math.max.bind(Math);
const _min = Math.min.bind(Math);
const _pow = Math.pow.bind(Math);
const _floor = Math.floor.bind(Math);
const _round = Math.round.bind(Math);
const _ceil = Math.ceil.bind(Math);
let log = console.log.bind(console);
log = _ => { };
const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void async function () {
    // Write your code here
    line = await readline()
    // let line = "xabcabcx"
    let length = line.length
    let flag = false
    for (let half_ans = parseInt(length / 2); half_ans > 0; half_ans--) {
        let ans = half_ans * 2;
        log(ans)
        for (let i = 0; i + half_ans + half_ans <= length; i++) {
            str1 = line.slice(i, i + half_ans);
            str2 = line.slice(i + half_ans, i + 2 * half_ans);
            flag = str1 === str2;
            if (flag)
                break
        }
        if (flag) {
            console.log(ans)
            break
        }
    }
    if (!flag) {
        console.log(0)
    }
}()
