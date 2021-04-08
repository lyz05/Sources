from django.contrib import admin

# Register your models here.
from productsApp.models import Product, ProductImg

class ProductImgInline(admin.StackedInline):
    model = ProductImg
    extra = 1   #默认显示的条数数量

class ProductAdmin(admin.ModelAdmin):
    inlines = [ProductImgInline,]
admin.site.register(Product,ProductAdmin)