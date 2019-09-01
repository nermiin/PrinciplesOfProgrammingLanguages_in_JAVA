/**
 * *
 * @author Nermin Kaya g161210560@ogr.sakarya.edu.tr
 * @since 1/5/2019
 * <p>
 * Text dosyadan sayilari okup Binler,yuzler,onlar,birler'i toplayip (Seri ve
 * paralel kullanarak) ekrana sonucu yazan bir program.
 * </p>
 */
package paraleljava;

import java.util.ArrayList;
import java.util.List;

public class Basamak_islemi implements Runnable {

    private List<Integer> x = new <Integer> ArrayList();

    Basamak_islemi(List x) {
        this.x = x;
    }
//============================ Toplama islemi ====================================
    public int sum(List<Integer> list) {
        int sum = 0;

        for (int i : list) {
            sum = sum + i;
        }
        return sum;
    }
//================================================================================
    @Override
    public void run() {
        sum(x);
    }
}
//================================================================================
