#!/bin/bash

# 8ball-unix
# basic c program that emulates a magic 8 ball
# by dyingwillow @ github

# the binary looks for answers in /usr/local/bin/8ball.txt
# if you want custom answers you can modify this file

echo "root access is required for this install process. use sudo or login as root."
echo "installing in 5 seconds. ctrl+c to quit now!"
sleep 5

echo "installing!"
sleep 1
sudo cp 8ball /usr/local/bin/8ball
sudo cp 8ball-noinput /usr/local/bin/8ball-noinput
sudo cp 8ball.txt /usr/local/bin/8ball.txt

if [ -e /usr/local/bin/8ball.txt ]; then
    echo "install complete!"
else
    echo "install failed? maybe try again..."
fi
echo ""
echo "run '8ball' for your question to be answered,"
echo "or run '8ball-noinput' for just an answer!"
