/**
 *
 * @author erichuiza
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        Restaurante r = new Restaurante();
        
        System.out.println("*** Lista de Meseros ***");
        System.out.println();
        r.cargarMeseros("meseros.csv");
        r.imprimirMeseros();
        
        System.out.println("*** Lista de Clientes ***");
        System.out.println();
        r.cargarClientes("clientes.csv");
        r.imprimirClientes();
        
        System.out.println("*** Lista de Pedidos ***");
        System.out.println();
        r.cargarPedidos("pedidos.csv");
        r.imprimirPedidos();
    }
    
}
