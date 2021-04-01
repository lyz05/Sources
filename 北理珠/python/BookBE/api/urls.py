from django.conf.urls import url, include
from rest_framework import routers
from . import views

# 不自动添加斜杠，为了兼容已经开发完的前端
router = routers.DefaultRouter(trailing_slash=False)
router.register(r'users', views.UserViewSet)
router.register(r'Books', views.BookViewSet)
router.register(r'Readers', views.ReaderViewSet)
#router.register(r'borrow', views.BorrowViewSet)
router.register(r'ViewBorrow', views.ViewBorrowViewSet)
router.register(r'ViewBook', views.ViewBookViewSet)

# 使用自动URL路由连接我们的API。
# 另外，我们还包括支持浏览器浏览API的登录URL。
urlpatterns = [
    url(r'^', include(router.urls)),
]
