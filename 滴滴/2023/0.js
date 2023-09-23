const rl = require("readline").createInterface(process.stdin, process.stdout);
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

function QuickSort(arr, start, end) {
    const range = arr.slice(start, end + 1);
    range.sort((a, b) => a - b);
    arr.splice(start, range.length, ...range);
    return arr;
}

void async function () {
    // Write your code here
    line = await readline()

    console.log()
}()
