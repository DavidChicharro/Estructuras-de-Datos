#!/bin/csh
@ inicio = 100
@ fin = 30100
@ incremento = 500
set ejecutable = ordenacion_pc
set salida = tiempos_ordenacion_pc.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
  @ i += $incremento
end
