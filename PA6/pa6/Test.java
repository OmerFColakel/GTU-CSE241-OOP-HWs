/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
import pa6.*;

/**
 *
 * @author Ömer Faruk ÇOLAKEL
 */
public class Test {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        dataset DS = new dataset();

        Player p1 = new Player("Player 1");
        Player p2 = new Player("Player 2");
        Player p3 = new Player("Player 3");
        Viewer v1 = new Viewer("Viewer 1");
        Viewer v2 = new Viewer("Viewer 2");

        DS.register(p1);
        DS.register(p1);

        DS.register(p2);    //  Checking if the same object can be registered multiple times

        DS.register(p3);
        DS.register(v1);
        DS.register(v2);

        System.out.println("Dataset Before Removing p3:");
        System.out.println(DS);
        DS.remove_observer(p3); //  Checking if the remove_observer() works 
        System.out.println("Dataset After Removing p3:");
        System.out.println(DS);

        System.out.println("Adding new image objects to dataset");
        DS.add(new image("imagename1", 200, 100));
        DS.add(new image("imagename2", 150, 300));
        DS.add(new image("imagename3", 1, 2));
        DS.add(new image("imagename4", 1, 15));
        DS.add(new image("imagename5", 1000, 1000));

        System.out.println("Adding new audio objects to dataset");
        DS.add(new audio("audioname1", 15.2));
        DS.add(new audio("audioname2", 8.3));
        DS.add(new audio("audioname3", 31));

        System.out.println("Adding new video objects to dataset");
        DS.add(new video("videoname1", 10, 10, 2));
        DS.add(new video("videoname2", 100, 2, 15.9));
        DS.add(new video("videoname3", 15, 300, 125.6));

        System.out.println("Adding new text objects to dataset");
        DS.add(new text("textname1"));
        DS.add(new text("textname2"));
        DS.add(new text("textname3"));
        
        //  User doesn't have to add registers first and then medias everytime.
        //  Medias in dataset will be sorted and added to register 
        //  even if the medias  are added first.
        System.out.println("Testing p3:");
        DS.register(p3);
        p3.showList();
        DS.remove_observer(p3);

        System.out.println("checking every player and viewer:");
        System.out.println("p1->showList()");
        p1.showList();  //  Testing players' showlist
        System.out.println("v1->showList()");
        v1.showList();  //  Testing viewers' showlist
        System.out.println("p2->showList()");
        p2.showList();  //  Testing players' showlist
        System.out.println("v2->showList()");
        v2.showList();  //  Testing viewers' showlist
        
        
        System.out.println("Testing next() on p1:");
        System.out.println("p1 currently playing: " + p1.currently_playing()); //audio1
        p1.next("audio");
        System.out.println("p1 currently playing: " + p1.currently_playing()); // audio2
        p1.next("video");
        System.out.println("p1 currently playing: " + p1.currently_playing()); //video1
        p1.next("audio");
        System.out.println("p1 currently playing: " + p1.currently_playing()); //video1
        p1.next("video");   //  video2
        p1.next("video");   //  video3 (last object in the arraylist)
        p1.next("video");   //  cant skip  
        p1.next("audio");   //  cant skip
        p1.next("a  ");     //  type is wrong
        
        System.out.println("Testing previous() on p1:");
        System.out.println("p1 currently playing: " + p1.currently_playing()); //video3
        p1.previous("video");
        System.out.println("p1 currently playing: " + p1.currently_playing()); // video2
        p1.previous("audio");
        System.out.println("p1 currently playing: " + p1.currently_playing()); // audio3

        System.out.println("\nTesting next() on v1:");
        System.out.println("v1 currently playing: " + v1.currently_viewing()); //image1
        v1.next("image");
        System.out.println("v1 currently playing: " + v1.currently_viewing()); // image2
        v1.next("text");
        System.out.println("v1 currently playing: " + v1.currently_viewing()); //text1
        v1.next("image");
        System.out.println("v1 currently playing: " + v1.currently_viewing()); // text1
        v1.next("a  ");     //  type is wrong
        System.out.println("Testing previous() on v1:");
        v1.previous("image");
        System.out.println("v1 currently playing: " + v1.currently_viewing()); //  image5
        v1.previous("text");
        System.out.println("v1 currently playing: " + v1.currently_viewing()); //  image5
        v1.previous("image");
        System.out.println("v1 currently playing: " + v1.currently_viewing()); //  image4

        playable po = (playable) p1.currently_playing();    //  audio3
        po.info();  //audio3
        DS.remove(po);  // removed audio3
        System.out.println("p1 without audio3: ");
        System.out.println("Player1.showlist->");
        p1.showList();
        System.out.println("Currentlyplaying->");
        System.out.println(p1.currently_playing()); //video1
        p1.previous("audio");
        System.out.println("Currentlyplaying->");
        System.out.println(p1.currently_playing()); //audio2
        po = (playable) p1.currently_playing();     //audio2
        DS.remove(po);
        System.out.println("Player1.showlist->");
        p1.showList();
        System.out.println("Currentlyplaying->");
        System.out.println(p1.currently_playing());
        
        nonPlayable npo = (nonPlayable)v1.currently_viewing();//image4
        npo.info();//image4
        System.out.println("Removed npo (image4)");
        DS.remove(npo);
        System.out.println("Viewer1.showlist->");
        v1.showList();
        System.out.println("Currentlyviewing->");
        System.out.println(v1.currently_viewing()); //image5
        v1.previous("image");
        System.out.println("Currentlyviewing->");   // image3
        System.out.println(v1.currently_viewing());
        npo = (nonPlayable) v1.currently_viewing(); //image3
        System.out.println("Removed image3");
        DS.remove(npo);
        System.out.println("Currentlyviewing->");
        System.out.println(v1.currently_viewing());
    }

}
