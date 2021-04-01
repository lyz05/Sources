import django_filters
from django_filters import rest_framework as filters

from api.models import Reader, Book, Borrow, ViewBook, ViewBorrow


class ReaderFilter(filters.FilterSet):
    readerno = django_filters.CharFilter(field_name='readerno', lookup_expr="icontains")  # icontains 包含,忽略大小写
    readername = django_filters.CharFilter(field_name='readername', lookup_expr="icontains")
    identitycard = django_filters.CharFilter(field_name='identitycard', lookup_expr="icontains")
    workunit = django_filters.CharFilter(field_name='workunit', lookup_expr="icontains")

    class Meta:
        model = Reader
        fields = ('readerno', 'readername', 'sex', 'identitycard', 'workunit')


class BookFilter(filters.FilterSet):
    bookno = django_filters.CharFilter(field_name='bookno', lookup_expr="icontains")  # icontains 包含,忽略大小写
    bookname = django_filters.CharFilter(field_name='bookname', lookup_expr="icontains")
    author = django_filters.CharFilter(field_name='author', lookup_expr="icontains")
    press = django_filters.CharFilter(field_name='press', lookup_expr="icontains")

    class Meta:
        model = Book
        fields = ('bookno', 'bookname', 'author', 'press', 'price', 'publishdate', 'shopnum')


class BorrowFilter(filters.FilterSet):
    class Meta:
        model = Borrow
        fields = ('readerno', 'bookno')


class ViewBookFilter(filters.FilterSet):
    bookno = django_filters.CharFilter(field_name='bookno', lookup_expr="icontains")  # icontains 包含,忽略大小写
    bookname = django_filters.CharFilter(field_name='bookname', lookup_expr="icontains")
    author = django_filters.CharFilter(field_name='author', lookup_expr="icontains")
    press = django_filters.CharFilter(field_name='press', lookup_expr="icontains")
    class Meta:
        model = ViewBook
        fields = ('bookno', 'bookname', 'author', 'press', 'publishdate', 'shopnum')


class ViewBorrowFilter(filters.FilterSet):
    class Meta:
        model = ViewBorrow
        fields = {'readerno': ['exact', 'isnull'],'returndate': ['exact', 'isnull']}