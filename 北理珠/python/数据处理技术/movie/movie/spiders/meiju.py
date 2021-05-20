import scrapy
from movie.items import MovieItem


class MeijuSpider(scrapy.Spider):
    name = 'meiju'
    allowed_domains = ['meijutt.tv']
    start_urls = ['https://www.meijutt.tv/new100.html']

    def parse(self, response):
        movies = response.xpath('//ul[@class="top-list  fn-clear"]/li')
        for each_movie in movies:
            item = MovieItem()
            item['id'] = each_movie.xpath('./div/i/text()').extract()[0]
            item['name'] = each_movie.xpath('./h5/a/@title').extract()[0]
            item['status'] = each_movie.xpath('./span/font/text()').extract()[0]
            item['subtitle'] = each_movie.xpath('./span/em/text()').extract()[0]
            item['category'] = each_movie.xpath('./span[@class="mjjq"]/text()').extract()[0]
            item['station'] = each_movie.xpath('./span[@class="mjtv"]/text()').extract()[0]
            item['date'] = each_movie.xpath('./div/text()').extract()[0]
            yield item