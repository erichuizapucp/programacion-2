
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
public abstract class Pedido extends Registro {
    private String codigo;
    private int clienteDni;
    private String plato;
    
    public Pedido() {
    }
    
    public Pedido(String codigo, int clienteDni, String plato) {
        this.codigo = codigo;
        this.clienteDni = clienteDni;
        this.plato = plato;
    }
    
    public abstract int getTipo();
    
    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public int getClienteDni() {
        return clienteDni;
    }

    public void setClienteDni(int clienteDni) {
        this.clienteDni = clienteDni;
    }

    public String getPlato() {
        return plato;
    }

    public void setPlato(String plato) {
        this.plato = plato;
    }
    
    @Override
    protected void cargarDatos(Scanner scanner) {
        this.codigo = scanner.next();
        this.clienteDni = scanner.nextInt();
        this.plato = scanner.next();
    }

    @Override
    protected void imprimir() {
        System.out.println("Codigo: " + this.codigo);
        System.out.println("Cliente DNI: " + this.clienteDni);
        System.out.println("Plato: " + this.plato);
    }
}
