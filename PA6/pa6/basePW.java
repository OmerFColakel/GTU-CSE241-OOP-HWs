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
public abstract class basePW {  //  A base class for player and viewer

    protected int current = 0;  //  The index of current media object
    protected final List<mediaBase> medias = new ArrayList<>(); //  All objects that can be played or viewed
    protected String name;  //  Name of the player or viewer

    public basePW() {  //  Default Constructor
        name = "nameNULL";
    }

    public basePW(String name) {   //  One parameter constructor
        this.name = name;
    }

    public String getName() {   //  Getter for name
        return name;
    }

    public void setName(String name) {  //  Setter for name
        this.name = name;
    }

    public void add(mediaBase newMedia) {   //  Adds a new media object to playlist
        boolean flag = true;
        for (mediaBase i : medias) {    //  Checking if the object is already added or not
            if (i == newMedia) {
                flag = false;
            }
        }
        if (flag) { //  If the same object is not in the playlist then addig it to the playlist
            medias.add(newMedia);
            notifyAdd();
        }
    }

    public int getCurrent() {   //  Getter for current
        return current;
    }

    public void setCurrent(int current) {   //  Setter for current
        if (current >= 0 && this.current != current) {
            this.current = current;
        }
    }

    public void showList() {    //  Prints thr current playlist
        for (mediaBase i : medias) {
            System.out.println(i);
        }
    }

    public abstract void next(String type); //  Currently playing goes to next "type" object

    public abstract void previous(String type);    //  Currently playing goes to previous "type" object

    public void remove(mediaBase obj) //  Removes object from playlist
    {
        if (obj == medias.get(current) && current == medias.size() - 1) {
            current = 0;    //  If the removed object is the last one playlist returns to first object
        }
        medias.remove(obj); //  Remove Object 
        notifyRemove(); //  Notify User
    }

    private void notifyAdd() //  Notify user when an object has been added
    {
        System.out.println("Object has been added successfully.");
    }

    private void notifyRemove() //  Notify user when an object has been removed
    {
        System.out.println("Object has been removed successfully.");
    }
}
