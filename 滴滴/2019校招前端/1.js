let parseQueryString = function(url, key) {
    let querys = url.split("?");
    if (querys.length===1 || !key) return "";
    querys = querys.slice(-1)[0].split('&')
    for (let query of querys) {
        let [key1,value] = query.split('=');
        if (key===key1 && value) {
            return (decodeURIComponent(value))
        }
    }
    return "";
}


ans = parseQueryString('https://www.didikey2=123&chuxi?ng.com/path?ke???&key2=45&6', 'key2')
console.log(ans)