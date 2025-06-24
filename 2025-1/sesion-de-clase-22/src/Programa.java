/**
 *
 * @author erichuiza
 */
public class Programa {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
//        System.out.println("Hello World.");
//        System.out.println();
//        System.out.println("Primer programa en java.");

       Persona juan = new Persona();
       juan.setId(12345678);
       juan.setEdad(30);
       juan.setNombre("Juan Perez");
       
       juan.imprimir();
       
       System.out.println();
       
       Persona maria = new Persona(45678923, "María Gonzales", 25);
       System.out.println(maria);
       
       System.out.println();
       
       Persona pedro = new Alumno(45678928, "Pedro Gonzales", 24, 6, 22);
       System.out.println(pedro);
       
    }
    
}
