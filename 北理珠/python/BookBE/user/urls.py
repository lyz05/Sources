from django.conf.urls import url, include
from rest_framework import routers
from . import views

# 使用自动URL路由连接我们的API。
# 另外，我们还包括支持浏览器浏览API的登录URL。
from .views import login, logout, resetpwd, psdalter, userinfo

urlpatterns = [
    url('login', login),
    url('logout', logout),
    url('resetpwd', resetpwd),
    url('psdalter', psdalter),
    url('userinfo', userinfo),
]
