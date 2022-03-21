import xadmin
from aboutApp.models import Award
from xadmin import views


# Register your models here.
class AwardAdmin(object):
    list_display = ['description', 'photo']


xadmin.site.register(Award, AwardAdmin)

class GlobalSetting(object):
    site_title = "企业门户网站后台管理系统"#页面左上角title内容
    site_footer = "企业门户网站后台管理系统"#页脚内容
xadmin.site.register(views.CommAdminView,GlobalSetting)