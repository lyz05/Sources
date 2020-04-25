import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class B {
    public static void main(String[] args)  throws IOException{
        String beginDateStr = "2000 1 1";
        String endDateStr = "1000000 1 1";
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            endDateStr = sc.nextLine();
            //System.out.println(endDateStr);
            long days = getDaySub(beginDateStr, endDateStr);
            long week = days / 4 + 1;
            long day = days % 4 + 1;
            System.out.println(week + " " + day);
        }
    }

    public static long getDaySub(String beginDateStr, String endDateStr) {

        long day = 0;
        SimpleDateFormat format = new SimpleDateFormat("yyyy MM dd");
        Date beginDate;
        Date endDate;
        try {
            beginDate = format.parse(beginDateStr);
            endDate = format.parse(endDateStr);
            day = (endDate.getTime() - beginDate.getTime()) / (24 * 60 * 60 * 1000);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        // System.out.println("day:"+day);

        return day;
    }
}