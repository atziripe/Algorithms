#!/bin/bash
cd ..
gcc burbujaopt.c tiempo.c -o bubbleplus
./bubbleplus 50 < numeros10millones.txt > bubbleplus.txt
./bubbleplus 100 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 500 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 1000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 2500 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 5000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 7500 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 10000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 20000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 30000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 60000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 80000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 100000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 125000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 150000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 200000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 250000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 300000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 350000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 400000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 1000000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 5000000 < numeros10millones.txt >> bubbleplus.txt
./bubbleplus 8000000 < numeros10millones.txt >> bubbleplus.txt


