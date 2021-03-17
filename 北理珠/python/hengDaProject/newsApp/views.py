from django.shortcuts import HttpResponse


def company(request):
    html='<html><body>企业要闻</body></html>'
    return HttpResponse(html)


def industry(request):
    html = '<html><body>行业新闻</body></html>'
    return HttpResponse(html)


def notice(request):
    html = '<html><body>通知公告</body></html>'
    return HttpResponse(html)
