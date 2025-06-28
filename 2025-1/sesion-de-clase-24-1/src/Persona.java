
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
public abstract class Persona extends Registro {
    private int dni;
    private String nombre;
    
    public Persona() {
    }
    
    public Persona(int dni, String nombre) {
        this.dni = dni;
        this.nombre = nombre;
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
    
    @Override
    protected void cargarDatos(Scanner scanner) {
        this.dni = scanner.nextInt();
        this.nombre = scanner.next();
    }

    @Override
    protected void imprimir() {
        System.out.println("DNI: " + this.dni);
        System.out.println("Nombre: " + this.nombre);
    }    
}
