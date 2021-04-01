from django.http import JsonResponse
from rest_framework.response import Response
from rest_framework import status

MSG_SUCCESS = 200
MSG_FAILED = 403
MsgModel = {"code": MSG_SUCCESS, "message": ""}

class BaseResponse(JsonResponse):
    def __init__(self, code=MSG_SUCCESS, message=""):
        data = {"code": code, "message": message}
        super(BaseResponse, self).__init__(data)

    @staticmethod
    def success(message):
        self = BaseResponse(MSG_SUCCESS,message)
        return self

    @staticmethod
    def fail(message):
        self = BaseResponse(MSG_FAILED,message)
        return self
