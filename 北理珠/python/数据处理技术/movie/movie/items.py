# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class MovieItem(scrapy.Item):
    # define the fields for your item here like:
    id = scrapy.Field()
    name = scrapy.Field()
    status = scrapy.Field()
    subtitle = scrapy.Field()
    category = scrapy.Field()
    station = scrapy.Field()
    date = scrapy.Field()

