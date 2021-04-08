from django.urls import path
from .import views


app_name='productsApp'


urlpatterns=[
    path('products/<str:productName>/',views.products,name='products')
]