from django.shortcuts import HttpResponse


def robot(request):
    html='<html><body>家用机器人</body></html>'
    return HttpResponse(html)


def monitoring(request):
    html = '<html><body>智能监控</body></html>'
    return HttpResponse(html)


def face(request):
    html = '<html><body>人脸识别解决方案</body></html>'
    return HttpResponse(html)
