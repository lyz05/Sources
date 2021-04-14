from django.shortcuts import HttpResponse, render, get_object_or_404

from newsApp.models import MyNew
import productsApp.views
from pyquery import PyQuery as pq


def news(request, newName):
    submenu = newName
    newName = newName.replace('company', '企业要闻')
    newName = newName.replace('industry', '行业新闻')
    newName = newName.replace('notice', '通知公告')

    newList = MyNew.objects.all().filter(newType=newName).order_by('-publishDate')
    for mynew in newList:
        html = pq(mynew.description)
        mynew.mytxt = pq(html)('p').text()
    (pageData, newList) = productsApp.views.pageinator(newList, int(request.GET.get('page', 1)), size=5)
    return render(request, 'newList.html', {
        'active_menu': 'news',
        'sub_menu': submenu,
        'newName': newName,
        'newList': newList,
        'pageData': pageData,
    })


def newDetail(request, id):
    mynew = get_object_or_404(MyNew, id=id)
    mynew.views += 1
    mynew.save()
    return render(request, 'newDetail.html', {
        'active_menu': 'news',
        'mynew': mynew,
    })
