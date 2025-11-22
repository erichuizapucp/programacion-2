/**
 *
 * @author erichuiza
 */
public abstract class Persona {
    private int dni;
    private String nombre;
    private int edad;

    public Persona(int dni, String nombre, int edad) {
        this.dni = dni;
        this.nombre = nombre;
        this.edad = edad;
    }
    
    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    @Override
    public String toString() {
        return String.format("DNI: %d, Nombre: %s, edad: %d, ", dni, nombre, edad);
    }
}
