const rl = require("readline").createInterface(process.stdin, process.stdout);
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

let h = {}, rd = {}, l = [];

function exta(x) {
    if (!h[x]) return;
    for (let y of h[x]) {
        console.log('Delete:',x,y);
        rd[y] --;
        if (rd[y]===0) {
            l.push(y);
        }
    }
}

void async function () {
    // Write your code here
    line = await readline()
    let n = parseInt(line);
    line = await readline()
    let edges = line.split(',')
    for (edge of edges) {
        let [x, y] = edge.split(":")
        x = parseInt(x);
        y = parseInt(y);
        if (h[x]) {
            h[x].push(y)
        } else h[x] = [y];
        rd[y] = rd[y] ? rd[y] + 1 : 1;
    }
    for (let i=0;i<n;i ++)
        if (!rd[i])
            l.push(i);
    for (let i=0;i<l.length;i ++) {
        exta(l[i]);
    }

    let flag = true;
    for (let i = 0; i < n; i++) {
        if (rd[i] && rd[i]!=0) {
            flag = false;
        }
    }
    console.log(flag ? 1 : 0);
}()
//6
//0:1,1:2,2:3,0:4,4:5,5:3