package Lib;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
*
* @author Nermin Kaya G161210560
* @since 16/03/2019
* <p>
* Random Library to generate character,word,phrase ....
* </p>
*/
public class RastgeleKarakter {
// Ascii den 65=A karakteri ve 122=z ..

    private final int max = 122;
    private final int min = 65;
    private long seed;
    private int last;

//  constructor that takes the max int
    public RastgeleKarakter() {

        last = (int) (System.currentTimeMillis() % 7574);
    }

//  Generate karakter between A-z ..
    public int nextInt() {
        last = (last * 32719 + 3) % 32749;
        return last % (max - min + 1) + min;
    }

//  Generate random character between A-Z and a-z ...
    public char rand() {
        int x;
        while (true) {
            x = nextInt();
            // if statement written to remove character between 90 - 97 .. 
            if ((x > 90) && (x < 97)) {
                continue;
            } else {
                break;
            }
        }
        return (char) x;
    }

//  Generate random character between two characters ..
    protected char rand(int min, int max) {
        if (min > max || (max - min + 1 > Integer.MAX_VALUE)) {
            throw new IllegalArgumentException("Invalid range");
        }
        int x;
//      while statement always true and when it start a random character will generated 
//      next if statement will check if the character between a-z or A-Z then if it's correct it will be exite while statement
//      and return it.
        while (true) {
            x = nextInt();
            if ((x >= min && x <= max) && (x < 91 || x > 96)) {
                break;
            }
        }
        return (char) x;
    }

//  Generate random number between two numbers ..
    public int rand1(int min, int max) {
        int x;
        while (true) {
            last = (last * 32719 + 3) % 32749;
            x = last % (max - min + 1) + min;
            if ((x >= min && x <= max)) {
                break;
            }
        }
        return x;
    }

//  Generate random character with specific number ..
    public String rand(int num) {
        int x = 99;
        StringBuffer r = new StringBuffer(num);

        for (int i = 0; i < num; i++) {
            int nextRandomChar = rand();
            //  append used to collect characters and return them together ..
            r.append((char) nextRandomChar);
        }
        return r.toString();
    }

//  Generate random character with specific number between two characters ..
    public String randBetween(int char1, int char2, int Ntimes) {
        StringBuffer r = new StringBuffer(Ntimes);
        List<Character> lst = new ArrayList<Character>(Ntimes + 1);
        for (int i = 0; i < Ntimes; i++) {
            lst.add(rand(char1, char2));
        }
        // to ascending order characters 
        Collections.sort(lst);
        for (char temp : lst) {
            r.append(temp);
        }
        return r.toString();
    }
    
//  Generate random from specific range ..
    public char RandomList(char[] RL) {
        int x = rand1(0, RL.length - 1);
// generate a random number the return random arrays elemant ..
        return RL[x];
    }

//  Generate random from specific range n times ..
    public String RandomListn(char[] RL, int count) {
        List<Character> r = new ArrayList<Character>(count);
        StringBuffer rr = new StringBuffer(count);
        for (int i = 0; i < count; i++) {
            rr.append(RandomList(RL));
        }
        return rr.toString();
    }

//  Generate random phrase 
    public String RandomPhrase() {
        int[] rn = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        // 1. generate random number
        int x = rand1(3, 10);
        StringBuffer r = new StringBuffer(x);
        // 2.generate word , word length is a random number. 
        for (int i = 0; i <= rand1(3, 10); i++) {
        // 3. collect it together ..
            r.append(rand(rand1(2, rn.length)) + " ");
        }
        return r.toString();
    }
}
