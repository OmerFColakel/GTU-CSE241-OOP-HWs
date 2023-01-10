/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pa6;

/**
 *
 * @author Ömer Faruk ÇOLAKEL
 */
public class text extends mediaBase implements nonVisual, nonPlayable {
    //  Text objects  are inherited from mediaBase.
    //  They are nonplayable and nonvisual.
    public text() {
        super();
    }

    public text(String name) {
        super(name);
    }

    @Override
    public void info() {
        System.out.println(super.toString()); 
    }
}
