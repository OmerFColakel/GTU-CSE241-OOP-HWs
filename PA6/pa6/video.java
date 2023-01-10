/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pa6;

/**
 *
 * @author Ömer Faruk ÇOLAKEL
 */
public class video extends mediaBase implements visual, playable {
    //  Video objects  are inherited from mediaBase.
    //  They are playable and visual.
    
    private int height;
    private int width;
    private double duration;
    
    public video() {
        super();
    }

    public video(String name, int height,int width,double duration) {
        super(name);
        if(height > 0 && width > 0 && duration > 0)
        {
            this.height = height;
            this.width = width;
            this.duration = duration;
        }
    }

    @Override
    public void info() {
        System.out.println(name + " " + height + " " + width + " " + getAspectRatio() + " " + duration + "\n"); 
    }
    
    @Override
    public int getHeight()
    {
        return height;
    }
    
    @Override
    public int getWidth()
    {
        return width;
    }
    
    @Override
    public void setHeight(int  height)
    {
        this.height = height;
        if(height > 0)
            this.height = height;
    }
    
    @Override
    public void setWidth(int  width)
    {
        this.width = width;
        if(width > 0)
            this.width = width;
    }
    
    @Override
    public double getDuration()
    {
        return duration;
    }
    
    @Override
    public void setDuration(double duration)
    {
        if(duration > 0)
            this.duration = duration;
    }
    
    @Override
    public double getAspectRatio()
    {
        try
        {   
            return height/width;
        }
        catch(Exception e)
        {
            return 0;
        }
        
    }

}
