#include <stdio.h>


struct time {
    int sec;
    int min;
    int hr;
};

struct temp {
    int rem1;
    int rem2;
    int s1;
    int m1;
    int h1;
};


struct time diff(struct time t1, struct time t2);

int main() {
    int i;
    struct time s[2];
    struct temp t;

    
    for (i = 0; i < 2; i++) {
        printf("%d. Enter hour, minute, and seconds: ", i + 1);
        scanf("%d%d%d", &s[i].hr, &s[i].min, &s[i].sec);
    }

    // Add the two time values
    t.s1 = s[0].sec + s[1].sec;
    if (t.s1 >= 60) {
        t.rem1 = t.s1 / 60;
        t.s1 = t.s1 % 60;
    } else {
        t.rem1 = 0;
    }

    t.m1 = s[0].min + s[1].min + t.rem1;
    if (t.m1 >= 60) {
        t.rem2 = t.m1 / 60;
        t.m1 = t.m1 % 60;
    } else {
        t.rem2 = 0;
    }

    t.h1 = s[0].hr + s[1].hr + t.rem2;
    printf("Time addition is %d:%d:%d\n", t.h1, t.m1, t.s1);

  
    struct time result = diff(s[0], s[1]);
    printf("Time difference is %d:%d:%d\n", result.hr, result.min, result.sec);

    return 0;
}

struct time diff(struct time t1, struct time t2) {
    struct time result;
    int time1 = t1.hr * 3600 + t1.min * 60 + t1.sec;
    int time2 = t2.hr * 3600 + t2.min * 60 + t2.sec;
    int difference = time1 - time2;

    if (difference < 0) {
        difference += 24 * 3600;
    }

    result.hr = difference / 3600;
    difference %= 3600;
    result.min = difference / 60;
    result.sec = difference % 60;

    return result;
}

