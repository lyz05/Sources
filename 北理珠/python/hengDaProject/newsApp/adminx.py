import xadmin

# Register your models here.
from newsApp.models import MyNew


class MyNewAdmin(object):
    style_fields = {'description':'ueditor'}

xadmin.site.register(MyNew,MyNewAdmin)