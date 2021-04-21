from django.db import models

# Create your models here.
from django.utils import timezone


class Ad(models.Model):
    title = models.CharField(max_length=50, verbose_name='招聘岗位')
    description = models.TextField(verbose_name='岗位要求')
    publishDate = models.DateTimeField(max_length=20, default=timezone.now, verbose_name='发布时间')

    def __str__(self):
        return self.title

    class Meta:
        ordering = ['-publishDate']
        verbose_name = '招聘广告'
        verbose_name_plural = verbose_name
