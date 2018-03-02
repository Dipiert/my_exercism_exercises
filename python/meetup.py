from datetime import date, timedelta

def meetup_day(year, month, day_of_the_week, which):
    X_days_of_month = all_X_day_of_a_month(year, month, day_of_the_week)
    weeks_name = {'1st' : 0, '2nd' : 1, '3rd' : 2, '4th' : 3, '5th' : 4,'last' : -1}
    for week_name in weeks_name: 
        if which == week_name: return X_days_of_month[weeks_name[week_name]]
    if which == 'teenth': return getTeenthDay(X_days_of_month)
    raise Exception('MeetupDayException')

def all_X_day_of_a_month(year, month, day_of_the_week):
   days = []
   daysNames = {"Monday": 0, "Tuesday": 1, "Wednesday": 2, "Thursday": 3, "Friday": 4, "Saturday": 5, "Sunday": 6}
   d = date(year, month, 1)
   d += timedelta(days = (daysNames[day_of_the_week] - d.weekday() + 7) % 7)  # First day_of_the_week on the month
   while d.month == month:
      days.append(d)
      d += timedelta(days = 7)
   return days

def getTeenthDay(days):
    for d in days:
            if d.day >= 13 and d.day <= 19:
                return d

