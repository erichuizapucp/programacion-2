import java.util.Scanner;

/**
 *
 * @author erichuiza
 */
class Bebida extends Producto {
    private char tipoBebida;
    
    @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        tipoBebida = archivo.next().charAt(0);
    }

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.println("Tipo: " + (tipoBebida == 'C' ? "Café" : tipoBebida == 'H' ? "Chocolate" : "Infusión"));
        System.out.println("---------------------------------------------------------------------------------");
    }

    @Override
    public void imprimir(Alumno alumno, Pais pais) {
        super.imprimir(alumno, pais); 
        System.out.println("Tipo: " + (tipoBebida == 'C' ? "Café" : tipoBebida == 'H' ? "Chocolate" : "Infusión"));
        System.out.println("----------------------------------------------------------------------------------------------------");
    }
}