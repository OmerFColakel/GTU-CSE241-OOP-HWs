/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pa6;

/**
 *
 * @author Ömer Faruk ÇOLAKEL
 */
public class mediaBase {    //  Base for text,image,video and audio

    protected String name;  

    public mediaBase() {   //  Default Constructor
        name = "nameNULL";
    }

    public mediaBase(String name) {    //  One Parameter Cosntructor
        this.name = name;
    }

    public String getName() {   //  Getter for Name
        return name;
    }

    public void setName(String name) {  //  Setter for Name
        this.name = name;
    }
    
    @Override
    public String toString() {
        return this.name;
    }
}
