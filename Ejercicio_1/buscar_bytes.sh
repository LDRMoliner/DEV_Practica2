#!/bin/sh

i=1
MAX_LENGTH=500
execv 2> /dev/null
while [ $i -le $MAX_LENGTH ]
do
	PAYLOAD=$( printf 'A%.0s' `seq 1 $i`  )
    	$( ./buffer_overflow "$PAYLOAD")
    	OUTPUT=$?
    	if [ $OUTPUT -eq 139 ]
	then
        	echo "Buffer overflow detectado con longitud: $i"
        	exit 0
    	fi
    	i=$(( $i \+ 1 ))
done
