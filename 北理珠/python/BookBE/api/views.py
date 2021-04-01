import datetime as dt

from django.contrib.auth.models import User
from rest_framework import viewsets

# Create your views here.
from api.models import Book, Reader, Borrow, ViewBorrow, ViewBook
from utils.BaseResponse import BaseResponse
from utils.CustomViewSet import CustomViewSet
from . import Filter
from .serializers import UserSerializer, BookSerializer, ReaderSerializer, BorrowSerializer, ViewBorrowSerializer, \
    ViewBookSerializer


class UserViewSet(viewsets.ModelViewSet):
    """
    允许用户查看或编辑的API路径。
    """
    queryset = User.objects.all()
    serializer_class = UserSerializer


class BorrowViewSet(CustomViewSet):
    """
    允许查看或编辑借阅记录的API路径。
    """
    queryset = Borrow.objects.all()
    serializer_class = BorrowSerializer
    filter_class = Filter.BorrowFilter

    def update(self, request, *args, **kwargs):
        request.data._mutable = True  # 允许修改数据
        today = dt.date.today()
        if (request.data['returndate'] == ""):
            shoulddate = today + dt.timedelta(days=31)
            request.data['shoulddate'] = shoulddate
            print(request.data['shoulddate'])
        else:
            request.data['returndate'] = today
        response = super().update(request, *args, **kwargs)
        print('更新一条记录')
        return response


class BookViewSet(CustomViewSet):
    """
    允许查看或编辑Books的API路径。
    """
    queryset = Book.objects.all()
    serializer_class = BookSerializer
    filter_class = Filter.BookFilter

    def create(self, request, *args, **kwargs):
        response = super().create(request, *args, **kwargs)
        return BaseResponse.success("添加书本成功")

    def update(self, request, *args, **kwargs):
        response = super().update(request, *args, **kwargs)
        return BaseResponse.success("修改书本成功")

    def destroy(self, request, *args, **kwargs):
        response = super().destroy(request, *args, **kwargs)
        return BaseResponse.success("删除书本成功")


class ReaderViewSet(CustomViewSet):
    """
    允许查看或编辑Reader的API路径。
    """
    queryset = Reader.objects.all()
    serializer_class = ReaderSerializer
    # filter_backends = (filters.DjangoFilterBackend,)
    filter_class = Filter.ReaderFilter

    # !!!警告：缺少事务保证
    def create(self, request, *args, **kwargs):
        # print(request.data)
        request.data._mutable = True  # 允许修改数据
        response = super().create(request, *args, **kwargs)
        user = User.objects.create_user(username=request.data['readerno'], password="")
        return BaseResponse.success("添加读者成功")

    def update(self, request, *args, **kwargs):
        response = super().update(request, *args, **kwargs)
        return BaseResponse.success("修改读者成功")

    def destroy(self, request, *args, **kwargs):
        response = super().destroy(request, *args, **kwargs)
        user = User.objects.get(username=kwargs['pk']).delete()
        return BaseResponse.success("删除读者成功")


class ViewBorrowViewSet(CustomViewSet):
    queryset = ViewBorrow.objects.all()
    serializer_class = ViewBorrowSerializer
    filter_class = Filter.ViewBorrowFilter

    def list(self, request, *args, **kwargs):
        response = super().list(request, *args, **kwargs)
        print('列出所有记录')
        return response


class ViewBookViewSet(CustomViewSet):
    queryset = ViewBook.objects.all()
    serializer_class = ViewBookSerializer
    filter_class = Filter.ViewBookFilter
