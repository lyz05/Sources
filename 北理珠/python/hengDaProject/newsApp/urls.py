from django.urls import path
from .import views


app_name='newsApp'


urlpatterns=[
    path('company/',views.company,name='company'), #企业要闻
    path('industry/',views.industry,name='industry'), #行业新闻
    path('notice/',views.notice,name='notice'), #通知公告
]
