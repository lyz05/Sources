#!/bin/bash
# JingleOJ安装脚本
# 请使用root帐号

set -x
# =========================== conf ===========================

# 0 不安装 1 安装
IS_INSTALL_PYTHON3=1
IS_INSTALL_MYSQL=1
IS_INSTALL_REDIS=1
IS_INSTALL_MAIN_SERVER=1
IS_INSTALL_JUDGE_SERVER=0

# 是否更换源 理论云服务厂商不需要
IS_ADD_SOURCE=0

# environment 如果不是线上生产环境 请填成offline
LOCAL_ENVIRONMENT='offline'
# LOCAL_ENVIRONMENT='prod' 生产环境 谨慎选择

# anaconda
ANACONDA_DOWNLOAD_URL='https://mirrors.tuna.tsinghua.edu.cn/anaconda/archive/Anaconda3-2019.07-Linux-x86_64.sh'
ANACONDA_PATH='/root/anaconda3'
ANACONDA_BIN=${ANACONDA_PATH}'/bin'
PYTHON3_ENVIRONMENT_FILE='pythonenv.yml'

# mysql
MYSQL_PASSWORD='jingleoj123'

# redis
REDIS_PASSWORD='jingleoj123'

# root document
INSTALL_DIR='/JingleOJ'
TEMP_DIR=${INSTALL_DIR}'/temp'

# git (if need login, please use scheme as https)
# git_username= # no authentication
git_username='username' # your git username
# git_password= # no authentication
git_password='password' # your git password
server_git='https://gitlab.com/miticfy-group/jingleoj2_server.git'
judge_server_git='https://gitlab.com/miticfy-group/jingleoj2_judgeserver.git'
judge_service_git='https://gitlab.com/miticfy-group/jingleoj2_judgeservice.git'

# =========================== dependencies ===========================
function gen_dockerfile(){
	local l_dockerfile_path=$1
	if [[ -z "${l_dockerfile_path}" ]];then
		return -1
	fi
	cat>${l_dockerfile_path}<<'EOF'
FROM ubuntu:16.04

MAINTAINER mortihoo

ADD /JingleOJ2_JudgeService /JingleOJ2_JudgeService

RUN rm /bin/sh && ln -s /bin/bash /bin/sh

RUN echo "" > /etc/apt/sources.list && \
	echo "deb http://mirrors.cloud.aliyuncs.com/ubuntu/ xenial main" >> /etc/apt/sources.list && \
	echo "deb-src http://mirrors.cloud.aliyuncs.com/ubuntu/ xenial main" >> /etc/apt/sources.list && \
	echo "deb http://mirrors.cloud.aliyuncs.com/ubuntu/ xenial-updates main" >> /etc/apt/sources.list && \
	echo "deb-src http://mirrors.cloud.aliyuncs.com/ubuntu/ xenial-updates main" >> /etc/apt/sources.list && \
	echo "deb http://mirrors.cloud.aliyuncs.com/ubuntu/ xenial universe" >> /etc/apt/sources.list && \
	echo "deb-src http://mirrors.cloud.aliyuncs.com/ubuntu/ xenial universe" >> /etc/apt/sources.list && \
	echo "deb http://mirrors.cloud.aliyuncs.com/ubuntu/ xenial-updates universe" >> /etc/apt/sources.list && \
	echo "deb-src http://mirrors.cloud.aliyuncs.com/ubuntu/ xenial-updates universe" >> /etc/apt/sources.list && \
	echo "deb http://mirrors.cloud.aliyuncs.com/ubuntu/ xenial multiverse" >> /etc/apt/sources.list && \
	echo "deb http://mirrors.cloud.aliyuncs.com/ubuntu xenial-security main" >> /etc/apt/sources.list && \
	echo "deb-src http://mirrors.cloud.aliyuncs.com/ubuntu xenial-security main" >> /etc/apt/sources.list && \
	echo "deb http://mirrors.cloud.aliyuncs.com/ubuntu xenial-security universe" >> /etc/apt/sources.list && \
	echo "deb-src http://mirrors.cloud.aliyuncs.com/ubuntu xenial-security universe" >> /etc/apt/sources.list && \
	echo "deb http://mirrors.cloud.aliyuncs.com/ubuntu xenial-security multiverse" >> /etc/apt/sources.list && \
	apt-get update && \
	apt-get install -y software-properties-common && \
	add-apt-repository ppa:jonathonf/python-3.6 && \
	apt-get update && \
	apt-get install -y apt-utils dialog python3.6 python3.6-dev gcc g++ default-jdk && \
	cd /usr/bin && \
	ln -s python3.6m python && \
	cd /JingleOJ2_JudgeService && \
	python setup.py install

ADD /JingleOJ2_JudgeServer/docker_inside /JingleOJ2_JudgeServer
EOF
    return 0
}

