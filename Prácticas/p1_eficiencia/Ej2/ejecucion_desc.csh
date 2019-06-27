#!/bin/csh
@ inicio = 1000
@ fin = 200000000
@ incremento = 500000
set ejecutable = ejercicio_desc
set salida = tiempo_desc_ord.dat
@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
