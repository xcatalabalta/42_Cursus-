FROM alpine:3.21

# Install dependencies
RUN apk add --no-cache \
    wget \
    curl \
    tar \
    ca-certificates \
    && rm -rf /var/cache/apk/*

# Download and install Portainer CE 2.20.3
RUN mkdir -p /opt/portainer && \
    wget -qO- https://github.com/portainer/portainer/releases/download/2.20.3/portainer-2.20.3-linux-amd64.tar.gz | \
    tar xz -C /opt/portainer --strip-components=1

# Create data directory
RUN mkdir -p /data

# Copy entrypoint script
COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

# Expose Portainer ports
EXPOSE 9000 9443

WORKDIR /opt/portainer

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
CMD ["/opt/portainer/portainer"]

