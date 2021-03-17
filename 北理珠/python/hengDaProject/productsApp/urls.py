from django.urls import path
from .import views


app_name='productsApp'


urlpatterns=[
    path('robot/',views.robot,name='robot'), #家用机器人
    path('monitoring/',views.monitoring,name='monitoring'), #智能监控
    path('face/',views.face,name='face')
] #人脸识别解决方案