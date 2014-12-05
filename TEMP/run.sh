#!/bin/bash

DEST="FOORUN"

SRC1=$1
SRC2=""
SRC3=""
SRC4=""
SRC5=""

MAIN=$2

gcc -W -Wall $SRC1 $SRC2 $SRC3 $SRC4 $SRC5 $MAIN -o $DEST && \
./$DEST && rm $DEST
