from django.http import HttpResponse, JsonResponse
from django.shortcuts import render
from django.views.decorators.csrf import csrf_exempt

# Create your views here.
grade={'lily':'77','lucy':'88','lilei':'99'}

def index(request):
    return render(request, 'query.html')

@csrf_exempt
def check(request):
    name=request.POST.get('name')
    if name in grade:
        score1 = grade[name]
    else:
        score1= '没有'
    return JsonResponse(data={'score':score1})
