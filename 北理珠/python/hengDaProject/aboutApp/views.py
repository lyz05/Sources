from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
def survey(request):
    return HttpResponse("企业概况")


def honor(request):
    return HttpResponse("荣誉资质")