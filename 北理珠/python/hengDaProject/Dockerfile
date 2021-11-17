FROM python:3
ENV PYTHONUNBUFFERED=1
WORKDIR /code
RUN apt update && apt install libgl1-mesa-glx -y
COPY pip.conf /root/.pip/pip.conf
COPY requirements.txt /code/
RUN pip install -r requirements.txt
RUN git clone https://gitee.com/iliangwei/DjangoUeditor3.git /root/DjangoUeditor3
RUN python /root/DjangoUeditor3/setup.py install
COPY . /code/