const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void async function () {
    // Write your code here
    line = await readline()
    while (line = await readline()) {
        let [x, a, b] = line.split(' ');
        let priceperbig = Math.min(3 * a, b);
        let ans = parseInt(x / 1500) * priceperbig;
        let left = x%1500;
        ans += Math.min(Math.ceil(left/500)*a,b);
        console.log(ans);
    }
}()
