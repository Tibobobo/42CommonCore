FROM	debian:bullseye

RUN		mkdir -p /var/lib/mysql

RUN		apt update -y \
		&& apt upgrade -y \
		&& apt install mariadb-server -y

COPY 	conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf

COPY 	tools/mariadb.sh	mariadb.sh
RUN		chmod +x mariadb.sh

ENTRYPOINT		["./mariadb.sh"]
