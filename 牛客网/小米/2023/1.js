const rl = require("readline").createInterface(process.stdin, process.stdout);
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

let avg_x = 0, avg_y = 0, tot_z = 0;
let l=[];

function calc(i,j) {
    const [x1,y1] = l[i];
    const [x2,y2] = l[j];
    const z2 = (x1-x2)**2+(y1-y2)**2;
    return z2;
}

void async function () {
    // Write your code here
    line = await readline()
    let [n, radius] = line.split(",");
    n = parseInt(n)
    radius = parseFloat(radius)
    for (let i = 0; i < n; i++) {
        line = await readline()
        let [x, y, z] = line.split(",");
        x = parseFloat(x);
        y = parseFloat(y);
        z = parseFloat(z);
        l.push([x,y,z]);
    }
    for (let i=0;i<n;i ++) {
        let [x,y,z] = l[i];
        let tmp = 0;
        for (let j=0;j<n;j ++) {
            tmp += calc(i,j);
        }
        if (tmp/n/2<=radius) {
            tot_z += z*z;
            avg_x += x*z*z;
            avg_y += y*z*z;
        }
    }
    avg_x = avg_x/tot_z;
    avg_y = avg_y/tot_z;
    console.log(avg_x.toFixed(0) + ',' + avg_y.toFixed(0));
    // console.log(avg_x + ',' + avg_y);

}()
