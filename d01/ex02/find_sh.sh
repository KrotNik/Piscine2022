#! /bin/sh
find . -name '*.sh' | echo * | sed "s/\.sh//"
