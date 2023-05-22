FROM 	debian:buster

RUN 	apt-get update -y
RUN 	apt-get upgrade -y
RUN 	apt-get install -y wget
RUN 	apt-get install -y php7.3 php-fpm php-mysql
RUN 	apt-get install -y mariadb-client

# download command line interface for WP to setup everything immediately
RUN 	wget https://wordpress.org/wordpress-6.1.1.tar.gz -P /var/www/html
RUN 	cd /var/www/html && tar -xzf wordpress-6.1.1.tar.gz && rm wordpress-6.1.1.tar.gz
RUN		chown -R root:root /var/www/html/wordpress

RUN 	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
		&& chmod +x wp-cli.phar \
		&& mv wp-cli.phar /usr/local/bin/wp

# make sure that nginx has rights on the web root directory
RUN 	chmod -R 755 /var/www/*
RUN 	chown -R www-data:www-data /var/www/*

EXPOSE 	9000

COPY 	./tools/wpscript.sh ./
RUN 	chmod +x ./wpscript.sh

COPY 	./conf/www.conf /etc/php/7.3/fpm/pool.d/

ENTRYPOINT ["bash", "./wpscript.sh"]
