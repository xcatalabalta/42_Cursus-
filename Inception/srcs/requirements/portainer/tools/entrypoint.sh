#!/bin/sh
set -e

echo "Starting Portainer entrypoint..."

# Read admin password from secret
if [ -f "/run/secrets/db_root_password" ]; then
    export PORTAINER_ADMIN_PASSWORD=$(cat /run/secrets/db_root_password)
    echo "✓ Admin password loaded from secret"
else
    echo "ERROR: db_root_password secret not found!"
    exit 1
fi

# Check if Portainer is already initialized
if [ ! -f /data/portainer.db ]; then
    echo "First time setup - initializing Portainer..."
    echo "Admin password will be set automatically"
    # debugger
    # echo "Password: ${PORTAINER_ADMIN_PASSWORD}"
    
    # Use --admin-password-file instead (more reliable)
    echo -n "${PORTAINER_ADMIN_PASSWORD}" > /tmp/admin_password
    ADMIN_PASSWORD_FLAG="--admin-password-file=/tmp/admin_password"
else
    echo "Portainer already initialized. Starting..."
    ADMIN_PASSWORD_FLAG=""
fi

# Set correct permissions
chown -R root:root /data 2>/dev/null || true

echo "Starting Portainer CE 2.20.3..."

# Start Portainer with appropriate flags
exec "$@" \
    --data /data \
    --bind :9000 \
    --bind-https :9443 \
    ${ADMIN_PASSWORD_FLAG}
