package homework1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ReadFile {

    private Scanner x;
    public String text;
    // c dosyası açmak için ve bulmayınca ekrana mesaj yazıyor

    public void openFile() {
        try {
            x = new Scanner(new File("Program.c"));
        } catch (FileNotFoundException e) {
            System.out.println("Could'nt find file...");
        }
    }
    // dosyayı okuyunca string e çeviriyor

    public String readFile() {
        while (x.hasNext()) {
            text += x.nextLine() + "\n";
        }
        return text;
    }
    // dosyayı kapatmak için kullanılır 

    public void closeFile() {
        x.close();
    }
}
