const rl = require("readline").createInterface(process.stdin, process.stdout);
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

function gcd(x, y) {
    if (x % y == 0) {
        return y
    }
    return gcd(y, x % y)
}


void async function () {
    // Write your code here
    line = await readline()
    let T = parseInt(line)
    while (T--) {
        line = await readline()
        let [c, n] = line.split(" ").map(x => { return parseInt(x) })
        let ab=-1;
        if (c<=n)
            for (let a = 1; a*c <= n; a++)
                for (let b = 1; b*c <= n; b++) {
                    if (1 === gcd(a, b)) {
                        ab = Math.max(ab,a*b*c*c);
                    }
            }
        console.log(ab)
    }

}()
