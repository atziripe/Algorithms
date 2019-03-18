#!/bin/bash
cd ..
gcc shell.c tiempo.c -o concha
./concha 100 < numeros10millones.txt > concha.txt
./concha 1000 < numeros10millones.txt >> concha.txt
./concha 5000 < numeros10millones.txt >> concha.txt
./concha 10000 < numeros10millones.txt >> concha.txt
./concha 50000 < numeros10millones.txt >> concha.txt
./concha 100000 < numeros10millones.txt >> concha.txt
./concha 200000 < numeros10millones.txt >> concha.txt
./concha 400000 < numeros10millones.txt >> concha.txt
./concha 600000 < numeros10millones.txt >> concha.txt
./concha 800000 < numeros10millones.txt >> concha.txt
./concha 1000000 < numeros10millones.txt >> concha.txt
./concha 2000000 < numeros10millones.txt >> concha.txt
./concha 3000000 < numeros10millones.txt >> concha.txt
./concha 4000000 < numeros10millones.txt >> concha.txt
./concha 5000000 < numeros10millones.txt >> concha.txt
./concha 6000000 < numeros10millones.txt >> concha.txt
./concha 7000000 < numeros10millones.txt >> concha.txt
./concha 8000000 < numeros10millones.txt >> concha.txt
./concha 9000000 < numeros10millones.txt >> concha.txt
./concha 10000000 < numeros10millones.txt >> concha.txt



