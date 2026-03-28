# Ejercicio: Clínica y Sobrecarga de Operadores

## Descripción del Ejercicio
El objetivo de este ejercicio es implementar un sistema básico para gestionar una clínica, utilizando estructuras en C++ y sobrecarga de operadores. El sistema debe permitir manejar pacientes, doctores y citas, y realizar operaciones comunes como agregar, buscar, ordenar y cancelar citas.

## Estructuras Principales
1. **Paciente**: Representa a un paciente con atributos como nombre, DNI, edad y género.
2. **Doctor**: Representa a un doctor con atributos como nombre, especialidad y horario.
3. **Cita**: Representa una cita médica, que incluye un paciente, un doctor, una fecha, una hora y un estado (reservada, cancelada, etc.).
4. **Clínica**: Contiene listas de pacientes, doctores y citas, junto con contadores para cada uno.

## Sobrecargas de Operadores
Se deben implementar las siguientes sobrecargas de operadores para facilitar las operaciones en el sistema:

### Operadores para `Cita`
1. **`operator<`**:
    - Compara dos citas por fecha y hora.
    - Útiles para ordenar citas cronológicamente.

2. **`operator!`**:
    - Cancela una cita, cambiando su estado a "CANCELADA".

3. **`operator<<`**:
    - Permite imprimir la información de una cita en un formato legible, incluyendo la fecha (YYYY-MM-DD) y la hora (HH:MM).

4. **`operator++` (prefijo y sufijo)**:
    - Incrementa la fecha de la cita al día siguiente.
    - En el caso de sufijo, devuelve la cita antes del incremento.

5. **`operator--` (prefijo y sufijo)**:
   - Decrementa la fecha de la cita al día anterior.
   - En el caso de sufijo, devuelve la cita antes del incremento.

6. **`operator==` y `operator!=`**:
    - Compara dos citas para verificar si son iguales (por fecha, hora, paciente y doctor).

### Operadores para `Clínica`
1. **`operator+=`**:
    - Permite agregar un paciente, doctor o cita a la clínica.

2. **`operator^`**:
    - Busca una cita en la clínica por el DNI del paciente.

3**`operator<<`**:
    - Permite imprimir la información completa de la clínica, incluyendo pacientes, doctores y citas.

## Caso de Uso: Clínica
El sistema debe funcionar de la siguiente manera:
1. **Carga Inicial**:
    - Se inicializan listas de pacientes, doctores y citas.
    - Las citas se cargan en orden desordenado.

2. **Operaciones Disponibles**:
    - **Agregar**:
        - Se pueden agregar nuevos pacientes, doctores y citas utilizando el operador `+=`.
    - **Buscar**:
        - Se puede buscar una cita por el DNI del paciente utilizando el operador `^`.
    - **Ordenar**:
        - Las citas se pueden ordenar al registrarse (insertar ordenado) `~`.
    - **Cancelar**:
        - Una cita se puede cancelar utilizando el operador `!`.
    - **Imprimir**:
        - Se puede imprimir la información de la clínica, pacientes, doctores y citas utilizando el operador `<<`.

3. **Ejemplo de Flujo**:
    - Se agrega un nuevo paciente y un nuevo doctor.
    - Se crea una nueva cita y se agrega a la clínica.
    - Se busca una cita por el DNI del paciente.
    - Se cancela una cita.
    - Se muestran las citas ordenadas por fecha y hora.
    - Se busca una cita por DNI del paciente.
    - Se reprogrma para el día siguiente.
    - Se imprime la cita después de reprogrmarla.
