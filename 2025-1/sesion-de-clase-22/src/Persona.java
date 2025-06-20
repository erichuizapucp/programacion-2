/**
 *
 * @author erichuiza
 */
public class Persona {
    private int dni;
    private String nombre;
    private int edad;
    
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
}
