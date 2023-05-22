FROM	debian:buster

# install nginx and other useful stuff
RUN	    apt-get update -y
RUN	    apt-get install nginx -y
RUN	    apt-get install vim -y
RUN	    apt-get install curl -y
RUN	    apt-get install openssl -y

# generate SSL/TLS certificates and keys used to secure 
# communication between web server and clients 
# and store in newly created directory.
# In this case, req command generates a self-signed crt (signed with provided key)
# -nodes option allows the key not to be encrypted with passphrase
# -subj gives info about the identity of the certificate's owner (Common Name, country...)
RUN	    mkdir -p /etc/nginx/ssl
RUN	    openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=tgrasset.42.fr/UID=tgrasset"

# copy configuration file from host machine to container
RUN	    mkdir -p var/run/nginx
COPY	./conf/nginx.conf /etc/nginx/nginx.conf

# make sure that nginx will have permission to read and serve 
# the content of this directory, such as the WordPress files
RUN	    chmod 755 /var/www/html
RUN	    chown -R www-data:www-data /var/www/html

# daemon off tells nginx to run in the foreground and not as a background daemon
# mandatory when nginx runs in a container, otherwise the container would exit when NGINX process is finished
CMD	    ["nginx", "-g", "daemon off;"]
