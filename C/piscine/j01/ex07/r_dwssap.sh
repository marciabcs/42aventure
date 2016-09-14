#!/bin/sh
cat /etc/passwd | sed '/#.*$/d' |sed '1d;n;d' |sed 's/:.*$//' |rev |sort -r |awk -v s="$FT_LINE1" -v e="$FT_LINE2" 'NR>=s && NR<=e'| tr '\n' ',' |sed 's/,/, /g' |sed 's/, $/./'| tr -d '\n'
