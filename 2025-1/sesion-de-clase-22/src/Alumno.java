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
    
    public Alumno(int dni, String nombre, int edad, int ciclo, int numCreditos) {
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
}
