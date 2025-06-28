
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
public class Cliente extends Persona {
    private String telefono;
    private String correo;
    
    public Cliente() {
    }
    
    public Cliente(int dni, String nombre, String telefono, 
            String correo) {
        super(dni, nombre);
        this.telefono = telefono;
        this.correo = correo;
    }
    
    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }
    
    @Override
    protected void cargarDatos(Scanner scanner) {
        super.cargarDatos(scanner);
        this.telefono = scanner.next();
        this.correo = scanner.next();
    }

    @Override
    protected void imprimir() {
        super.imprimir();
        System.out.println("Telefono: " + this.telefono);
        System.out.println("Correo: " + this.correo);
    }
}
