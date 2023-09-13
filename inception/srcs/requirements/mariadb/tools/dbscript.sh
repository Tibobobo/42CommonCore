#!/bin/bash
#set -eux

service mysql start;

#creation de la database en recuperant son nom dans la variable d'environnement correspondante
mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"

#creation du user
mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"

#donner les droits au user sur cette database
mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"

#modification du user root
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"

#rafraichissement pour mettre a jour ces changements
mysql -e "FLUSH PRIVILEGES;"

#on redemarre mysql pour que les changements soient pris en compte
mysqladmin -u root -p${SQL_ROOT_PASSWORD} shutdown
exec mysqld_safe
