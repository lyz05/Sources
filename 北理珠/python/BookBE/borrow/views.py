from django.http import JsonResponse
from django.shortcuts import render

# Create your views here.
from api.models import Borrow, Book, Reader
from utils.BaseResponse import BaseResponse
import datetime as dt

# 普通读者的三个借阅书籍操作（借书，续借，还书）
# 借书
def addborrow(request):
    current_user = request.user
    today = dt.date.today()
    dic = {}
    dic['bookno'] = Book.objects.get(bookno=request.GET['bookno'])
    dic['readerno'] = Reader.objects.get(readerno=current_user.username)
    dic['borrowdate'] = today
    dic['shoulddate'] = today + dt.timedelta(days = 31)
    #dic['returndate'] = ""
    borrow = Borrow.objects.filter(bookno=dic['bookno'], readerno=dic['readerno'], returndate=None)
    if borrow.exists():
        return BaseResponse.fail("这本书你已经借过了")
    borrow = Borrow.objects.create(**dic)
    if borrow is not None:
        return BaseResponse.success("借书成功")
    else:
        return BaseResponse.fail("借书失败")

#还书
def retborrow(request):
    current_user = request.user
    today = dt.date.today()

    dic = {}
    dic['bookno'] = Book.objects.get(bookno=request.GET['bookno'])
    dic['readerno'] = Reader.objects.get(readerno=current_user.username)
    #dic['returndate'] = ""
    borrow = Borrow.objects.get(bookno=dic['bookno'],readerno=dic['readerno'],returndate=None)
    borrow.returndate = today
    borrow.save()
    if borrow is not None:
        return BaseResponse.success("还书成功")
    else:
        return BaseResponse.fail("还书失败")

#续借
def renewborrow(request):
    current_user = request.user
    today = dt.date.today()

    dic = {}
    dic['bookno'] = Book.objects.get(bookno=request.GET['bookno'])
    dic['readerno'] = Reader.objects.get(readerno=current_user.username)
    #dic['returndate'] = ""
    borrow = Borrow.objects.get(bookno=dic['bookno'],readerno=dic['readerno'],returndate=None)
    borrow.shoulddate = today + dt.timedelta(days = 31)
    borrow.save()
    if borrow is not None:
        return BaseResponse.success("续借成功")
    else:
        return BaseResponse.fail("续借失败")
