#!/bin/sh
cat /etc/passwd | sed -r 's/(.*)(:.*){6}/\1/' | sed -n '2~2p' | rev | sort -d -r | sed -n "$FT_LINE1,$FT_LINE2"p | tr "\n" "," | sed 's\,\, \g' | sed -r 's/, $/./' 
