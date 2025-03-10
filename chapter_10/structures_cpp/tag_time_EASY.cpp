#include <iostream>

struct tag_time {
  unsigned char hours;
  unsigned char minutes;
  unsigned char seconds;

  char* get_time(char* str, size_t max_length) {
    snprintf(str, max_length, "%02hhu:%02hhu:%02hhu", hours, minutes, seconds);
    return str;
  }

  static tag_time sum_time(const tag_time& t1, const tag_time& t2) {
    tag_time tm_sum;
    tm_sum.seconds = (t1.seconds + t2.seconds) % 60;
    tm_sum.minutes =
        ((t1.minutes + t2.minutes) + (t1.seconds + t2.seconds) / 60) % 60;
    tm_sum.hours =
        ((t1.hours + t2.hours) +
         (((t1.minutes + t2.minutes) + (t1.seconds + t2.seconds) / 60) / 60)) %
        24;
    return tm_sum;
  }
};

int main(void) {
  tag_time tm1, tm2, time_res;
  char str[9];
  scanf("%hhu%hhu%hhu", &tm1.hours, &tm1.minutes, &tm1.seconds);
  scanf("%hhu%hhu%hhu", &tm2.hours, &tm2.minutes, &tm2.seconds);
  time_res = tag_time::sum_time(tm1, tm2);
  time_res.get_time(str, sizeof(str));
  puts(str);
  //__ASSERT_TESTS__
  return 0;
}