import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
class Menu {
    private List<Bebida> bebidas;
    
    public Menu() {
        bebidas = new ArrayList<>();
    }
    
    public void cargarBebidas(Scanner archivo) {
        while (archivo.hasNext()) {
            String codigo = archivo.next();
            if (codigo.equals("FIN")) break;
            
            Bebida bebida = new Bebida();
            bebida.setCodigo(codigo);
            bebida.setNombre(archivo.next());
            bebida.setDescripcion(archivo.next());
            bebida.setTipo(archivo.next().charAt(0));
            bebida.setPrecio(archivo.nextDouble());
            bebida.setCantVent(archivo.nextInt());
            bebida.setDisponible(true);
            
            bebidas.add(bebida);
        }
    }
    
    public Bebida buscarBebida(final String codigoBebida) {
//        Bebida bebida = 
//                bebidas.stream().filter(
//                        b -> b.getCodigo().equals(codigoBebida))
//                        .findFirst().get();
//        return bebida;
        Bebida res = null;
        for (Bebida bebida : bebidas) {
            if (bebida.getCodigo().equals(codigoBebida)) {
                res = bebida;
                break;
            }
        }
        return res;
    }
    
    public void imprimir(BufferedWriter writer) throws IOException {
        writer.write("============================= Menú del día ======================================");
        writer.newLine();
        for (Bebida bebida : bebidas) {
            writer.write(bebida.getTipo() + ": " + bebida.getNombre());
            writer.newLine();
            writer.write(bebida.getDescripcion());
            writer.newLine();
            writer.write("Precio: S/ " + String.format("%.2f", bebida.getPrecio()));
            writer.newLine();
            writer.write("Disponible: " + (bebida.isDisponible() ? "Si" : "No"));
            writer.newLine();
            writer.write("---------------------------------------------------------------------------------");
            writer.newLine();
        }
    }
    
    public void imprimir() {
        System.out.println("============================= Menú del día ======================================");
        for (Bebida bebida : bebidas) {
            System.out.println(bebida.getTipo() + ": " + bebida.getNombre());
            System.out.println(bebida.getDescripcion());
            System.out.println("Precio: S/ " + String.format("%.2f", bebida.getPrecio()));
            System.out.println("Disponible: " + (bebida.isDisponible() ? "Si" : "No"));
            System.out.println("---------------------------------------------------------------------------------");
        }
    }
    
    public void verificar() {
    }
}
