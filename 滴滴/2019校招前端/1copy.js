let parseQueryString = function (url, key) {
    //请在此处编写你的代码，其他部分请勿修改，否则不记分。
    //begin
    var urlRet = /^[^#]+\?(.*)(?:$|#)/.exec(url);

    if (!urlRet || !key) {
        return "";
    }

    var searchReg = new RegExp("(?:^|&)" + key + "=([^&]*)(&|$)"),
        searchRet = searchReg.exec(urlRet[1]);
    if (searchRet) {
        return decodeURIComponent(searchRet[1])
    } else {
        return "";
    }


    //end
    // 以下代码请勿修改
}


ans = parseQueryString('https://www.didikey2=123&chuxi?ng.com/path?ke:key2=4$56&key_3=key2', 'key2')
console.log(ans)