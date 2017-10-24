def is_leap_year(year):
	if year % 400 == 0: return 1
	elif year % 100 == 0: return 0
	elif year % 4 == 0: return 1
	else: return 0

months_length = [0,31,28,31,30,31,30,31,31,30,31,30,31]
current_year = 1900
current_month = 1
current_date = 1
days_count = 0
sundays = 0

while current_year < 2001:
	if current_date == 1 and days_count % 7 == 6 and current_year > 1900:
		sundays += 1
	days_count += 1

	if current_month == 12 and current_date == months_length[current_month]:
		current_year += 1
		current_month = 1
		current_date = 1
	elif current_month == 2 and is_leap_year(current_year) and current_date == 28:
		current_date += 1
	elif current_month == 2 and current_date == 29:
		current_date = 1
		current_month += 1
	elif current_date == months_length[current_month]:
		current_month += 1
		current_date = 1
	else:
		current_date += 1

print(sundays)