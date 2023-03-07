#!/bin/bash

echo "Connect your device so the new version can be set"

function setVersion() {
    version="$1"

    sed -i -e "s/APP_VERSION = \".*\";/APP_VERSION = \"${version}\";/g" ./src/version.h
}

BRANCH=$(git rev-parse --abbrev-ref HEAD)
VERSION=$(git rev-list HEAD --first-parent --count)
RELEASE_VERSION="${BRANCH}-${VERSION}"
echo "Set version: ${RELEASE_VERSION}"
setVersion "${RELEASE_VERSION}" || exit 1

git add src/version.h || exit 1
git commit -m "version release: ${RELEASE_VERSION}" || exit 1
git tag "v${RELEASE_VERSION}" || exit 1
git push -u origin --tags || exit 1

pio run --target upload
