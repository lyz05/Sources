from rest_framework import viewsets
from rest_framework.response import Response


class CustomViewSet(viewsets.ModelViewSet):
    def create(self, request, *args, **kwargs):
        response = super().create(request, *args, **kwargs)
        print('创建一条记录')
        return response

    def retrieve(self, request, *args, **kwargs):
        response = super().retrieve(request, *args, **kwargs)
        print('查询一条记录')
        return response

    def update(self, request, *args, **kwargs):
        response = super().update(request, *args, **kwargs)
        print('更新一条记录')
        return response

    def destroy(self, request, *args, **kwargs):
        response = super().destroy(request, *args, **kwargs)
        print('删除一条记录')
        return response

    def list(self, request, *args, **kwargs):
        response = super().list(request, *args, **kwargs)
        response.data = {"total": len(response.data), "rows": response.data}
        print('列出所有记录')
        return response
