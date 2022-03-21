import xadmin

# Register your models here.
from serviceApp.models import Doc

xadmin.site.register(Doc)
