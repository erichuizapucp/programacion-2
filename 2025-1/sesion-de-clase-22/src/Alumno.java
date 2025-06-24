/**
 *
 * @author erichuiza
 */
public class Alumno extends Persona {
    private int ciclo;
    private int numCreditos;

    public Alumno() {
        super();
    }
    
    public Alumno(int dni, String nombre, int edad, 
            int ciclo, int numCreditos) {
        super(dni, nombre, edad);
        this.ciclo = ciclo;
        this.numCreditos = numCreditos;
    }
    
    public int getCiclo() {
        return ciclo;
    }

    public void setCiclo(int ciclo) {
        this.ciclo = ciclo;
    }

    public int getNumCreditos() {
        return numCreditos;
    }

    public void setNumCreditos(int numCreditos) {
        this.numCreditos = numCreditos;
    }

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.println("Ciclo: " + ciclo);
        System.out.println("Num Créditos: " + numCreditos);
    }

    @Override
    public String toString() {
        String str = super.toString();
        str += "Ciclo: " + ciclo + "\n";
        str += "Num Creditos" + numCreditos  + "\n";
        
        return str;
    }
    
    
    
}
