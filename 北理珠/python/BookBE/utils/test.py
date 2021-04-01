from api.models import Reader, Book, Borrow

lyz = Reader.objects.create(readerno='lyz', readername='lyz', sex='男', identitycard='121', workunit='123')
myy = Reader.objects.create(readerno='myy', readername='myy', sex='女', identitycard='121', workunit='123')
book1 = Book.objects.create(bookno='book1', bookname='book1', author='myy', press='123', price=12,
                            publishdate='2020-01-02', shopnum=10)
book2 = Book.objects.create(bookno='book2', bookname='book2', author='lyz', press='123', price=12,
                            publishdate='2020-01-02', shopnum=10)
borrow1 = Borrow(reader=lyz,book=book1,borrowdate='2020-01-02',shoulddate='2020-01-02')
borrow1.save()
print()