function gen_pythonenv(){
	local l_pythonenv_path=$1
	if [[ -z "${l_pythonenv_path}" ]];then
		return -1
	fi
	cat>${l_pythonenv_path}<<'EOF'
name: jingleoj
channels:
  - https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
  - defaults
dependencies:
  - anyjson=0.3.3=py36hcd494a7_1
  - ca-certificates=2017.08.26=h1d4fec5_0
  - certifi=2018.1.18=py36_0
  - django=2.0.2=py36hd476221_0
  - libedit=3.1=heed3624_0
  - libffi=3.2.1=hd88cf55_4
  - libgcc-ng=7.2.0=hdf63c60_3
  - libstdcxx-ng=7.2.0=hdf63c60_3
  - ncurses=6.0=h9df7e31_2
  - openssl=1.0.2o=h20670df_0
  - pip=10.0.1=py36_0
  - pymysql=0.8.0=py36_0
  - python=3.6.5=hc3d631a_0
  - pytz=2018.3=py36_0
  - readline=7.0=ha6073c6_4
  - setuptools=39.0.1=py36_0
  - sqlite=3.22.0=h1bed415_0
  - tk=8.6.7=hc745277_3
  - wheel=0.30.0=py36hfd4bba0_1
  - xz=5.2.3=h55aa19d_2
  - zlib=1.2.11=ha838bed_2
  - pip:
    - aioredis==1.0.0
    - amqp==2.3.2
    - asgiref==2.3.0
    - async-timeout==2.0.1
    - attrs==17.4.0
    - autobahn==18.4.1
    - automat==0.6.0
    - babel==2.6.0
    - baidu-aip==2.2.10.0
    - billiard==3.5.0.4
    - celery==4.2.1
    - celery-task-tigger==0.4
    - channels==2.1.1
    - channels-redis==2.1.1
    - chardet==3.0.4
    - configobj==5.0.6
    - constantly==15.1.0
    - cos-python-sdk-v5==1.6.4
    - crcmod==1.7
    - daphne==2.1.1
    - dicttoxml==1.7.4
    - docker==3.2.0
    - docker-pycreds==0.2.2
    - dwebsocket==0.4.2
    - flower==0.9.2
    - gevent==1.4.0
    - greenlet==0.4.15
    - hiredis==0.2.0
    - hyperlink==18.0.0
    - idna==2.6
    - incremental==17.5.0
    - kombu==4.2.1
    - msgpack==0.5.6
    - oss2==2.4.0
    - pillow==5.3.0
    - pypinyin==0.34.0
    - rarfile==3.0
    - redis==2.10.6
    - requests==2.18.4
    - six==1.11.0
    - style==1.1.0
    - tornado==5.1.1
    - twisted==18.4.0
    - txaio==2.10.0
    - update==0.0.1
    - urllib3==1.22
    - uwsgi==2.0.17
    - vine==1.1.4
    - websocket-client==0.47.0
    - xlrd==1.1.0
    - xlwt==1.3.0
    - zope.interface==4.5.0
prefix: ANACONDA_PATH/envs/jingleoj
EOF
    sed -i "s:ANACONDA_PATH:${ANACONDA_PATH}:g" ${l_pythonenv_path}
    return 0
}

# =========================== common function ===========================
function git_use_account(){
	local git_path=$1
	echo "https://"${git_username}:${git_password}@$(echo "${git_path}" | awk -F 'https://' '{print $2}')
}
# =========================== start work ===========================
cur_path=$(cd `dirname $0`; pwd)
# lock etc.
init_env_lock=${INSTALL_DIR}'/init_env.lock'
main_server_lock=${INSTALL_DIR}'/main_server.lock'
judge_server_lock=${INSTALL_DIR}'/judge_server.lock'

# create root dir etc.
if [[ ! -d ${INSTALL_DIR} ]];then
    mkdir -p ${INSTALL_DIR}
fi

if [[ ! -d ${TEMP_DIR} ]];then
    mkdir -p ${TEMP_DIR}
fi

