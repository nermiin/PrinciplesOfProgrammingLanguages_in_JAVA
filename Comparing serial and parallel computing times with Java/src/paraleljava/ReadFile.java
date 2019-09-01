/** *
 * @author Nermin Kaya g161210560@ogr.sakarya.edu.tr
 * @since 1/5/2019
 * <p>
 * Text dosyadan sayilari okup Binler,yuzler,onlar,birler'i toplayip (Seri ve
 * paralel kullanarak) ekrana sonucu yazan bir program.
 * </p>
 */

package paraleljava;

import java.io.IOException;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ReadFile {

    Scanner scanner;
    List<Integer> integers = new ArrayList<>();
    // txt dosyası açmak için ve bulmayınca ekrana mesaj yazıyor

    public void openFile(Path filePath) {
        try {
            scanner = new Scanner(filePath);
        } catch (IOException ex) {
           System.out.println("Could'nt find file...");
        }

    }
    // dosyayı okuyunca List ye çeviriyor

    public List<Integer> readFile() {
        while (scanner.hasNext()) {
            integers.add(scanner.nextInt());
        }
        return integers;
    }
    // dosyayı kapatmak için kullanılır 

    public void closeFile() {
        scanner.close();
    }
}
