const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

//素数筛
let prime = [];
let isPrime = [];
function initPrime(n) {
    isPrime = new Array(n+1).fill(true);
    isPrime[0] = isPrime[1] = false;
    for (let i = 2; i <= n; i++) {
        if (isPrime[i]) {
            prime.push(i);
            for (let j = i*i; j <= n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

void async function () {
    // Write your code here
    line = await readline()
    let [n,k] = line.split(' ').map(x=>parseInt(x));
    initPrime(n);
    let ans = 0;
    if (prime.length <= k) {
        ans = n;
    } else {
        ans = prime[k]-1;
    }
    console.log(ans);
    // console.log(prime);
}()
