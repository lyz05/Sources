from django.conf.urls import url, include
from rest_framework import routers
from . import views

urlpatterns = [
    url('addborrow', views.addborrow),
    url('retborrow', views.retborrow),
    url('renewborrow', views.renewborrow),
]
