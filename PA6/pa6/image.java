/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pa6;

/**
 *
 * @author Ömer Faruk ÇOLAKEL
 */
public class image extends mediaBase implements visual, nonPlayable {
    //  Image objects  are inherited from mediaBase.
    //  They are nonplayable and visual.
    
    private int height; //  Holds height of image
    private int width;  //  Holds width of image
    
    public image() {   //  Default Constructor
        super();
        height = 0;
        width = 0;
    }

    public image(String name, int height, int width) { //  Three Paramater Constructor
        super(name);
        this.height = height;
        this.width = width;
        
        
    }
    
    @Override
    public int getHeight()  //  Getter for Height
    {
        return this.height;
    }
    
    @Override
    public int getWidth()   //  Getter for Width
    {
        return this.height;
    }
    
    @Override
    public void setHeight(int height)   //  Setter for Height
    {
        this.height = height;
        if(height > 0)
            this.height = height;
    }
    
    @Override
    public void setWidth(int width) //  Setter for Width
    {
        if(width > 0)
            this.width = width;
        
    }
    
    public double getAspectRatio()  //  Return Aspect Ratio
    {
        try
        {
            return height / width;  //  Returns aspect ratio
        }
        catch(Exception e)
        {
            return 0;   //  if width is 0 returns 0
        }
    }
    
    @Override
    public void info() {
        System.out.println(name + " " + height + " " + width + " " + getAspectRatio() + "\n"); 
    }
}
