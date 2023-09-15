const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;
let log = console.log.bind(console);

function work(s) {
    let flag = true;
    while (flag) {
        flag = false;
        s = s.split('')
        let length = s.length
        for (let i = length - 3; i >= 0; i--) {
            let num = parseInt(s[i + 1] + s[i + 2], 16)
            if (s[i] == '%' && !isNaN(parseInt(s[i + 1],16)) && !isNaN(parseInt(s[i + 2],16))) {
                flag = true;
                s[i] = String.fromCharCode(num)
                s[i + 1] = '';
                s[i + 2] = '';
            }
        }
        s = s.join('');
    }
    return s;
}

void async function () {
    // Write your code here
    line = await readline()
    log(line)
    let T = parseInt(line)
    for (let i = 0; i < T; i++) {
        line = await readline()
        console.log(work(line))
    }
}()
