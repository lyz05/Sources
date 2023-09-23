const rl = require("readline").createInterface(process.stdin, process.stdout);
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

let n,k,ans=0,positions;

function dfs(start , dep , tmp) {
    if (dep===k) {
        ans = Math.max(ans,tmp);
        return;
    }
    for (let i=start+1;i<n;i ++) {
        const pos = start>-1?positions[i]-positions[start]:positions[i];
        dfs(i,dep+1,Math.min(tmp,pos));
    }
}
    
//有一条直线，起点是0，终点是m。给一个数组a，对于每一个元素a[i]，表示可以在此安装路灯，一共要安装k个路灯，求最近的两个路灯的最大值。
void async function () {
    // Write your code here
    line = await readline();
    [n, k] = line.split(" ").map(x => { return parseInt(x) })
    line = await readline()
    positions = line.split(" ").map(x => { return parseInt(x) })
    console.log(positions)
    dfs(-1,0,Infinity)
    console.log(ans)
}()
