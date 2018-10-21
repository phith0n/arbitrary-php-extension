NAME = tuwen/zephir
SHELL = /bin/bash

build-dockers: build-docker-7.2 build-docker-7.1 build-docker-7.0 build-docker-5.6 build-docker-5.5 build-docker-5.4

build-docker-7.2:
	set -ex; \
	cd linux/7.2; \
	docker build -t $(NAME):7.2 .

build-docker-7.1:
	set -ex; \
	cd linux/7.1; \
	docker build -t $(NAME):7.1 .

build-docker-7.0:
	set -ex; \
	cd linux/7.0; \
	docker build -t $(NAME):7.0 .

build-docker-5.6:
	set -ex; \
	cd linux/5.6; \
	docker build -t $(NAME):5.6 .

build-docker-5.5:
	set -ex; \
	cd linux/5.5; \
	docker build -t $(NAME):5.5 .

build-docker-5.4:
	set -ex; \
	cd linux/5.4; \
	docker build -t $(NAME):5.4 .

docker-push:
	docker push $(NAME):7.2
	docker push $(NAME):7.1
	docker push $(NAME):7.0
	docker push $(NAME):5.6
	docker push $(NAME):5.5
	docker push $(NAME):5.4
