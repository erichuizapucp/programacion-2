
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
public class PedidoPrioritario extends Pedido {
    @Override
    public int getTipo() {
        return 1;
    }
    
    @Override
    protected void cargarDatos(Scanner scanner) {
        super.cargarDatos(scanner);
    }

    @Override
    protected void imprimir() {
        super.imprimir();
        System.out.println("Prioritario: Si");
    }
}
