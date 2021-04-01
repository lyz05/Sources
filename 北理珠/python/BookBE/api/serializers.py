# 序列化数据库表
from collections import OrderedDict

from django.contrib.auth.models import User, Group
from rest_framework import serializers

from api.models import Book, Reader, Borrow, ViewBook, ViewBorrow


class UserSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        # fields = '__all__'
        fields = ('url', 'username', 'password', 'is_superuser', 'last_login')


class BookSerializer(serializers.ModelSerializer):
    class Meta:
        model = Book
        fields = '__all__'


class BorrowSerializer(serializers.ModelSerializer):
    class Meta:
        model = Borrow
        fields = '__all__'


class ReaderSerializer(serializers.ModelSerializer):
    class Meta:
        model = Reader
        fields = ('readerno', 'readername', 'sex', 'identitycard', 'workunit')
        # fields = '__all__'

    def to_representation(self, instance):
        ret = super().to_representation(instance)
        return ret

class ViewBookSerializer(serializers.ModelSerializer):
    class Meta:
        model = ViewBook
        fields = '__all__'

class ViewBorrowSerializer(serializers.ModelSerializer):
    class Meta:
        model = ViewBorrow
        fields = '__all__'