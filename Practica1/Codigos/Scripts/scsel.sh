#!/bin/bash
cd ..
gcc seleccion.c tiempo.c -o selec
./selec 50 < numeros10millones.txt > selec.txt
./selec 100 < numeros10millones.txt >> selec.txt
./selec 500 < numeros10millones.txt >> selec.txt
./selec 1000 < numeros10millones.txt >> selec.txt
./selec 2500 < numeros10millones.txt >> selec.txt
./selec 5000 < numeros10millones.txt >> selec.txt
./selec 7500 < numeros10millones.txt >> selec.txt
./selec 10000 < numeros10millones.txt >> selec.txt
./selec 20000 < numeros10millones.txt >> selec.txt
./selec 30000 < numeros10millones.txt >> selec.txt
./selec 60000 < numeros10millones.txt >> selec.txt
./selec 80000 < numeros10millones.txt >> selec.txt
./selec 100000 < numeros10millones.txt >> selec.txt
./selec 125000 < numeros10millones.txt >> selec.txt
./selec 150000 < numeros10millones.txt >> selec.txt
./selec 200000 < numeros10millones.txt >> selec.txt
./selec 250000 < numeros10millones.txt >> selec.txt
./selec 300000 < numeros10millones.txt >> selec.txt
./selec 350000 < numeros10millones.txt >> selec.txt
./selec 400000 < numeros10millones.txt >> selec.txt

