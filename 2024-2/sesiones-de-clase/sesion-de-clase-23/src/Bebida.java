import java.util.List;

/**
 *
 * @author erichuiza
 */
class Bebida {
    private String codigo;
    private String nombre;
    private String descripcion;
    private char tipo;
    private double precio;
    private int cantVent;
    private boolean disponible;
    private List<Ingrediente> ingredientes;
    
    public String getCodigo() {
        return codigo;
    }

    public String getNombre() {
        return nombre;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public char getTipo() {
        return tipo;
    }

    public double getPrecio() {
        return precio;
    }

    public int getCantVent() {
        return cantVent;
    }

    public boolean isDisponible() {
        return disponible;
    }

    public List<Ingrediente> getIngredientes() {
        return ingredientes;
    }
    
    public void setCodigo(final String codigo) {
        this.codigo = codigo;
    }

    public void setNombre(final String nombre) {
        this.nombre = nombre;
    }

    public void setDescripcion(final String descripcion) {
        this.descripcion = descripcion;
    }

    public void setTipo(final char tipo) {
        this.tipo = tipo;
    }

    public void setPrecio(final double precio) {
        this.precio = precio;
    }

    public void setCantVent(final int cantVent) {
        this.cantVent = cantVent;
    }

    public void setDisponible(final boolean disponible) {
        this.disponible = disponible;
    }

    public void setIngredientes(final List<Ingrediente> ingredientes) {
        this.ingredientes = ingredientes;
    }
}
