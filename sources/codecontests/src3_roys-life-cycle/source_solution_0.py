def main():
	n = int(raw_input())
	strings = []
	string_streak = 0
	total_streak = 0
	for i in range(n):
		temp_string = raw_input()
		strings.append(temp_string)

	for string in strings:
		temp_string_streak = 0
		temp_streak = 0
		for char in string:
			if char == "E" or char == "S":
				if temp_streak > temp_string_streak:
					temp_string_streak = temp_streak
				temp_streak = 0
			if char == "C":
				temp_streak += 1
		if temp_streak > temp_string_streak:
			temp_string_streak = temp_streak
		if temp_string_streak > string_streak:
			string_streak = temp_string_streak
	
	total_string = ""
	for string in strings:
		total_string += string
	
	temp_streak = 0
	for char in total_string:
		if char == "E" or char == "S":
			if temp_streak > total_streak:
				total_streak = temp_streak
			temp_streak = 0
		if char == "C":
			temp_streak += 1
	if temp_streak > total_streak:
		total_streak = temp_streak
	print str(string_streak) + " " + str(total_streak)

if __name__ == "__main__":
	main()