#!/bin/bash

gcc burbuja.c tiempo.c -o bubble
./bubble 50 < numeros10millones.txt > bubble.txt
./bubble 100 < numeros10millones.txt >> bubble.txt
./bubble 500 < numeros10millones.txt >> bubble.txt
./bubble 1000 < numeros10millones.txt >> bubble.txt
./bubble 2500 < numeros10millones.txt >> bubble.txt
./bubble 5000 < numeros10millones.txt >> bubble.txt
./bubble 7500 < numeros10millones.txt >> bubble.txt
./bubble 10000 < numeros10millones.txt >> bubble.txt
./bubble 20000 < numeros10millones.txt >> bubble.txt
./bubble 30000 < numeros10millones.txt >> bubble.txt
./bubble 60000 < numeros10millones.txt >> bubble.txt
./bubble 80000 < numeros10millones.txt >> bubble.txt
./bubble 100000 < numeros10millones.txt >> bubble.txt
./bubble 125000 < numeros10millones.txt >> bubble.txt
./bubble 150000 < numeros10millones.txt >> bubble.txt
./bubble 200000 < numeros10millones.txt >> bubble.txt
./bubble 250000 < numeros10millones.txt >> bubble.txt
./bubble 300000 < numeros10millones.txt >> bubble.txt
./bubble 350000 < numeros10millones.txt >> bubble.txt
./bubble 400000 < numeros10millones.txt >> bubble.txt





