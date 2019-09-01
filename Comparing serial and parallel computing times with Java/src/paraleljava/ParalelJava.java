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

import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ParalelJava {

    public static void main(String[] args) {
        List<Integer> rakamlar = new <Integer> ArrayList();

        ReadFile read = new ReadFile();
        read.openFile(Paths.get("Sayilar.txt"));//text dosyasi ac
        rakamlar = read.readFile(); //  sayilar rakamlar listeye at
//================================================================================
        List<Integer> Binler = new <Integer> ArrayList();
        List<Integer> Yuzler = new <Integer> ArrayList();
        List<Integer> Onlar = new <Integer> ArrayList();
        List<Integer> Birler = new <Integer> ArrayList();
//================================================================================
// binler yuzler onlar birler ayri ayri listelerine at
        for (int i = 0; i < rakamlar.size(); i++) {
            String rakam = rakamlar.get(i).toString();
            Binler.add(Integer.parseInt(rakam.substring(0, 1)));
            Yuzler.add(Integer.parseInt(rakam.substring(1, 2)));
            Onlar.add(Integer.parseInt(rakam.substring(2, 3)));
            Birler.add(Integer.parseInt(rakam.substring(3, 4)));
        }
//================================================================================
        read.closeFile(); //dosyayi kapat
//=============================== Seri islemi ====================================
        Basamak_islemi islem = new Basamak_islemi(rakamlar);

        long Seri_baslangic = System.nanoTime(); //hesaplama başlıyor
        islem.sum(Binler);
        islem.sum(Yuzler);
        islem.sum(Onlar);
        islem.sum(Birler);
        long Seri_bitis = System.nanoTime();//hesaplama bitiyor
        double Seri_sure = (Seri_bitis - Seri_baslangic) / 1000000.0;
        System.out.printf("\nSonuc %d%d%d%d", islem.sum(Binler), islem.sum(Yuzler), islem.sum(Onlar), islem.sum(Birler));

        System.out.println("\nSeriHesaplanma Süresi " + String.format("%.2f", Seri_sure) + " milisaniye.");
//================================ Paralel islemi ====================================
        ExecutorService havuz = Executors.newFixedThreadPool(4);// d thread li  havuz olustur
        long baslangic = System.nanoTime(); //hesaplama başlıyor
        havuz.execute(new Basamak_islemi(Binler));
        havuz.execute(new Basamak_islemi(Yuzler));
        havuz.execute(new Basamak_islemi(Onlar));
        havuz.execute(new Basamak_islemi(Birler));

        havuz.shutdown();
        while (!havuz.isTerminated()) {
        }
        long bitis = System.nanoTime();//hesaplama bitiyor
        double sure = (bitis - baslangic) / 1000000.0;
        System.out.println("\nParalelHesaplanma Süresi " + String.format("%.2f", sure) + " milisaniye.");
//===============================================================================================
    }
}
