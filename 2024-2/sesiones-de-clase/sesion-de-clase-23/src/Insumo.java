/**
 *
 * @author erichuiza
 */
class Insumo {
    private String codigo;
    private String nombre;
    private double cantDisponible;
    private double cantRequerida;
    private String unidadMedida;
    
    public String getCodigo() {
        return codigo;
    }
    
    public String getNombre() {
        return nombre;
    }
    
    public double getCandDisponible() {
        return cantDisponible;
    }
    
    public double getCantRequerida() {
        return cantRequerida;
    }
    
    public String getUnidadMedida() {
        return unidadMedida;
    }
    
    public void setCodigo(final String codigo) {
        this.codigo = codigo;
    }
    
    public void setNombre(final String nombre) {
        this.nombre = nombre;
    }
    
    public void setCantDisponible(final double cantDisponible) {
        this.cantDisponible = cantDisponible;
    }
    
    public void setCantRequerida(final double cantRequerida) {
        this.cantRequerida = cantRequerida;
    }
    
    public void setUnidadMedida(final String unidadMedida) {
        this.unidadMedida = unidadMedida;
    }
}
