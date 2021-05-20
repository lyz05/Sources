# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter


class MoviePipeline:
    def process_item(self, item, spider):
        print(item)
        with open("my_meiju.txt","a") as f:
            lst = list(item.values())
            f.write(" ".join(lst)+"\n")
        return item
