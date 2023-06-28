Goal:- The objective of this program is to develop a multi-threaded solution to find a 
list of perfect numbers. <br>
Details:- N is a perfect number if the sum of all its factors, excluding itself, is N; 
examples are 6 and 28. <br>

The main thread will read the numbers N and K from an input file. The main thread will 
create K threads. <br>
The numbers from 1 to N will be partitioned among these threads so that two threads do 
not work on the same number. Thus each Thread T; will be responsible for a set of 
numbers. For each number in its set, the thread T, will determine if the number is a 
perfect number or not. If it is T; will store it locally. After completion, T; will share the set 
of numbers it identified with the main thread. <br>

The main thread will wait until all the threads complete their respective execution. It will 
then consolidate all the perfect numbers identified and computed by other threads in a 
single output file. <br>
Input File:- As mentioned above, the input will consist of two parameters N and K. 
Output File:- For ease of understanding, each thread T; will also create a log file, 
OutFile; onto which it will store all the details of its execution. It will log each number it 
tests and the output it generates. Suppose T; tests the number 1 to 10, then a sample 
output can be as follows: <br>
1: Not a perfect number <br>
2: Not a perfect number<br>
.... <br>
6: Is a perfect number <br>
....<br>
On similar lines, the main thread will create a log file OutMain which will consist of all 
the perfect numbers less than N and the thread that identified it. A possible output 
format for two threads is as follows: <br>
Thread1: num1 num2 .... <br>
Thread2: num5 num6 .... <br>
