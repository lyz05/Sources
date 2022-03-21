import xadmin

# Register your models here.
from productsApp.models import Product, ProductImg

class ProductImgInline(object):
    model = ProductImg
    extra = 1   #默认显示的条数数量

class ProductAdmin(object):
    inlines = [ProductImgInline,]
xadmin.site.register(Product,ProductAdmin)