FROM alpine:3.21

RUN apk add --no-cache \
    nginx \
	openssl \
	wget \
	curl
RUN mkdir -p /run/nginx /etc/nginx/certs /usr/share/nginx/html

COPY conf/my_nginx.conf /etc/nginx/nginx.conf

COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 443

ENTRYPOINT ["/entrypoint.sh"]
CMD ["nginx", "-g", "daemon off;"]
