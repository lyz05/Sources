from django.contrib import admin

# Register your models here.
from .models import Ad
from .models import Resume
from django.utils.safestring import mark_safe


class ResumeAdmin(admin.ModelAdmin):
    list_display = ('name', 'status', 'personID', 'birth', 'edu', 'school',
                    'major', 'position', 'image_data')

    def image_data(self, obj):
        return mark_safe(u'<img src="%s" width="120px" />' % obj.photo.url)

    image_data.short_description = u'个人照片'

admin.site.register(Ad)
admin.site.register(Resume, ResumeAdmin)
