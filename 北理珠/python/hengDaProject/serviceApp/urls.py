from django.urls import path
from .import views


app_name='serviceApp'


urlpatterns=[
    path('download/',views.download,name='download'), #资料下载
    path('platform/',views.platform,name='platform'), #人脸识别开放平台
]
