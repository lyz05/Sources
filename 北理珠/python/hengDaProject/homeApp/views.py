from django.db.models import Q
from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
from newsApp.models import MyNew
from productsApp.models import Product


def home(request):
    newList = MyNew.objects.all().filter(~Q(newType='通知公告')).order_by('-publishDate')
    postList = set()
    postNum = 0
    for s in newList:
        if s.photo:
            postList.add(s)
            postNum += 1
        if postNum == 3:
            break

    if (len(newList) > 7):
        newList = newList[0:7]

    noteList = MyNew.objects.all().filter(Q(newType='通知公告')).order_by('-publishDate')
    if (len(noteList) > 4):
        noteList = noteList[0:4]
    productList = Product.objects.all().order_by('-views')
    if (len(productList) > 4):
        productList = productList[0:4]
    return render(request, 'home.html', {
        'active_menu': 'home',
        'postList': postList,
        'newList': newList,
        'noteList': noteList,
        'productList': productList,
    })
