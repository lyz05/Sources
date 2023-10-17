const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

let a,b,c;

function gcd(x,y) {
    return y==0?x:gcd(y,x%y);
}

function calc(num) {
    let ret = Math.floor(num/a) +Math.floor(num/b)+Math.floor(num/c);
    let ab = a*b/gcd(a,b),ac = a*c/gcd(a,c),bc = b*c/gcd(b,c);
    let abc = ab*c/gcd(ab,c);
    ret -= Math.floor(num/ab);
    ret -= Math.floor(num/ac);
    ret -= Math.floor(num/bc);
    ret += Math.floor(num/abc);
    return ret;
}

void async function () {
    // Write your code here
    line = await readline()
    let T = parseInt(line)
    for (let i = 0; i < T; i++) {
        line = await readline()
        let tokens = line.split(' ');
        a = parseInt(tokens[0]);
        b = parseInt(tokens[1]);
        c = parseInt(tokens[2]);
        let l = parseInt(tokens[3]);
        let r = parseInt(tokens[4]);
        let ans = calc(r) - calc(l-1)
        console.log(ans);
    }
}()
