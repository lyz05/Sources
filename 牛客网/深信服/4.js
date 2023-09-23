// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;


void async function () {
    // Write your code here
    line = await readline();
    let K = parseInt(line);
    line = await readline();
    let m = parseInt(line);
    line = await readline();
    let n = parseInt(line);
    if (K < m + n) {
        console.log(0);
    } else {
        line = [];
        let dp = [];
        for (let k = 0; k < K; k++) {
            dp.push([]);
            for (let i = 0; i < m; i++) {
                dp[k].push([]);
                for (let j = 0; j < n; j++) {
                    dp[k][i].push(0);
                    if (k==0 && i == 0 && j == 0)
                        dp[k][i][j] = 1;
                    else {
                        dp[k][i][j] = dp[k - 1][i - 1][j] + 
                            dp[k - 1][i][j - 1] + 
                            dp[k - 1][i + 1][j] + 
                            dp[k - 1][i][j + 1];
                    }
                }
            }
        }
        console.log(dp);
    }

}()

//9,10,12,1
//100,300,200,30
//20