# init
if [[ ! -f ${init_env_lock} ]];then
	echo "export DEBIAN_FRONTEND=noninteractive" >> /etc/profile
	echo "export LC_ALL=C.UTF-8" >> /etc/profile
	echo "export LANG=C.UTF-8" >> /etc/profile
	echo "export LC_CTYPE=C.UTF-8" >> /etc/profile
	source /etc/profile
	echo "" >> /etc/apt/sources.list
	echo "deb http://mirrors.cloud.aliyuncs.com/ubuntu/ xenial multiverse" >> /etc/apt/sources.list
	if [[ ${IS_ADD_SOURCE} == 1 ]];then
		echo "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main restricted universe multiverse" >> /etc/apt/sources.list
		# echo "deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main restricted universe multiverse" >> /etc/apt/sources.list
		echo "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse" >> /etc/apt/sources.list
		# echo "deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse" >> /etc/apt/sources.list
		echo "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse" >> /etc/apt/sources.list
		# echo "deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse" >> /etc/apt/sources.list
		echo "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security main restricted universe multiverse" >> /etc/apt/sources.list
		# echo "deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security main restricted universe multiverse" >> /etc/apt/sources.list
	fi
	sudo apt-get update && sudo apt-get upgrade -y
	sudo apt-get autoremove -y && sudo apt-get upgrade -y
	sudo apt-get install -y python-dev gcc-4.7 rar unrar tofrodos supervisor git
	ret_val=$?
	if [[ ${ret_val} != 0 ]];then
		echo "init env error 1"
		exit 1
	fi
	sudo rm /usr/bin/gcc && sudo ln -s /usr/bin/gcc-4.7 /usr/bin/gcc
	# set timezone
	sudo timedatectl set-timezone "Asia/Shanghai"
	ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
	rm /bin/sh && ln -s /bin/bash /bin/sh
	echo "finish init env" > ${init_env_lock}
fi

# install anaconda3 python3
if [[ ${IS_INSTALL_PYTHON3} == 1 ]];then
	anaconda_file='./anaconda.sh'

	cd ${TEMP_DIR}

	wget --quiet ${ANACONDA_DOWNLOAD_URL} -O ${anaconda_file}
	ret_val=$?
	if [[ ${ret_val} != 0 ]];then
		echo "wget anaconda error"
		exit 2
	fi

	/bin/bash ${anaconda_file} -b -p ${ANACONDA_PATH}
	ret_val=$?
	if [[ ${ret_val} != 0 ]];then
		echo "anaconda3 install error"
		exit 3
	fi

	echo "export PATH="${ANACONDA_BIN}":$PATH" >> /etc/profile
	echo "alias saj='source activate jingleoj'" >> /etc/profile
	source /etc/profile

	conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
	conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
	conda config --set show_channel_urls yes

	sudo rm /usr/lib/libpcre.so.1
	sudo ln -s ${ANACONDA_PATH}/lib/libpcre.so.1 /usr/lib/

	# create jingle oj python env
	cd ${cur_path}
	gen_pythonenv ${PYTHON3_ENVIRONMENT_FILE}

    conda env create -f ${PYTHON3_ENVIRONMENT_FILE}
    ret_val=$?
	if [[ ${ret_val} != 0 ]];then
		echo "python3 env install error"
		exit 4
	fi
fi

# install mysql
if [[ ${IS_INSTALL_MYSQL} == 1 ]];then
	mysql_conf_path='/etc/mysql/mysql.conf.d/mysqld.cnf'
	# check
	which mysql
	ret_val=$?
	if [[ ${ret_val} == 0 ]];then
		echo "mysql is already install"
	else
		sudo debconf-set-selections <<< 'mysql-server mysql-server/root_password password '${MYSQL_PASSWORD}
		sudo debconf-set-selections <<< 'mysql-server mysql-server/root_password_again password '${MYSQL_PASSWORD}
		sudo apt-get install mysql-server mysql-client -y

		# modify conf
    	sed -i "s:bind-address:#bind-address:g" ${mysql_conf_path}
    	echo "bind-address	=	0.0.0.0" >> ${mysql_conf_path}

    	# restart
    	systemctl restart mysql
		ret_val=$?
    	if [[ ${ret_val} != 0 ]];then
			echo "restart mysql error 1"
			exit 5
		fi

		mysql -uroot -p${MYSQL_PASSWORD} --default-character-set=utf8 -e "use mysql;update user set host='%' where user='root';flush privileges;"
		ret_val=$?
		if [[ ${ret_val} != 0 ]];then
			echo "modify mysql host error"
			exit 6
		fi

		# restart 2
    	systemctl restart mysql
		ret_val=$?
    	if [[ ${ret_val} != 0 ]];then
			echo "restart mysql error 2"
			exit 101
		fi

		echo 'mysql install success'
	fi
