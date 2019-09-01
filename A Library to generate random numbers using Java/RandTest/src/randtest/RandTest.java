package randtest;

import Lib.RastgeleKarakter;

/**
*
* @author Nermin Kaya G161210560
* @since 16/03/2019
* <p>
* Random Library to generate character,word,phrase ....
* </p>
*/
public class RandTest {

    /**
     * @param args the command line arguments
     */
 
     public static void main(String[] args) {
        char[] c = {'g', 'y', 'u', 'n', 'e', 'c'};

        RastgeleKarakter rs = new RastgeleKarakter();
        // to generate 1 random character
        System.out.println("Rastgele Karakter : " + rs.rand());
        // to generate 1 random character
        System.out.println("Rastgele Karakter : " + rs.rand());
        // to generate 30 random character
        System.out.println("Rastgele 30 kere Karakter : " + rs.rand(30));
        // to generate 50 random character
        System.out.println("Rastgele 100 kere Karakter : " + rs.rand(100));
        // to generate a arandom character between a and k 
        System.out.println("Verilen iki karakter (a,k): " + rs.randBetween('a', 'k', 1));
        // to generate a arandom character between a and k 
        System.out.println("Verilen iki karakter(a,k) 3 defa : " + rs.randBetween('a', 'k', 3));
        // to generate a arandom character between a and k 
        System.out.println("Belirtilen Karakterler (g,y,u,n,e,c) : " + rs.RandomList(c));
        // to generate a arandom character between a and k  
        System.out.println("Belirtilen karakter (g,y,u,n,e,c) 3 defa : " + rs.RandomListn(c, 3));
        // to generate a arandom cÃ¼mle  
        System.out.println("Rastgele cÃ¼mle : " + rs.RandomPhrase());
        System.out.println("Rastgele cÃ¼mle : " + rs.RandomPhrase());
    }
    
}
