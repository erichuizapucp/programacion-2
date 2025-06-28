import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
public class Restaurante {
    private final List<Mesero> meseros;
    private final List<Cliente> clientes;
    private final List<Pedido> pedidos;

    public Restaurante() {
        this.meseros = new ArrayList<>();
        this.clientes = new ArrayList<>();
        this.pedidos = new ArrayList<>();
    }
    
    public void cargarMeseros(final String nombreArchivo) throws Exception {
        File archivo = new File(nombreArchivo);
        Scanner scanner = new Scanner(archivo);
        scanner.useDelimiter(",|\\n");
        
        while (scanner.hasNext()) {
            Mesero mesero = new Mesero();
            mesero.cargarDatos(scanner);
            this.meseros.add(mesero);
        }
    }
    
    public void imprimirMeseros() {
        for (Mesero mesero : this.meseros) {
            mesero.imprimir();
            System.out.println();
        }
    }
    
    public void cargarClientes(final String nombreArchivo) throws Exception {
        File archivo = new File(nombreArchivo);
        Scanner scanner = new Scanner(archivo);
        scanner.useDelimiter(",|\\n");
        
        while (scanner.hasNext()) {
            Cliente cliente = new Cliente();
            cliente.cargarDatos(scanner);
            this.clientes.add(cliente);
        }
    }
    
    public void imprimirClientes() {
        for (Cliente cliente : this.clientes) {
            cliente.imprimir();
            System.out.println();
        }
    }
    
    public void cargarPedidos(final String nombreArchivo) throws Exception {
        File archivo = new File(nombreArchivo);
        Scanner scanner = new Scanner(archivo);
        scanner.useDelimiter(",|\\n");
        
        while (scanner.hasNext()) {
            Pedido pedido;
            int tipo = Integer.parseInt(scanner.next());
            
            switch (tipo) {
                case 0: 
                    pedido = new PedidoRegular();
                    break;
                case 1: 
                    pedido = new PedidoPrioritario();
                    break;
                default:
                    pedido = new PedidoRegular();
                    break;
            }
            
            pedido.cargarDatos(scanner);
            this.pedidos.add(pedido);
        }
    }
    
    public void imprimirPedidos() {
        for (Pedido pedido : this.pedidos) {
            pedido.imprimir();
            System.out.println();
        }
    }
}
