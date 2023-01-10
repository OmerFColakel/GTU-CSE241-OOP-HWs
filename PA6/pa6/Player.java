/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pa6;

/**
 *
 * @author Ömer Faruk ÇOLAKEL
 */
public class Player extends basePW {

    public Player() {  //  Default Constructor
        super();
    }

    public Player(String name) {   //  One Parameter Constructor 
        super(name);
    }

    public mediaBase currently_playing() {      //  Returns currently playing object
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
    
    @Override
    public void next(String type) {
        if (type == "audio" || type == "video") {   //  Checking if the type is valid
            if (this.current < medias.size() - 1) { //  Checking if there are any objects to skip to
                for (int i = this.current + 1; i < medias.size(); ++i) {
                    String str = medias.get(i).getClass().toString();   //  Getting the current class's type
                    for (int j = 0; j < str.length(); ++j) {
                        if (str.charAt(j) == '.') { //  Splitting the string into 2 from the '.'
                                                    //  Because we only need after '.'
                            ++j;
                            if (str.charAt(j) == type.charAt(0)) //  If the type of one of the next objects
                            {                                    //  is same with type string then that 
                                this.current = i;                //  object will be currentlyPlaying object.
                                return;
                            }
                        }
                    }
                }
                System.out.println("Couldn't find that type among the next tracks.");
            } else {
                System.out.println("Can't skip to next one because playlist has ended.");
            }
        } else {
            System.out.println("Type is wrong.");
        }

    }

    @Override
    public void previous(String type) {
        if (type == "audio" || type == "video") {
            if (this.current > 0) {     //  if current object has 0 index then there's no previous objects
                for (int i = this.current - 1; i >= 0; --i) {
                    String str = medias.get(i).getClass().toString();   //  Getting the class's type
                    for (int j = 0; j < str.length(); ++j) {
                        if (str.charAt(j) == '.') { //  Splitting the string into 2 from the '.'
                                                    //  Because we only need after '.'.
                            ++j;
                            if (str.charAt(j) == type.charAt(0)) //  If the type of one of the next objects
                            {                                    //  is same with type string then that 
                                this.current = i;                //  object will be currentlyPlaying object.
                                return;
                            }
                        }
                    }
                }
                System.out.println("Couldn't find that type previous the next tracks.");
            } else {
                System.out.println("Can't go back to previous one because playlist has just started.");
            }
        } else {
            System.out.println("Type is wrong!");
        }

    }
}
