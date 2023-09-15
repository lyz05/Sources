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
    let n = parseInt(line)
    line = await readline()
    let a = line.split(' ')
    let nums = [], ops = ['+'];
    for (var i = 0; i < n; i++) {
        nums.push(parseInt(a[2 * i]));
        ops.push(a[2 * i + 1])
    }
    // console.log(nums, ops);
    let l = 0, r = 0;
    while (r < n) {
        while (r < n && ops[r] == ops[l]) r++;
        r --;
        if (ops[l] === '+' || ops[l] === '-') {
            if (r + 1 < n && (ops[r + 1] == '*' || ops[r + 1] == '/')) {
                QuickSort(nums, l, r - 1);
            } else {
                QuickSort(nums, l, r);
            }
        }
        if (ops[l] == '*') {
            if (l > 0 && (ops[l - 1] == '+' || ops[l - 1] == '-'))
                QuickSort(nums, l - 1, r);
            else
                QuickSort(nums, l, r);
        }
        if (ops[l] == '/') {
            QuickSort(nums, l, r);
        }
        r++;
        l = r
    }
    let ans = []
    for (var i = 0; i < n; i++) {
        ans.push(ops[i])
        ans.push(nums[i])
    }
    console.log(ans.slice(1).join(" "))
}()
