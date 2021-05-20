from django.urls import path
from . import views

app_name = 'serviceApp'

urlpatterns = [
    path('service/<str:serviceName>/', views.service, name='service'),  # 资料下载
    path('getDoc/<int:id>/', views.getDoc, name='getDoc'),
    path('facedetect/', views.facedetect, name='facedetect'),
    path('facedetectDemo/', views.facedetectDemo, name='facedetectDemo')
]
