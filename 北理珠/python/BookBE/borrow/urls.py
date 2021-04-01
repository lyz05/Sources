from django.conf.urls import url, include
from rest_framework import routers
from . import views

# 使用自动URL路由连接我们的API。
# 另外，我们还包括支持浏览器浏览API的登录URL。


urlpatterns = [
    url('addborrow', views.addborrow),
    url('retborrow', views.retborrow),
    url('renewborrow', views.renewborrow),
]
