#!/bin/csh
@ inicio = 1
@ fin = 1500
@ incremento = 30
set ejecutable = matrices
set salida = tiempos.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 20` >> $salida
  @ i += $incremento
end
