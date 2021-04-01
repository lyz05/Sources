from django.core import serializers
from django.http import JsonResponse, HttpResponse
from django.shortcuts import render

# Create your views here.
from api.models import Book, Reader, Borrow
from utils.BaseResponse import BaseResponse


def borrowreaders(request):
    current_user = request.user
    dic = {}
    dic['readerno'] = Reader.objects.get(readerno=current_user.username)
    table = request.GET['table']
    if table == 'Borrow':
        borrows = Borrow.objects.filter(readerno=dic['readerno'], returndate=None)
        return
    else:
        borrows = Borrow.objects.filter(readerno=dic['readerno'], returndate=not None)


    ret = ""
    # for borrow in borrows:
    #     ret.append({"readerno": borrow.readerno, "bookno": borrow.bookno, "borrowdate": borrow.borrowdate,
    #                 "shoulddate": borrow.shoulddate, "returndate": borrow.returndate})
    # print(borrows)
    return HttpResponse("")


def bookreaders(request):
    pass
