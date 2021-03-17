from django.shortcuts import HttpResponse


def download(request):
    html='<html><body>资料下载</body></html>'
    return HttpResponse(html)


def platform(request):
    html = '<html><body>人脸识别开放平台</body></html>'
    return HttpResponse(html)
