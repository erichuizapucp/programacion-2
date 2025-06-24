/**
 *
 * @author erichuiza
 */
public class Persona {
    private int dni;
    private String nombre;
    private int edad;
    private String apellido;
    
    public Persona() {
    }
    
    public Persona(int dni, String nombre, int edad) {
        this.dni = dni;
        this.nombre = nombre;
        this.edad = edad;
    }
    
    public int getDni() {
        return this.dni;   
    }
    
    public void setId(int dni) {
        this.dni = dni;
    }
    
    public String getNombre() {
        return this.nombre;
    }
    
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    
    public int getEdad() {
        return this.edad;
    }
    
    public void setEdad(int edad) {
        this.edad = edad;
    }
    
    public void imprimir() {
        System.out.println("DNI: " + dni);
        System.out.println("Nombre: " + nombre);
        System.out.println("Edad: " + edad);
    }

    @Override
    public String toString() {
        String str = "DNI: " + dni + "\n";
        str += "Nombre: " + nombre + "\n";
        str += "Edad: " + edad + "\n";
        return str;
    }
    
    
}
