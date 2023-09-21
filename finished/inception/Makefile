SOURCES = 	srcs/requirements/mariadb/conf/50-server.cnf \
			srcs/requirements/mariadb/tools/mariadb.sh \
			srcs/requirements/mariadb/Dockerfile \
			srcs/requirements/nginx/conf/nginx.conf \
			srcs/requirements/nginx/Dockerfile \
			srcs/requirements/wordpress/conf/www.conf \
			srcs/requirements/wordpress/tools/config_wp.sh \
			srcs/requirements/wordpress/Dockerfile \
			/home/tgrasset/.env \
			srcs/docker-compose.yml


all: 	$(SOURCES) env_file create_data_dir
		docker compose -f srcs/docker-compose.yml up -d --pull never

create_data_dir:
		@if [ ! -d "/home/tgrasset/data" ]; \
		then \
			mkdir -p /home/tgrasset/data/mariadb; \
			mkdir -p /home/tgrasset/data/wordpress; \
		else \
			echo "Data directories already exist";\
		fi; \
		

env_file: /home/tgrasset/.env
		@if [ ! -e "srcs/.env" ]; \
		then \
			cp /home/tgrasset/.env srcs/.env; \
			echo "Env file added to srcs directory"; \
		fi; \

down:	$(SOURCES) env_file
		docker compose -f srcs/docker-compose.yml down

clean:	down
		docker system prune -af

fclean:	clean
		sudo rm -rf /home/tgrasset/data

re:		fclean all

.PHONY: all re down clean
