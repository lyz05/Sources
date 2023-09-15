const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

function check(ans, n, m, N, M) {
    let now = new Map();
    for (let i = 0; i < ans; i++) {
        if (m.has(n[i])) {
            if (now.has(n[i])) {
                now.set(n[i], now.get(n[i]) + 1);
            } else {
                now.set(n[i], 1);
            }
        }
    }
    if (now.size === M)
        return true;
    for (let j = ans; j < N; j++) {
        let i = j - ans;
        if (m.has(n[i]) && now.get(n[i]) > 0) {
            now.set(n[i], now.get(n[i]) - 1);
            if (now.get(n[i]) === 0) {
                now.delete(n[i]);
            }
        }
        if (m.has(n[j])) {
            if (now.has(n[j])) {
                now.set(n[j], now.get(n[j]) + 1);
            } else {
                now.set(n[j], 1);
            }
        }
        if (now.size === M)
            return true;
    }
    return false;
}

void async function () {
    // Write your code here
    line = await readline()
    let T = parseInt(line)
    while (T--) {
        line = await readline()
        let N = parseInt(line)
        line = await readline()
        let n = line.split(' ');
        line = await readline()
        let M = parseInt(line)
        line = await readline()
        let m = line.split(' ');
        m = new Set(m)

        let l = M, r = N, ans = 0;
        while (l <= r) {
            let mid = (l + r) >> 1;
            if (check(mid, n, m, N, M)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        console.log(ans)

    }

}()