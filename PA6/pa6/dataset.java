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
public class dataset {

    private final List<basePW> pw = new ArrayList<>();  //  Holds the observers
    private final List<mediaBase> medias = new ArrayList<>();   //  Holds the media objects
    
    public void register(basePW newPW) {    //
        boolean flag = true;
        for (basePW i : pw) //  Checking if the player or viewer is already in the list
        {
            if (newPW == i) {
                flag = false;
                break;
            }
        }
        if (flag) {
            pw.add(newPW);
            for(mediaBase i : medias)
            {
                if(pw.get(pw.size()-1) instanceof Player && i instanceof playable)
                    pw.get(pw.size()-1).add(i);
                else if(pw.get(pw.size()-1) instanceof Viewer && i instanceof nonPlayable)
                    pw.get(pw.size()-1).add(i);
            }
                
        }   
    }

    public void remove_observer(Player newPlayer) {
        pw.remove(newPlayer);   //  Removes observer from arraylist
    }

    public void add(mediaBase newObj) {     //  Adds new obj to arraylist , player and viewers

        for(mediaBase i : medias)   // Doesn't add media to array if it already exists
            if(i == newObj)
               return;
            
        medias.add((newObj));   //  adds to arraylist
        for (basePW i : pw) {   // adds playable to players and nonplayables to viewers
            if (newObj instanceof playable && i instanceof Player) {
                i.add(newObj);
            }else if(newObj instanceof nonPlayable && i instanceof Viewer)
            {
                i.add(newObj);
            }
        }
    }

    public void remove(baseInterface obj)   //  Removes objects from observers
    {
        for(basePW i: pw)
            if(obj instanceof playable && i instanceof Player) 
                i.remove((mediaBase)obj);
            else if (obj instanceof nonPlayable && i instanceof Viewer)
                i.remove((mediaBase)obj);
            
    }
    @Override
    public String toString() {
        String str = "";
        for (basePW i : pw) {
            str += i.getName() + "\n";
        }
        return str;
    }
}
