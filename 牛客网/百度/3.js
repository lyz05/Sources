const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;


// 归并排序求逆序对
let cnt = 0;
function mergeSort(arr) {
    if (arr.length <= 1) return arr;
    let mid = arr.length >> 1;
    let left = mergeSort(arr.slice(0, mid));
    let right = mergeSort(arr.slice(mid));
    return merge(left, right);
}

function merge(left, right) {
    let ret = [];
    let i = 0, j = 0;
    while (i < left.length && j < right.length) {
        if (left[i] <= right[j]) {
            ret.push(left[i++]);
        } else {
            ret.push(right[j++]);
            cnt += left.length - i;
        }
    }
    while (i < left.length) ret.push(left[i++]);
    while (j < right.length) ret.push(right[j++]);
    return ret;
}


void async function () {
    // Write your code here
    line = await readline()
    let n = parseInt(line)
    line = await readline()
    let a = line.split(' ').map(
        x=>{
            let num = parseInt(x);
            if (num%2==1) return 1; else return 2;
    });
    // console.log(a);
    let b = mergeSort(a);
    // console.log(b);
    console.log(cnt);
}()
