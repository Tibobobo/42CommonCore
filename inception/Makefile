all: 
	mkdir -p /home/tgrasset/data/mariadb
	mkdir -p /home/tgrasset/data/wordpress
	docker compose -f ./srcs/docker-compose.yml build
	docker compose -f ./srcs/docker-compose.yml up -d

clean:
	docker compose -f ./srcs/docker-compose.yml stop
	sudo rm -rf /home/tgrasset/data
	docker system prune -af

re: clean all

.PHONY: all clean 