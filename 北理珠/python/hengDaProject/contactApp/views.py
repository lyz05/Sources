from django.shortcuts import HttpResponse, render

from contactApp.models import Ad


def contact(request):
    return render(request, 'contact.html', {
        'active_menu': 'employ',
        'sub_menu': 'contact'
    })


def recruit(request):
    AdList = Ad.objects.all().order_by('-publishDate')
    return render(request, 'recruit.html', {
        'active_menu': 'employ',
        'sub_menu': 'recruit',
        'AdList': AdList
    })
