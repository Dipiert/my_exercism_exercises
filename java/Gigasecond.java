import java.time.LocalDate;
import java.time.LocalDateTime;

class Gigasecond {
    private LocalDateTime now;
    private static long GIGASEC = 1000000000L;

    Gigasecond(LocalDate birthDate) {
        now = birthDate.atStartOfDay();
    }

    Gigasecond(LocalDateTime birthDateTime) {
        now = birthDateTime;
    }

    LocalDateTime getDate() {
        return now.plusSeconds(GIGASEC);
    }

}

