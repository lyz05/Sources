from django.shortcuts import HttpResponse, render

from productsApp.models import Product


def robot(request):
    html = '<html><body>家用机器人</body></html>'
    return HttpResponse(html)


def monitoring(request):
    html = '<html><body>智能监控</body></html>'
    return HttpResponse(html)


def face(request):
    html = '<html><body>人脸识别解决方案</body></html>'
    return HttpResponse(html)


def products(request, productName):
    submenu = productName
    if productName == 'robot':
        productName = '家用机器人'
    elif productName == 'monitor':
        productName = '智能监控'
    else:
        productName = '人脸识别解决方案'

    productList = Product.objects.all().filter(productType=productName).order_by('-publishDate')

    return render(request, 'productList.html', {
        'active_menu': 'products',
        'sub_menu': submenu,
        'productName': productName,
        'productList': productList,
    })
