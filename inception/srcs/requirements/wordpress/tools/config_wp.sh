#!/bin/bash

if [ -f "/var/www/html/wp-config.php" ]
then
	echo "Wordpress already configured"
else
	echo "Configuring wordpress"
	./wp-cli.phar config create --allow-root --dbname=$SQL_DATABASE --dbuser=$SQL_USER --dbpass=$SQL_PASSWORD --dbhost=mariadb:3306 --path='/var/www/html'
	chmod 777 /var/www/html/wp-config.php
	chown -R root:root /var/www/html
	./wp-cli.phar core install --allow-root --url=$DOMAIN_NAME --title="$SITE_TITLE" --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL --path='/var/www/html'
	./wp-cli.phar user create $USER1_LOGIN $USER1_MAIL --allow-root --role=author --user_pass=$USER1_PASS --path='/var/www/html'
	echo "Wordpress configured successfully"
fi

unset DOMAIN_NAME SQL_DATABASE SQL_USER SQL_PASSWORD SQL_ROOT SQL_HOST SITE_TITLE ADMIN_USER ADMIN_PASSWORD ADMIN_EMAIL USER1_LOGIN USER1_MAIL USER1_PASS

exec /usr/sbin/php-fpm7.4 --nodaemonize
