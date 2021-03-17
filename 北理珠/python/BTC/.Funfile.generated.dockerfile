FROM registry.cn-beijing.aliyuncs.com/aliyunfc/runtime-python3.6:build-1.9.13 as python3
RUN fun-install pip install pandas