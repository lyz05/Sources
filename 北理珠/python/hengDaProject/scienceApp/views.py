from django.shortcuts import render


def science(request):
    return render(request, 'science.html', {'active_menu': 'science'})
