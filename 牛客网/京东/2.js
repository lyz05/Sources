// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void async function () {
    // Write your code here
    line = await readline()
    let tokens = line.split(' ');
    let n = parseInt(tokens[0]);
    let m = parseInt(tokens[1]);
    let K = parseInt(tokens[2]);
    let dp = [], map = [], ans = 0;
    for (let i = 0; i < n; i++) {
        line = await readline()
        map.push(line)
    }
    for (let k = 0; k < K; k++) {
        dp.push([])
        for (let i = 0; i < n; i++) {
            dp[k].push([]);
            for (let j = 0; j < m; j++) {
                dp[k][i].push(0);
            }
        }
    }
    // console.log(dp);

    for (let k = 0; k < K; k++) {
        for (let i = n - 1; i >= 0; i--) {
            for (let j = 0; j < m; j++) {
                if (k - 1 >= 0 && i + 1 < n && map[i][j] == 'o' && map[i + 1][j] == 'o') {
                    dp[k][i][j] = Math.max(dp[k][i][j], dp[k - 1][i + 1][j] + 1);
                    ans = Math.max(ans, dp[k][i][j]);
                }
            }
        }
    }
    console.log(ans);
}()