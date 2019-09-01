package homework1;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Boss {

    /**
     *
     * @author Nermin Kaya
     * @since 2/2/2019
     * <p>
     * implement java program which is reading from C file and detected how much
     * an operator , functions there is ! and writing operator's and function's
     * names,then print them to screen .... :)
     * </p>
     */
    public String Ctypes = "\\b(char|int|short|long|float|double|unsigned|signed|void|bool|struct|enum)\\b";

    // Opeatör sayısı bulmak için :
    int FindOperatorS(String text) {
        // m1 içinde yazılan operatörler + - * & = < > ! > / olarak metinden çıkartıyor.
        Matcher m1 = Pattern.compile("[+//-//*//&//=//<//>//!//|///]").matcher(text);
        // m2 içinde yazılan operatörler ++ -- && || == olarak metinden çıkartıyor.
        Matcher m2 = Pattern.compile("([+][+])|([-][-])|([&][&])|([|][|]|([=][=]))").matcher(text);

        int count = 0;
        // m1 operatörleri bulunca sayıcı 1 arttıyor .
        while (m1.find()) {
            count++;
        }
        // m2 operatörleri bulunca sayıcıdan 1 çıkartıyor .
        while (m2.find()) {
            count--;
        }
        return count;
    }

    // Fonkisyon sayısı bulmak için :
    int FuncS(String text) {
//       Matcher funcsayi = Pattern.compile("\\bvoid|return\\b").matcher(text);
//       Matcher funcsayi = Pattern.compile(Ctypes+"(.*?)(\\))((\n\\{)|(\\{))",Pattern.DOTALL).matcher(text);
        Matcher funcsayi = Pattern.compile(Ctypes + ".*?\\(.*?\\)", Pattern.DOTALL).matcher(text);
        int fonkcount = 0;
        while (funcsayi.find()) {
            fonkcount++;
        }
        return fonkcount;
    }

    // Parametre sayısı bulmak için
    int ParametreS(String text) {
        Matcher funcsayi = Pattern.compile("\\(" + Ctypes + ".*?\\)", Pattern.DOTALL).matcher(text);

        char[] lst;
        int count = 0;
        while (funcsayi.find()) {
            count++;
            lst = funcsayi.group().toCharArray();
            for (char var : lst) {
                if (var == ',') {
                    count++;
                }
            }
        }
        return count;
    }

    public static String removeChar(String s, char c) {
        String r = "";
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != c) {
                r += s.charAt(i);
            }
        }
        return r;

    }

    // açıklama satrı // , /**/ ve include satrı metinden silmek için
    String replacetext(String text) {
        StringBuffer sb = new StringBuffer();
        Matcher m1 = Pattern.compile("((\\/\\*)(.*?)(\\*\\/))", Pattern.DOTALL).matcher(text);
        Matcher m2 = Pattern.compile("(\\/\\/(.*?)\n)", Pattern.MULTILINE).matcher(text);
        Matcher m3 = Pattern.compile("\\#\\binclude\\b(.*?)>", Pattern.MULTILINE).matcher(text);
        Matcher m4 = Pattern.compile("\\#\\binclude\\b(.*?)\"(.*?)\"", Pattern.MULTILINE).matcher(text);

        while (m1.find()) {
            text = text.replaceAll(m1.group(3), "");
            text = text.replaceAll("/\\*\\*/", "");
        }
        while (m2.find()) {
            text = text.replaceAll("(\\/\\/(.*?)\n)", "");
        }

        while (m3.find()) {
            text = text.replaceAll("\\#\\binclude\\b(.*?)>", "");
        }

        while (m4.find()) {
            text = text.replaceAll("\\#\\binclude\\b(.*?)\"(.*?)\"", "");
        }

        return text;
    }

    // süslü parantez içinde ne varsa silmek için 
    String replacetext2(String text) {
        StringBuffer sb = new StringBuffer();
        Matcher m1 = Pattern.compile("\\{(.*?)\\}", Pattern.DOTALL).matcher(text);
        while (m1.find()) {
            m1.appendReplacement(sb, "");
        }
        m1.appendTail(sb);
        return sb.toString();
    }

    // fonksiyon ismi ve parametre isimleri bulmak için
    void FindFPNama(String text) {
        StringBuffer sb = new StringBuffer();
        Matcher m = Pattern.compile(Ctypes + "(.*?)(\\()(.*?)(\\))").matcher(text);
        while (m.find()) {
            // group(1) ctypes içerdiği c veri tipi int gibi metinden silmektedir
            text = text.replaceAll(m.group(1), "");
            // group(2) fonsiyon ismi group(4) parametre ismi 
            System.out.println(m.group(2) + " -Parametreleri : " + m.group(4).replaceAll(Ctypes, ""));
        }
    }
}
