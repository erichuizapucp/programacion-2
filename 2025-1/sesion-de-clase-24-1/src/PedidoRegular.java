
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
public class PedidoRegular extends Pedido {
    @Override
    public int getTipo() {
        return 0;
    }
    
    @Override
    protected void cargarDatos(Scanner scanner) {
        super.cargarDatos(scanner);
    }

    @Override
    protected void imprimir() {
        super.imprimir();
        System.out.println("Prioritario: No");
    }
}
