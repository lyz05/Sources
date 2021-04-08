from rest_framework.views import exception_handler as drf_exception_handler
from django.db import DatabaseError

from utils.BaseResponse import BaseResponse


def exception_handler(exc, context):
    """
    自定义异常处理
    :param exc: 异常
    :param context: 抛出异常的上下文
    :return: Response响应对象
    """
    # 调用drf框架原生的异常处理方法
    response = drf_exception_handler(exc, context)

    if response is None:
        view = context['view']
        if isinstance(exc, DatabaseError):
            # 数据库异常
            print('[%s] %s' % (view, exc))
            response = BaseResponse.fail('数据库错误！')
    else:
        message = ""
        for key, value in response.data.items():
            message += key+":"+str(value[0])+" "
            break
        return BaseResponse.fail(message)
    return response