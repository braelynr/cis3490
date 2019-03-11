Braelyn Rotman
1006740
March 10th, 2019
A3 readme.txt

___________________________________________
README.TXT CONTENTS
___________________________________________
1. Included Files
2. Running Instructions
3. Assumptions Made + Notes
4. Comparion & Analysis
5. Sample Outputs

___________________________________________
INCLUDED FILES
___________________________________________
makefile
main.c
P11.c
P12.c
P21.c
P22.c
P23.c
readme.txt

___________________________________________
RUNNING INSTRUCTIONS
___________________________________________
To Compile:
  Type "make" or "make all"
To Run:
  Type "./run"

Q1.1 can take up to 30 minutes for a 10 character input string
Comment out these lines in main.c to skip over questions:
  1.1 - line 52
  1.2 - line 53
  2.1 - line 100
  2.2 - line 101
  2.3 - line 102

___________________________________________
ASSUMPTIONS MADE + NOTES
___________________________________________
Overlapping patterns:
  If pattern = 11 and text = 11111
  # of occurences = 2

Multiple Occurences of anagrams:
  If search string = 123 and text = 213 123 213
  # of anagrams = 2
___________________________________________
COMPARISON & ANALYSIS
___________________________________________

Ratio: pattern shifts : run time (milliseconds)

Brute Force:
  1. Search Pattern: Euro
     Matches: 14
     Ratio: 3294546:9
  2. Search Pattern: winter
     Matches: 87
     Ratio: 3294151:15
  3. Search Pattern: course
     Matches: 1620
     Ratio: 3286486:115
  4. Search Pattern: information
     Matches: 171
     Ratio: 3292871:28
  5. Search Pattern: University
     Matches: 2345
     Ratio: 3273477:141
  6. Search Pattern: go
     Matches: 1323
     Ratio: 3293267:77
  7. Search Pattern: health
     Matches: 108
     Ratio: 3294046:17
  8. Search Pattern: safety
     Matches: 12
     Ratio: 3294526:11
  9. Search Pattern: grading
     Matches: 14
     Ratio: 3294501:11
 10. Search Pattern: detail
     Matches: 49
     Ratio: 3294341:14

Horspool:
  1. Search Pattern: Euro
     Matches: 14
     Ratio: 868266:8
  2. Search Pattern: winter
     Matches: 87
     Ratio: 662710:11
  3. Search Pattern: course
     Matches: 1620
     Ratio: 612661:110
  4. Search Pattern: information
     Matches: 171
     Ratio: 390764:22
  5. Search Pattern: University
     Matches: 2345
     Ratio: 427600:132
  6. Search Pattern: go
     Matches: 1323
     Ratio: 1655659:84
  7. Search Pattern: health
     Matches: 108
     Ratio: 638945:10
  8. Search Pattern: safety
     Matches: 12
     Ratio: 656233:5
  9. Search Pattern: grading
     Matches: 14
     Ratio: 564283:6
 10. Search Pattern: detail
     Matches: 49
     Ratio: 658811:9

Average Ratio = Sum of Ratios/# of Ratios
Average Ratios:
  Brute Force - 3291221.2:43.8
  Horspool    -  713593.2:39.7

Analysis:
  Brute force and horspool have very similar runtimes for any input string
  length however horspool is almost always faster but only by a few
  milliseconds which is seen in the average ratios. Brute force has to do
  significantly more shifts than horspool making it more inefficient and
  contributing to the longer run time. Based on the average ratio, horspool
  does less than a third of the shifts that brute force does. This makes sense
  since brute force only shifts by an index of 1 every time while horspool
  tries to make as large a shift as possible without risking skipping over
  matching patterns.


___________________________________________
SAMPLE OUTPUTS
___________________________________________

Question 1.1 sample outputs:

./run
Q1: Enter a string: 1234567890
-----Question 1.1-----
Anagram List:
  1475369028
  2036584179
  1750648392
  1876495230
  1534092876
  1586732092
  1945786032
Total Number of Anagrams: 7
Algorithm Time: 1830467 milliseconds

./run
Q1: Enter a string: 623897407
-----Question 1.1-----
Anargam List:
  478307629
  672804793
  768047293
  276739408
Total Number of Anagrams: 4
Algorithm Time: 235368 milliseconds


Question 1.2 sample outputs:

./run
Q1: Enter a string: 1234567890
-----Question 1.2-----
Anagram List:
  1475369028
  2036584179
  1750648392
  1876495230
  1534092876
  1586732092
  1945786032
Total Number of Anagrams: 7
Pre-Sorting Time: 21 milliseconds
Algorithm Time: 2 milliseconds

./run
Q1: Enter a string: 623897407
-----Question 1.2-----
Anargam List:
  478307629
  672804793
  768047293
  276739408
Total Number of Anagrams: 4
Pre-Sorting Time: 20 milliseconds
Algorithm Time: 1 milliseconds


Question 2.1 sample outputs:

./run
Q2: Enter a pattern: Euro
-----Question 2.1-----
Total Number of Matches: 14
Number of Shifts: 3296589
Algorithm Time: 9 milliseconds

./run
Q2: Enter a pattern: Winter Semester
-----Question 2.1-----
Total Number of Matches: 19
Number of Shifts: 3296578
Algorithm Time: 10 milliseonds


Question 2.2 sample outputs:

./run
Q2: Enter a pattern: Euro
-----Question 2.2-----
Total Number of Matches: 14
Number of Shifts: 868548
Algorithm Time: 7 milliseconds

./run
Q2: Enter a pattern: Winter Semester
-----Question 2.2-----
Total Number of Matches: 19
Number of Shifts: 314026
Algorithm Time: 6 milliseonds


Question 2.3 sample outputs:

./run
Q2: Enter a pattern: Euro
-----Question 2.3-----
Total Number of Matches: 14
Number of Shifts: 868280
Algorithm Time: 9 milliseconds

./run
Q2: Enter a pattern: Winter Semester
-----Question 2.3-----
Total Number of Matches: 19
Number of Shifts: 304445
Algorithm Time: 3 milliseonds
