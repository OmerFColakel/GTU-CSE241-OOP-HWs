/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pa6;

/**
 *
 * @author Ömer Faruk ÇOLAKEL
 */
public class audio extends mediaBase implements playable, nonVisual {   
    //  Audio objects  are inherited from mediaBase.
    //  They are playable and nonvisual.
    
    private double duration ;   
    
    public audio() {   //  Default Constructor
        super();
    }

    public audio(String name, double duration) {   //  Two Parameter Constructor
        super(name);
        this.duration = duration;
    }

    @Override
    public void info() {    //  Prints info about object
        //  Prints name and duration
        System.out.println(name + " " + duration); 
    }
    
    @Override
    public double getDuration() //  Getter for Duration
    {
        return duration;
    }
    
    @Override
    public void setDuration(double duration)    //  Setter for Duration
    {
       this.duration = duration;
    }
    

}
