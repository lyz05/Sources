const rl = require("readline").createInterface(process.stdin, process.stdout);
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

function gcd(x, y) {
    if (x % y == 0) {
        return y
    }
    return gcd(y, x % y)
}


// T组数据，给两个数c和n，c是a,b最大公因数，a,b是正整数且不大于n,求a*b的最大值
void async function () {
    // Write your code here
    line = await readline()
    let T = parseInt(line)
    while (T--) {
        line = await readline()
        let [c, n] = line.split(" ").map(x => { return parseInt(x) })
        let ab=-1
        if (c<n) {
            let tmp = Math.floor(n/c)
            ab = tmp*(tmp-1)*c*c;
        } else if (c===n) {
            ab = c*c;
        }
        console.log(ab)
    }

}()
