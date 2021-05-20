import cv2, requests

url = 'http://localhost:8000/serviceApp/facedetect/'

tracker = None
imgPath = "face.jpg"
files = {
    "image": ("filename2", open(imgPath, "rb"), "image/jpeg"),
}

req = requests.post(url, data=tracker, files=files).json()
print("获取信息：{}".format(req))

img = cv2.imread(imgPath)
for (w, x, y, z) in req["faces"]:
    cv2.rectangle(img, (w, x), (y, z), (0, 255, 0), 2)

cv2.imshow("face detection", img)
cv2.waitKey(0)
