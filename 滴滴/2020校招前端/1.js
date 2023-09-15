const rl = require("readline").createInterface(process.stdin, process.stdout);
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void async function () {
    // Write your code here
    line = await readline()
    const [n, m] = line.split(' ')
    let map = []
    for (let i = 0; i < n; i++) {
        line = await readline();
        map.push(line.split(' '))
    }
    let ans = 0;
    for (let j=0;j<m;j ++) {
        let now = 0;
        for (let i=0;i<n;i ++) {
            now = Math.max(map[i][j],now) 
        }
        ans += now;
    }
    console.log(ans)
}()
