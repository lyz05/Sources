const rl = require("readline").createInterface(process.stdin, process.stdout);
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void async function () {
    // Write your code here
    let dic = {}, l = [];
    while (line = await readline()) {
        if (line === "END") break;
        l.push(line);
        let [radix, num] = line.split("#")
        num = parseInt(num, parseInt(radix));
        dic[num] = dic[num] ? dic[num] + 1 : 1;
    }
    let flag = false;
    for (let i = 0; i < l.length; i++) {
        let [radix, num] = l[i].split("#")
        num = parseInt(num, parseInt(radix));
        if (dic[num] === 1) {
            console.log(l[i]);
            flag = true;
        }
    }
    if (!flag)
        console.log("None")
}()
