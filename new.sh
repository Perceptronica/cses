#!/bin/bash

if [ -z "$1" ]; then
    echo "usage: ./new.sh <argument>"
    exit 1
fi

DIR_NAME="$1"
mkdir "$DIR_NAME"

cd "$DIR_NAME" || exit

cat <<EOL > main.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

}
EOL