fi


# install redis server
if [[ ${IS_INSTALL_REDIS} == 1 ]];then
	redis_conf_path='/etc/redis/redis.conf'
	# check
	which redis-cli
	ret_val=$?
	if [[ ${ret_val} == 0 ]];then
		echo "redis is already install"
	else
		sudo apt-get install -y redis-server

		# modify conf
    	sed -i "s:^bind:#bind:g" ${redis_conf_path}
    	echo "bind 0.0.0.0" >> ${redis_conf_path}
    	echo "requirepass "${REDIS_PASSWORD} >> ${redis_conf_path}

    	# restart
    	systemctl restart redis-server
		ret_val=$?
    	if [[ ${ret_val} != 0 ]];then
			echo "restart redis error"
			exit 7
		fi

		echo 'redis install success'
	fi
fi


# install Jingle OJ main server
if [[ ${IS_INSTALL_MAIN_SERVER} == 1 ]] && [[ ! -f ${main_server_lock} ]];then
	main_server_dir=${INSTALL_DIR}'/JingleOJ2_Server'
	main_server_cur_conf_dir=${main_server_dir}'/config'
	main_server_prod_conf_dir=${main_server_dir}'/config_prod'
	main_server_offline_conf_dir=${main_server_dir}'/config_offline'

	cd ${INSTALL_DIR}

	# get code
	if [[ -z "${git_username}" ]] || [[ -z "${git_password}" ]];then
		git clone ${server_git} ${main_server_dir}
		ret_val=$?
		if [[ ${ret_val} != 0 ]];then
			echo "get main server code error 1"
			exit 8
		fi
	else
		git clone $(git_use_account ${server_git}) ${main_server_dir}
		ret_val=$?
		if [[ ${ret_val} != 0 ]];then
			echo "get main server code error 2"
			exit 9
		fi
	fi

	# install nginx
	which nginx
	ret_val=$?
	if [[ ${ret_val} != 0 ]];then
		sudo apt-get install -y nginx
		ret_val=$?
		if [[ ${ret_val} != 0 ]];then
			echo "nginx install error"
			exit 10
		fi
	fi

	# create link
	sudo ln -s ${main_server_dir}/my_nginx.conf /etc/nginx/sites-enabled/
	sudo ln -s ${main_server_dir}/supervisor_conf/* /etc/supervisor/conf.d

	# copy configure file
	if [[ ${LOCAL_ENVIRONMENT} == 'prod' ]];then
		cp -r ${main_server_prod_conf_dir}/* ${main_server_cur_conf_dir}/
	else
		cp -r ${main_server_offline_conf_dir}/* ${main_server_cur_conf_dir}/
	fi

	echo "finish install main server" > ${main_server_lock}
fi

# install Jingle OJ main server
if [[ ${IS_INSTALL_JUDGE_SERVER} == 1 ]] && [[ ! -f ${judge_server_lock} ]];then
	judge_service_dir=${INSTALL_DIR}'/JingleOJ2_JudgeService'
	judge_server_dir=${INSTALL_DIR}'/JingleOJ2_JudgeServer'
	dockerfile_src=${cur_path}'/dockerfile'

	cd ${INSTALL_DIR}

	# get code
	if [[ -z "${git_username}" ]] || [[ -z "${git_password}" ]];then
		git clone ${judge_service_git} ${judge_service_dir} && git clone ${judge_server_git} ${judge_server_dir}
		ret_val=$?
		if [[ ${ret_val} != 0 ]];then
			echo "get judge server code error 1"
			exit 11
		fi
	else
		git clone $(git_use_account ${judge_service_git}) ${judge_service_dir} && git clone $(git_use_account ${judge_server_git}) ${judge_server_dir}
		ret_val=$?
		if [[ ${ret_val} != 0 ]];then
			echo "get judge server code error 2"
			exit 12
		fi
	fi

	wget -qO- https://get.docker.com/ | sh
	ret_val=$?
	if [[ ${ret_val} != 0 ]];then
		echo "install docker error"
		exit 13
	fi

	cd ${INSTALL_DIR}
	gen_dockerfile './dockerfile'

	sudo docker build -t jingleoj .

	echo "finish install judge server" > ${judge_server_lock}
fi


echo "finish deploy!success!"
