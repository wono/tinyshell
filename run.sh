#!/bin/bash

DEST="lab6"

SRC1="execute_by_child.c"
SRC2="fileio.c"
SRC3="str_handler.c"
SRC4="tokenize.c"
SRC5="util.c"
MAIN="main.c"

DEFN=""

SHL='\e[1;37m'
EHL='\e[0m'

clear
echo -e $SHL
echo ##########################################################################
echo ##########################################################################
echo "                           BCIT CST C/S LAB 6 : TINY SHELL"
echo ##########################################################################
echo "                            AUTHOR: Wonho Lim (a@wono.me)"
echo ##########################################################################
echo -e $EHL
gcc -W -Wall -std=c11 $SRC1 $SRC2 $SRC3 $SRC4 $SRC5 $MAIN -o $DEST $DEFN &&\
./$DEST
