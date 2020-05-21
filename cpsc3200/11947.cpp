//use date class and compare dates in range to find sign

#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

struct Date {

  int yyyy;
  int mm;
  int dd;

  // no dates before 1753
  static int const BASE_YEAR = 1753;

  // Enumerated type for names of the days of the week
  enum dayName {SUN,MON,TUE,WED,THU,FRI,SAT};

  // Is a date valid
  static bool validDate(int yr, int mon, int day)
  {
    return yr >= BASE_YEAR && mon >= 1 && mon <= 12 &&
      day > 0 && day <= daysIn(mon, yr);
  }    

  bool isValid() const
  {
    return validDate(yyyy, mm, dd);
  }
  
  // Constructor to create a specific date.  If the date is invalid,
  // the behaviour is undefined
  Date(int yr = 1970, int mon = 1, int day = 1)
  {
    yyyy = yr;
    mm = mon;
    dd = day;
  }
  
  // Returns the day of the week for this
  dayName dayOfWeek() const
  {
    int a = (14 - mm) / 12;
    int y = yyyy - a;
    int m = mm + 12 * a - 2;
    return (dayName)((dd + y + y/4 - y/100 + y/400 + 31 * m / 12) % 7);
  }
  
  // comparison operators
  bool operator==(const Date &d) const
  {
    return dd == d.dd && mm == d.mm;
  }

  bool operator<(const Date &d) const
  {
    return yyyy < d.yyyy || (yyyy == d.yyyy && mm < d.mm) ||
      (mm == d.mm && dd < d.dd);
  }

  bool operator<=(const Date& d) const 
  {
    return *this < d || *this == d;
  }

  bool operator>=(const Date& d) const
  {
    return !(*this < d) || *this == d;
  }


  // Returns true if yr is a leap year
  static bool leapYear(int y)
  {
    return (y % 400 ==0 || (y % 4 == 0 && y % 100 != 0));
  }

  // number of days in this month
  static int daysIn(int m, int y)
  {
    switch (m) {
    case 4  :
    case 6  :
    case 9  :
    case 11 :
      return 30;
    case 2  :
      if (leapYear(y)) {
	return 29;
      }
      else {
	return 28;
      }
    default :
      return 31;
    }
  }
  
  // increment by day, month, or year
  //
  // Use negative argument to decrement
  //
  // If adding a month/year results in a date before BASE_YEAR, the result
  // is undefined.
  //
  // If adding a month/year results in an invalid date (Feb 29 on a non-leap
  // year, Feb 31, Jun 31, etc.), the results are automatically "rounded down"
  // to the last valid date

  // add n days to the date: complexity is about n/30 iterations
  void addDay(int n = 1)
  {
    dd += n;
    while (dd > daysIn(mm,yyyy)) {
      dd -= daysIn(mm,yyyy);
      if (++mm > 12) {
	mm = 1;
	yyyy++;
      }
    }
    
    while (dd < 1) {
      if (--mm < 1) {
	mm = 12;
	yyyy--;
      }
      dd += daysIn(mm,yyyy); 
    }
  }

  // add n months to the date: complexity is about n/12 iterations
  void addMonth(int n = 1)
  {
    mm += n;
    while (mm > 12) {
      mm -= 12;
      yyyy++;
    }
    
    while (mm < 1)  {
      mm += 12;
      yyyy--;
    }
    
    if (dd > daysIn(mm,yyyy)) {
      dd = daysIn(mm,yyyy);
    }
  }

  // add n years to the date
  void addYear(int n = 1)
  {
    yyyy += n;
    if (!leapYear(yyyy) && mm == 2 && dd == 29) {
      dd = 28;
    }
  }

  // number of days since 1753/01/01, including the current date
  int daysFromStart() const
  {
    int c = 0;
    Date d(BASE_YEAR, 1, 1);
    Date d2(d);

    d2.addYear(1);
    while (d2 < *this) {
      c += leapYear(d.yyyy) ? 366 : 365;
      d = d2;
      d2.addYear(1);
    }

    d2 = d;
    d2.addMonth(1);
    while (d2 < *this) {
      c += daysIn(d.mm, d.yyyy);
      d = d2;
      d2.addMonth(1);
    }
    while (d < *this) {
      d.addDay();
      c++;
    }
    return c;
  }
};


int y = 2000;
vector<pair<pair<Date, Date>, string>> V = {
  { { Date(y, 1, 21), Date(y, 2, 19) }, "aquarius" },
  { { Date(y, 2, 20), Date(y, 3, 20) }, "pisces" },
  { { Date(y, 3, 21), Date(y, 4, 20) }, "aries" },
  { { Date(y, 4, 21), Date(y, 5, 21) }, "taurus" },
  { { Date(y, 5, 22), Date(y, 6, 21) }, "gemini" },
  { { Date(y, 6, 22), Date(y, 7, 22) }, "cancer"},
  { { Date(y, 7, 23), Date(y, 8, 21) }, "leo" },
  { { Date(y, 8, 22), Date(y, 9, 23) }, "virgo" },
  { { Date(y, 9, 24), Date(y, 10, 23) }, "libra" },
  { { Date(y, 10, 24), Date(y, 11, 22) }, "scorpio" },
  { { Date(y, 11, 23), Date(y, 12, 22) }, "sagittarius" }
};


string getSign(Date d) {
  for(auto& p : V) {
    p.first.first.yyyy = p.first.second.yyyy = d.yyyy;
    if(d >= p.first.first && d <= p.first.second) return p.second;
  }
  return "capricorn";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  int count = 1;
  while(t--) {
    string s; cin >> s;

    int year, month, day;
    month = stoi(s.substr(0, 2));
    day = stoi(s.substr(2, 2));
    year = stoi(s.substr(4, 4));

    Date a;
    a.yyyy = year;
    a.mm = month;
    a.dd = day;

    a.addDay(40*7);

    cout << count++ << " "; 
    if(a.mm < 10) cout << '0' << a.mm;
    else cout << a.mm;
    cout << "/";
    if(a.dd < 10) cout << '0' << a.dd;
    else cout << a.dd;
    cout << "/" << a.yyyy << " " << getSign(a) << endl;
  }
}

