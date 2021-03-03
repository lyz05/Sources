from django.shortcuts import render

# Create your views here.

def classInfo(request):
    context = {}
    context['name'] = 'Python Web应用开发'
    context['palce'] = 'MB505'
    return render(request,'class.html',context)