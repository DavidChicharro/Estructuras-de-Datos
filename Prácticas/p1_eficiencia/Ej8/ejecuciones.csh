#!/bin/csh
@ inicio = 50
@ fin = 100050
@ incremento = 1000
set ejecutable = mergesort
set salida = tiempos_sin_umbral_2.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
