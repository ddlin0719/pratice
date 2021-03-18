package org.ddddd;

public class ReportUtils {
    public static String getTimeFormat(long timeCost) {
        long totalSecond = timeCost / 1000;
        long hours = totalSecond / 3600;
        long minutes = (totalSecond - 3600 * hours) / 60;
        long seconds = totalSecond - hours * 3600 - minutes * 60;

        StringBuilder sb = new StringBuilder();
        if (hours > 0) {
            sb.append(hours).append("h").append(" ");
        }
        if (minutes > 0) {
            sb.append(minutes).append("min").append(" ");
        }
        if (seconds > 0) {
            sb.append(seconds).append("s");
        }

        if (hours == 0 && minutes == 0 && seconds == 0) {
            sb.append("0s");
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(getTimeFormat(1000));
        System.out.println(getTimeFormat(3599000));
        System.out.println(getTimeFormat(3601000));
        System.out.println(getTimeFormat(7200000));
        System.out.println(getTimeFormat(59000));
        System.out.println(getTimeFormat(61000));
        System.out.println(getTimeFormat(180000));
        System.out.println(getTimeFormat(999999999));
    }
}
