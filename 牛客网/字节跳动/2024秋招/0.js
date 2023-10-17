const _max = Math.max.bind(Math);
const _min = Math.min.bind(Math);
const _pow = Math.pow.bind(Math);
const _floor = Math.floor.bind(Math);
const _round = Math.round.bind(Math);
const _ceil = Math.ceil.bind(Math);
let log = console.log.bind(console);
log = _ => {}

// 字符转unicode序号
let str = "a";
str.charCodeAt();	// 97
'z'.charCodeAt();	// 122

String.fromCharCode(97);	// a

str= "abc";
str.slice(0,2) // "ab"

str= "abc";
str.split(""); // ["a","b","c"];
let arr = ["a","b","c"];
arr.join("");	// 
