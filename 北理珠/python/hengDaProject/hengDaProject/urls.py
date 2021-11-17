"""hengDaProject URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from homeApp.views import home
from django.conf.urls import include
from django.conf import settings
from django.conf.urls.static import static
import xadmin

urlpatterns = [
    path('admin/',xadmin.site.urls),
    path('', home, name='home'),
    path('aboutApp/', include('aboutApp.urls'), name='about'),
    path('contactApp/', include('contactApp.urls'), name='contact'),
    path('newsApp/', include('newsApp.urls'), name='news'),
    path('productsApp/', include('productsApp.urls'), name='products'),
    path('serviceApp/', include('serviceApp.urls'), name='service'),
    path('scienceApp/', include('scienceApp.urls'), name='science'),
    path('ueditor/',include('DjangoUeditor.urls')),
    path('search/',include('haystack.urls'))
]

if settings.DEBUG:
    urlpatterns += static(settings.MEDIA_URL,
                          document_root=settings.MEDIA_ROOT)
