#include <iostream>
#include <string>

using namespace std;

struct Date {
  int year;
  int month;
  int day;
};

bool datecomp(Date d1, Date d2) {
  if (d1.year != d2.year) {
    return d1.year < d2.year;
  } else {
    if (d1.month != d2.month)
      return d1.month < d2.month;
    else {
        return d1.day <= d2.day;
    }
  }
}

bool is_leap_years(int d) {
  return ((d % 4 == 0 && d % 100 != 0) || (d % 400 == 0));
}

int get_num_days(int d) {
  return is_leap_years(d) ? 366 : 365;
}

int day2end(Date d) {
  int totaldays = get_num_days(d.year);
  int s[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (totaldays == 366) s[2] = 29;
  int ans = 0;
  for (int i = d.month; i < 13; i++) {
    ans += s[i];
  }
  // subtract days
  ans -= d.day;
  return ans;
}

int datediff(Date d1, Date d2) {
  int ans = 0;
  if (!datecomp(d1, d2)) {
    swap(d1, d2);
  }
  // 先计算年份差距
  int a = day2end(d1);
  int b = day2end(d2);
  if (d1.year == d2.year) {return a - b;}
  int day_gap_year = 0;

  for (int i = d1.year + 1; i < d2.year; i ++) {
    day_gap_year += get_num_days(i);
  }
  return a + get_num_days(d2.year) - b + day_gap_year;
}

int main() {

  Date d;
  Date end;
  d.year = 2020;
  d.month = 1;
  d.day = 21;
  end.year = 2020;
  end.month = 10;
  end.day = 2;
  cout << datediff(d, end) <<endl;
  return 0;
}