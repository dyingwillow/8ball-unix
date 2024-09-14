# 8ball-unix

## a magic 8 ball written in C

source code is currently aimed towards *nix systems (specifically linux), but it probably compiles for windows with mingw.

the binary pulls answers from /usr/local/bin/8ball.txt (this can be modified for windows targets)

you can add custom answers by adding them to that file.

### installation

there is an install script for linux and potentially other unixes, haven't tested!

run 'install.sh' for proper usage.

### usage

the 8ball binary lets you ask questions, while 8ball-input just gives you an answer.

the thinking period of the 8 ball is just a 3 second sleep state in the code.

### building

```
git clone https://github.com/dyingwillow/8ball-unix

cd 8ball-unix/src

sudo cp ../8ball.txt /usr/local/bin/8ball.txt

gcc main.c -o 8ball # // gcc noinput.c -o 8ball-noinput for no input version

./8ball # // or 8ball-noinput
```

please report your issues! i want this to end up an actually okay program.
