#!/bin/sh

echo "doublon colonne"
# cas erreur : doublon sur colonne 1
./sudoku "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "97......." | cat -e
echo 

echo "doublon ligne"
# cas erreur : doublon sur ligne 1
./sudoku "9...9...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......." | cat -e
echo

echo "doublon bloc"
# cas erreur : doublon sur bloc 1
./sudoku "9...7...." "29..9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......." | cat -e
