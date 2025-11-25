
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
public class Mesero extends Persona {
    private double sueldo;
    private int experiencia;
    
    public Mesero() {
    }
    
    public Mesero(int dni, String nombre, double sueldo, 
            int experiencia) {
        
        super(dni, nombre);
        
        this.sueldo = sueldo;
        this.experiencia = experiencia;
    }
    
    @Override
    protected void cargarDatos(Scanner scanner) {
        super.cargarDatos(scanner);
        sueldo = scanner.nextDouble();
        experiencia = scanner.nextInt();
    }

    @Override
    protected void imprimir() {
        super.imprimir();
        System.out.println("Sueldo: " + this.sueldo);
        System.out.println("Exp: " + this.experiencia);
    }
}
