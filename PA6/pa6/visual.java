/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package pa6;

/**
 *
 * @author Ömer Faruk ÇOLAKEL
 */
public interface visual extends baseInterface { //  Methods for only visual objects

    public int getHeight(); //  Getter for height

    public int getWidth();  //  Getter for width

    public void setHeight(int height);  //  Setter for height   

    public void setWidth(int width);    //  Setter for width

    public double getAspectRatio();     //  Returns Aspect Ratio (height/width)
}
