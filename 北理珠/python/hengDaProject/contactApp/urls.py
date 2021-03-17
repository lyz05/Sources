from django.urls import path
from . import views


app_name='contactApp'

urlpatterns=[
    path('contact/',views.contact,name='contact'), #欢迎咨询
    path('recruit/',views.recruit,name='recruit'), #加入恒达
]
