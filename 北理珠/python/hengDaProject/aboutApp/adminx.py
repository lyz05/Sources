import xadmin
from aboutApp.models import Award


# Register your models here.
class AwardAdmin(xadmin.ModelAdmin):
    list_display = ['description', 'photo']


xadmin.site.register(Award, AwardAdmin)
xadmin.site.site_header = "企业门户网站后台管理系统"
xadmin.site.site_title = "企业门户网站后台管理系统"