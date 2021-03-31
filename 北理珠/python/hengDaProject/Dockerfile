FROM python:3
ENV PYTHONUNBUFFERED=1
WORKDIR /code
COPY pip.conf /root/.pip/pip.conf
COPY requirements.txt /code/
RUN pip install -r requirements.txt
COPY . /code/