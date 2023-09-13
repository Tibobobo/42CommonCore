FROM debian:bullseye

# installation de nginx et d'autres utilitaires necessaires, notamment openssl qui permet de generer cle et certificat tsl
RUN apt-get update -y 
RUN apt-get install -y nginx
RUN apt-get install -y vim
RUN apt-get install -y curl
RUN mkdir -p /etc/nginx/ssl
RUN apt-get install -y openssl

# generation du certif + cle tsl et stockage dans les dossiers specifies
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=tgrasset.42.fr/UID=tgrasset"

# copie du fichier de conf nginx depuis la machine hote vers le container
RUN mkdir -p /var/run/nginx
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

CMD ["nginx", "-g", "daemon off;"]
