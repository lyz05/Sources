from django.contrib.auth.models import User
from django.db import models


class Book(models.Model):
    bookno = models.CharField(max_length=10, primary_key=True)
    bookname = models.CharField(max_length=40)
    author = models.CharField(max_length=20)
    press = models.CharField(max_length=30)
    price = models.DecimalField(max_digits=7, decimal_places=2)
    publishdate = models.DateField()
    shopnum = models.IntegerField()

    def __str__(self):
        return self.bookname


class Reader(models.Model):
    readerno = models.CharField(max_length=8, unique=True, primary_key=True)
    readername = models.CharField(max_length=8)
    sex = models.CharField(max_length=2)
    identitycard = models.CharField(max_length=18)
    workunit = models.CharField(max_length=50)

    # books = models.ManyToManyField(Book, through='Borrow')
    def __str__(self):
        return self.readername


class Borrow(models.Model):
    readerno = models.ForeignKey(Reader, on_delete=models.CASCADE)
    bookno = models.ForeignKey(Book, on_delete=models.CASCADE)
    borrowdate = models.DateField()
    shoulddate = models.DateField()
    returndate = models.DateField(null=True)


class ViewBorrow(models.Model):
    readerno = models.CharField(max_length=8, unique=True, primary_key=True)
    readername = models.CharField(max_length=8)
    bookno = models.CharField(max_length=10)
    bookname = models.CharField(max_length=40)
    author = models.CharField(max_length=20)
    press = models.CharField(max_length=30)
    borrowdate = models.DateField()
    shoulddate = models.DateField()
    returndate = models.DateField(null=True)

    class Meta:
        db_table = 'ViewBorrow'

class ViewBook(models.Model):
    bookno = models.CharField(max_length=10, primary_key=True)
    bookname = models.CharField(max_length=40)
    author = models.CharField(max_length=20)
    press = models.CharField(max_length=30)
    publishdate = models.DateField()
    shopnum = models.IntegerField()
    curnum = models.IntegerField()

    class Meta:
        db_table = 'ViewBook'