/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pa6;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Ömer Faruk ÇOLAKEL
 */
public class Viewer extends basePW {

    public Viewer() {  //  Default Constructor
        super();
    }

    public Viewer(String name) {   //  One Parameter Constructor 
        super(name);
    }

    @Override
    public void next(String type) {
        if (type == "text" || type == "image") {    //  Checking if the type is valid
            if (this.current < medias.size() - 1) { //  Checking if there are any previous objects
                for (int i = this.current + 1; i < medias.size(); ++i) {
                    String str = medias.get(i).getClass().toString();   //  Getting the current class's type
                    for (int j = 0; j < str.length(); ++j) {
                        if (str.charAt(j) == '.') { //  Splitting the string into 2 from the '.'
                                                    //  Because we only need after '.'                          
                            ++j;
                            if (str.charAt(j) == type.charAt(0)) {  //  If the type of one of the previous objects
                                                                    //  is same with type string then that              
                                this.current = i;                   //  object will be currentlyPlaying object.
                                return;
                            }
                        }
                    }
                }
                System.out.println("Couldn't find that type among the previous tracks.");
            } else {
                System.out.println("Can't skip to next one because playlist has ended.");
            }
        } else {
            System.out.println("Type is wrong.");
        }
    }

    @Override
    public void previous(String type) {
        if (type == "text" || type == "image") {    //  Checking if the type is valid
            if (this.current > 0) {     //  Checking if there are any previous objects
                for (int i = this.current - 1; i >= 0; --i) {
                    String str = medias.get(i).getClass().toString();   //  Getting the current class's type
                    for (int j = 0; j < str.length(); ++j) {
                        if (str.charAt(j) == '.') { //  Splitting the string into 2 from the '.'
                                                    //  Because we only need after '.'                          
                            ++j;
                            if (str.charAt(j) == type.charAt(0)) {  //  If the type of one of the previous objects
                                                                    //  is same with type string then that              
                                this.current = i;                   //  object will be currentlyPlaying object.
                                return;
                            }
                        }
                    }
                }
                System.out.println("Couldn't find that type among the previous tracks.");
            } else {
                System.out.println("Can't go back to previous one because playlist has just started.");
            }
        } else {
            System.out.println("Type is wrong!");
        }

    }
    
    public mediaBase currently_viewing() {      //  Returns currently playing object
        try
        {
            return medias.get(current);          
        }
        catch(Exception e)  //  If there are no currently playing object then method returns empty object
        {
            current = 0;    //  Also resets current
            return new mediaBase(); //  Return empty object
        }

    }
}
