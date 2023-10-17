const rl = require("readline").createInterface(process.stdin, process.stdout);
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

let avg_x = 0, avg_y = 0, tot_z = 0;

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
        tot_z += z*z;
        avg_x += x*z*z;
        avg_y += y*z*z;
    }
    avg_x = avg_x/tot_z;
    avg_y = avg_y/tot_z;
    console.log(avg_x.toFixed(0) + ',' + avg_y.toFixed(0));
    // console.log(avg_x + ',' + avg_y);

}()
