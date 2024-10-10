#!/bin/bash


if [ -f "jogo.c" ]; then 
    gcc "jogo.c" "board.c" -o  "jogo"
    ./"jogo"

fi
