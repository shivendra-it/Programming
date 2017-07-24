import java.io.*;
import java.util.*;

class MyList {
    public static void main(String[] args) {
        List myList = new ArrayList<>();

        myList.add(0, "0");

        //add at specified index
        myList.add(1, "1");

        myList.add(2, "2");
        myList.add(3, "3");
        myList.add(4, "3");
        myList.add(5, "4");

        for(Object v : myList ){
            System.out.println(v.toString());
        }

        //replace
        myList.set(1, "2");

        //remove
        myList.remove("1");
    }
}