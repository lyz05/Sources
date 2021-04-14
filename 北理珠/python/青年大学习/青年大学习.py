from PIL import Image, ImageDraw, ImageFont
import requests
import matplotlib.pyplot as plt

def image_add_text(img, text, left, top, text_color=(255, 0, 0), text_size=13):
    # 创建一个可以在给定图像上绘图的对象
    draw = ImageDraw.Draw(img)
    # 字体的格式 这里的SimHei.ttf需要有这个字体
    fontStyle = ImageFont.truetype("MILT_RG.ttf", text_size, encoding="utf-8")
    # 绘制文本
    draw.text((left, top), text, text_color, font=fontStyle)
    return img

def image_combine(img,img2):
    size = list(img.size)
    size[1] = size[1]-185
    img2 = img2.resize(size)
    size = [0, 185]+list(img.size)
    img.paste(img2, size)
    return img

def down_file(url,dst):
    with open(dst, "wb") as code:
            code.write(requests.get(url).content)

down_file('https://h5.cyol.com/special/daxuexi/a4nr0x6flx/images/end.jpg','end.jpg')
img = image_combine(Image.open(r'base.jpg'),Image.open(r'end.jpg'))
# img = image_add_text(img,"\"青年大学习\"第十一季第四期",250,95,text_color=(0, 0, 0), text_size=45)
img.show()
img.save("combine.jpg")


