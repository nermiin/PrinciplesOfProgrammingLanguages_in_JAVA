package homework1;

public class HomeWork1 {

    public static void main(String[] args) {
        // ReadFile sınıfı çağır
        ReadFile r = new ReadFile();
        // Boss sınıfı çağır
        Boss b = new Boss();
        
        String cc ="";
        // C dosyası aç
        r.openFile();
        // c dosyası oku ve CFile adılı string e çevir
        String CFile = r.readFile();
        // metinden acıklama ve include satırları sil
        CFile = b.replacetext(CFile);

        System.out.println("Toplam Operatör Sayısı  : " + b.FindOperatorS(CFile));
        
        // süslü parantezın içeriği sil
        CFile = b.replacetext2(CFile);
        
        System.out.println("Toplam Fonksiyon Sayısı : " + b.FuncS(CFile));
        System.out.println("Toplam Parametre Sayısı : " + b.ParametreS(CFile));
        System.out.println("Fonksiyon İsimleri  :");

        //fonksiyon ismi ve parametreleri ekrana yazdır .
        b.FindFPNama(CFile);
        //C dosyası kapat
        r.closeFile();
    }
}
