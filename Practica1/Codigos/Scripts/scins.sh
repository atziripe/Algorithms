#!/bin/bash
cd ..
gcc insercion.c tiempo.c -o inser
./inser 50 < numeros10millones.txt > inser.txt
./inser 100 < numeros10millones.txt >> inser.txt
./inser 500 < numeros10millones.txt >> inser.txt
./inser 1000 < numeros10millones.txt >> inser.txt
./inser 2500 < numeros10millones.txt >> inser.txt
./inser 5000 < numeros10millones.txt >> inser.txt
./inser 7500 < numeros10millones.txt >> inser.txt
./inser 10000 < numeros10millones.txt >> inser.txt
./inser 20000 < numeros10millones.txt >> inser.txt
./inser 30000 < numeros10millones.txt >> inser.txt
./inser 60000 < numeros10millones.txt >> inser.txt
./inser 80000 < numeros10millones.txt >> inser.txt
./inser 100000 < numeros10millones.txt >> inser.txt
./inser 125000 < numeros10millones.txt >> inser.txt
./inser 150000 < numeros10millones.txt >> inser.txt
./inser 200000 < numeros10millones.txt >> inser.txt
./inser 250000 < numeros10millones.txt >> inser.txt
./inser 300000 < numeros10millones.txt >> inser.txt
./inser 350000 < numeros10millones.txt >> inser.txt
./inser 400000 < numeros10millones.txt >> inser.txt



