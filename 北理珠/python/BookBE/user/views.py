from django.contrib import auth
from django.contrib.auth import authenticate
from django.contrib.auth.models import User, AnonymousUser
from django.http import HttpResponse, JsonResponse
from django.utils.datastructures import MultiValueDictKeyError

# Create your views here.
# @require_http_methods(['POST'])
from django.views.decorators.http import require_http_methods

from api.models import Reader
from utils.BaseResponse import BaseResponse

AlterPasswordModel = ['username', 'pwd', 'newpwd', 'newpwd2']
UserModel = ['username', 'password', 'locale']


@require_http_methods(['POST'])
def login(request):
    username = request.POST['username']
    password = request.POST['password']
    user = authenticate(request, username=username, password=password)
    if user is not None:
        auth.login(request, user)
        if user.is_superuser:
            return BaseResponse(603, '读者登录成功')
        else:
            return BaseResponse(604, '管理员登录成功')
        # Redirect to a success page.
    else:
        return BaseResponse.fail('用户名或密码错误')
        # Return an 'invalid login' error message.


def logout(request):
    auth.logout(request)
    return BaseResponse.success('注销操作完成')

@require_http_methods(['POST'])
def resetpwd(request):
    readerno = request.POST['readerno']
    user = User.objects.get(username=readerno)
    if user is None:
        return BaseResponse.fail('该用户不存在')
    user.set_password("")
    user.save()
    return BaseResponse.success('重置读者密码成功')

@require_http_methods(['POST'])
def psdalter(request):
    dict = {}
    for item in AlterPasswordModel:
        dict[item] = request.POST[item]
    user = auth.authenticate(username=dict['username'], password=dict['pwd'])
    if dict['newpwd'] != dict['newpwd2']:
        return BaseResponse.fail('两次输入的新密码不一致')
    if dict['pwd'] == dict['newpwd']:
        return BaseResponse.fail('旧密码与新密码相同')

    if user is not None:
        user.set_password(dict['newpwd'])
        user.save()
        return BaseResponse.success('更新密码成功')
    else:
        return BaseResponse.fail('用户名或密码错误')


def userinfo(request):
    current_user = request.user
    username = current_user.username
    if not request.user.is_authenticated:
        return JsonResponse({'username': None, 'readername': None, 'role': None})
    if current_user.is_superuser:
        role = "admin"
        readername = None
    else:
        role = "reader"
        reader = Reader.objects.get(readerno=username)
        readername = reader.readername
        #readername = reader.objects[0].readername
    return JsonResponse({'username': username, 'readername': readername, 'role': role})
