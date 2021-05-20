import base64

import cv2
from django.http import StreamingHttpResponse
from django.shortcuts import HttpResponse, render, get_object_or_404
from django.http import JsonResponse
import os

from django.views.decorators.csrf import csrf_exempt
import numpy as np

from serviceApp.models import Doc
from pyquery import PyQuery as pq
import productsApp.views


def service(request, serviceName):
    submenu = serviceName
    serviceName = serviceName.replace('download', '资料下载')
    serviceName = serviceName.replace('platform', '人脸识别开放平台')

    docList = Doc.objects.all().order_by('-publishDate')
    (pageData, docList) = productsApp.views.pageinator(docList, int(request.GET.get('page', 1)), size=5)
    if submenu=="platform":
        return render(request,'platForm.html',{
            'active_menu': 'service',
            'sub_menu': submenu,
            'docName': serviceName,
        })
    else:
        return render(request, 'docList.html', {
            'active_menu': 'service',
            'sub_menu': submenu,
            'docName': serviceName,
            'docList': docList,
            'pageData': pageData,
        })

def platform(request):
    html = '<html><body>人脸识别开放平台</body></html>'
    return HttpResponse(html)

def read_file(file_name, size):
    with open(file_name, mode='rb') as fp:
        while True:
            c = fp.read(size)
            if c:
                yield c
            else:
                break


def getDoc(request, id):
    doc = get_object_or_404(Doc, id=id)
    update_to, filename = str(doc.file).split('/')
    filepath = '%s/media/%s/%s' % (os.getcwd(), update_to, filename)
    response = StreamingHttpResponse(read_file(filepath, 512))
    response['Content-Type'] = 'application/octet-stream'
    response['Content-Disposition'] = 'attachment;filename="{}"'.format(filename)
    return response





face_detector_path = "serviceApp/haarcascade_frontalface_default.xml"
face_dector = cv2.CascadeClassifier(face_detector_path)  # 生成人脸检测器


def read_image(stream=None):
    if stream is not None:
        data_temp = stream.read()
        img = np.asarray(bytearray(data_temp), dtype="uint8")
        img = cv2.imdecode(img,cv2.IMREAD_COLOR)
        return img



@csrf_exempt
def facedetect(request):
    result = {}

    if request.method == "POST":
        stream = request.FILES.get("image", None)
        if stream is not None:
            print(stream)
            img = read_image(stream=stream)
        else:
            result.update({
                "#faceNum": -1,
            })
            return JsonResponse(result)
        if img.shape[2] == 3:
            img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        values = face_dector.detectMultiScale(img,
                                              scaleFactor=1.1,
                                              minNeighbors=5,
                                              #minSize=(30,30),
                                              flags=cv2.CASCADE_SCALE_IMAGE)

        values = [(int(a), int(b), int(a + c), int(b + d)) for (a, b, c, d) in values]
        result.update({
            "#faceNum": len(values),
            "faces": values,
        })

    return JsonResponse(result)

@csrf_exempt
def facedetectDemo(request):
    result = {}

    if request.method == "POST":
        if request.FILES.get('image') is not None:
            img = read_image(stream=request.FILES["image"])
        else:
            result['#faceNum'] = -1
            return JsonResponse(result)

        if img.shape[2] == 3:
            imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
        else:
            imgGray = img

        values = face_dector.detectMultiScale(imgGray,scaleFactor=1.1,minNeighbors=5,minSize=(30,30),flags=cv2.CASCADE_SCALE_IMAGE)
        values = [(int(a), int(b), int(a + c), int(b + d)) for (a, b, c, d) in values]
        for (w, x, y, z) in values:
            cv2.rectangle(img, (w, x), (y, z), (0, 255, 0), 2)

        retval, buffer_img = cv2.imencode('.jpg',img)
        img64 = base64.b64encode(buffer_img)
        img64 = str(img64,encoding='utf-8')
        result['img64'] = img64

    return JsonResponse(result)