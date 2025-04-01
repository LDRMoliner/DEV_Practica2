# Instrucciones para ejecutar los ejercicios

## Primer ejercicio

Para ejecutar el primer ejercicio, debes utilizar el siguiente comando:

```bash
sh exploit.sh [buffer_size] [offset]
```

Donde:
- **bytes** es el número de bytes del buffer que se usa en el programa a vulnerar.
- **offset** es el valor del desplazamiento necesario para el ataque.

## Segundo ejercicio

Para ejecutar el segundo ejercicio, utiliza el siguiente comando:

```bash
sh exploit_root.sh programa [buffer_size] [offset]
```

Donde:
- **buffer_size** es el número de bytes del buffer que se usa en el programa a vulnerar.
- **offset** es el número a restar a la dirección obtenida.
