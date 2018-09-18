# Instructions

Download C tutorial for Java Programmers and the file with the supporting source code and unpack them to a directory for this lab (e.g., ~/comp232).
NOTE: ~/ in Unix means "home directory" -- that is the directory to which the system takes you after you log in.
All source C files are in the src sub-directory. The file CMakeLists.txt in the root directory contains instructions how to compile the code in the tutorial. Please select "Reload CMake Project" from the File menu to adapt the configuration to your computer and your environment.
The configurations to run various files in the tutorial are pre-defined; they are available in the drop down menu in the top bar of CLion. To run one of the programs, select an appropriate configuration in the upper right corner of CLion, and then click the Run (a green triangle) or Debug (green "bug") icon in the top bar, or select the corresponding item in the Run menu.

#Question 1

Open CLion, and then select Open File from the File menu. Navigate to the root directory of the tutorial and open it.
You should seethe The file CMakeLists.txt in one editor pane, and the file hello.c in another. If you don't, double-click on the hello.c file in the left project pane list of the files to open it.
Now, select "hello" from the drop-down configuration menu and run the hello program by clicking on the Run icon, or clicking on the Debug icon, or selecting corresponding items from the Run menu.
The configurations instruct CLion to re-build the executables before running. That can also be done manually by selecting Clean item from the Run menu, and then selecting Build item from the same menu.
Examine the code of the program and verify that the output reflects the program's logic.

# Question 2

Modify the code in types.c, so that the program asks also for the number of faculty, and then prints the student-to-faculty ratio for CSUCI. You will need to modify the types of the variables and use proper format string in printf(), so the precision is limited to one position after the dot.
You may use man pages to get help on C functions and on system calls. You many want to explore:

>   $ man printf
>   $ man scanf
>   $ man getc

You may also get the same help inside CLion by positioning the cursor on a function and then using F1 key.

# Question 3

Modify the code in if-then-else.c, so the value of level is read from the standard input.

Question 4
Modify array.c so that the program reads a number of doubles from the standard input and computes their average.
The number of the doubles to process should be read from the standard input. It will be followed by the corresponding number of doubles. For example:

>   Provide a desired number of doubles?
>   5
>
>   Provide the doubles?
>   1.0 2.0
>   3.0
>   4.0 5.0

Note that scanf() will search for doubles in the standard input independent of the placement input line.
A maximum number of doubles that the program can handle is defined by a define MAX_NUM_OF_CELLS. Your program should create an array with that many elements, but then verify that the number entered by the user is no larger than the limit. If it is, then a warning message should be printed, and the number should be assumed to be the said MAX_NUM_OF_CELLS.
The program should print all the numbers in one line separating them by spaces, and follow with the second line with the average. For example, the following could be one output:

>   Data: 1.0 2.0 3.0 4.0 5.0
>   Average: 3.0
>   Question 5

Examine the code in strings.c, pointer.c, and mem-alloc.c. Then, set breakpoints at the beginning of the main() function, and execute the program. When the program stops at a breakoint, continue the execution by stepping through the instructions. At each step, examine the current values of the variables and make sure that you understand what is going on. Ask the instructor for explanation if you do not.
Using strings.c, pointer.c, and mem-alloc.c as prototypes, implement a new program in file words.c. The new program should:

- read words from the standard input in a loop until a word END  is read,
- count all read words,
- store the words in an array of strings, and
- print the number of read words in the first line followed by the whole array with one word per line. For example:

>   The following 3 words have been read:
>   veni
>   vidi
>   vici

You should create an array of pointers to strings that will hold pointers to the read words. Set the size of the array to an arbitrary number of the words that the program can process; that number should be defined with #define. To start with, the array will not have any valid pointers, so you must allocate space to hold read words with malloc(). Each word will have a different length, so you must use a buffer (an array of characters) that will hold the line that is read from the input with scanf(), and then use strlen() to find out how long is the word in the buffer. With that length, you will know for how large storage you should ask in malloc(), so that it can hold the word. Keep in mind that strlen() returns the number of characters in the buffer excluding the end-of-string marker ('\0'); therefore, you must request one character more from malloc(). Subsequently, use strcpy() to copy the new word from the buffer into the newly allocated space and set the current element of the words array to point to that space.
You many want to explore:

>   ```
>   $ man scanf
>   $ man malloc
>   $ man strlen
>   $ man strcpy
>   $ man strcmp
>   ```

# Question 6

In this task, you will modify file.c program.
First, create a file call data.txt with the following content:

>   Hello there!

in the sub-directory cmake-build-debug by right-clicking on the name of the sub-directory in the left-side project pane, left-clicking on New from the pop-up menu, and finally selecting File from the secondary pop-up menu. Enter the file name, and then the file content in the editor pane. Remember to save the file by clicking on the Save icon or selecting Save All from the File menu.
Extend the code in file.c, so that the program reads the data from the data.txt file and writes it to a new file. The name of the new file should be requested from the user.
Please note that the executables in our configuration of CLion are created in the sub-directory cmake-build-debug, so by default any output file will also be generated in there.
You can overwrite the default location of input and output files. For example, to use a file in the src directory, prefix the file name with ../src/.
You many want to explore:

>   $ man fgetc
>   $ man fputc
>   $ man fopen
>   $ man fclose
>   $ man scanf

# Question 7

ptr-arg-2.c contains an implementation of a function swap_integers() that swaps values of two integers using their pointers. Add a function swap_strings() that will swap two strings. The new code should include:
a declaration of the new function,
declarations of two strings initialized to some arbitrary values, and
the definition of the function that swaps the strings.
Please do not use strcpy(); rather, you should just swap the pointers.
Things start to get tricky here, so using the debugger is indispensable.

# Question 8

Starting with the code in ptr-func.c, create a file calc.c that implements a simple calculator utility that performs four basic operations: + - / * on two operands. The program should prompt the user for the operation to perform in an endless loop. For example:

>   calc> 3 + 6
>   9
>   calc>

You must implement the calculator in such a way that there is one function calc(...) that takes a pointer to the actual function that performs the specified operation (add() sub() mult() div()), and two operands.

# Question 9

Using struct.c, as a starting point, implement an application that creates a database of employee personal records. Your implementation should follow these guidelines:

- the definition of the structure PERSON should be provided in an h-file called person.h that you need to create in the src sub-directory,
-- for the content, refer to the lecture notes,
- typdef is used for referencing the PERSON structure,
- an array employees[] is declared in the main C file (that is struct.c), but is also used in a new C file person.c that you need to create as well; person.c should include implementations of the following functions:
- add_employee() to read the person data from the standard input and to add it to the array,
- display_employee() to display the data for a single employee,
- display_all_employees() to display data for all employees,
- the main program should read in the data for a number of employees by first prompting the user for the number of employees, allocating sufficient space for the employees in the array, and then calling the add_employee() function to populate the current element of the array.
Here are the signatures of the functions that must be declared in person.h and defined in person.c:

>   void add_employee(PERSON *);
>   void display_all_employees(PERSON *[]);
>   void display_employee(PERSON *);

To compile the new person.c along with the struct.c, you need to modify the configuration file CMakeLists.txt in the root directory of the project by changing this line:

>   add_executable(struct src/struct.c)

to:

>   add_executable(struct src/struct.c src/person.c)

# Question 10

Implement a program that processes batches of messages in a loop as follows:

- reads a message from the standard input into input_buffer,
- collects the messages in message_cache using the function add_message_to_cache() that takes input_buffer as a parameter,
- when needed as explained in the next bullet, invokes a function message_dispatcher() to process a batch of messages that are in the cache one by one using the function process_message(), and
- continues to take batches of messages from the input until either:
- the capacity of the cache (arbitrarily chosen to be some fixed value; for example 16) is reached in which case the message dispatcher should be called to process the messages in the buffer, and then to continue reading messages, or
- a line with a sentinel END is read, in which case the program should process all remaining messages in the cache, and then terminate.
There should be one message per line of input. Messages can be in a number of formats:

```
TYPE 1: a string of unknown size
TYPE 2: 5 integers
TYPE 3: 4 floating point numbers
TYPE 4: 5 five-character words
The input should indicate the type of the message and the content; e.g.:

1 abcdefghijklmnopqrst
3 123.34 23.12345 5439.234 0.000231
4 aaaaa bbbbb ccccc ddddd eeeee
2 123 45 6 7890 87592
```

After receiving the sentinel your program should finish processing the messages in the buffer and print processing statistics:
- the number of batches (including the last one even if incomplete),
- the total number of messages processed, and
- the number of messages of each type.
The process_message() function should be invoked from message_dispatcher() for each message in the cache. It should take a single parameter that is the next message from the cache to process. It should recognize what type the message has, and then print the message type along with its content as follows:
- for type 1, the complete string,
- for type 2, all integers separated by commas,
- for type 3, all floating numbers separated by a slash, and
- for type 4, all words separated by spaces.
For example:

```
TYPE 1: abcdefghijklmnopqrst
TYPE 2: 123,45,6,7890,87592
TYPE 3: 123.34/23.12345 5439.234 0.000231
TYPE 4: aaaaa bbbbb ccccc ddddd eeeee

Number of message batches: 1
Messages processed:
Total: 4
Type 1: 1
Type 2: 1
Type 3: 1
Type 4: 1
```

The cache should be implemented as an array of the struct contructs that include two fields: one for the type of the message and the second should be a union construct to hold the content of the message that is specific to its type. An unsigned short should be used as the data type for the message type field. The type should be used in a switch statement to save the message in the union according to the message type.
processor.c should contain a global declaration of the message cache and a global declaration of a number of messages read, as well as implementations of the functions add_message_to_cache() and message_dispatcher(), and process_message().
add_message_to_cache() should use sscanf() to read the type of the message and the message content from the parameter. To do that, an appropriate pattern for sscanf() needs to be designed. A switch statement should be used to select proper handler for each message type.
The program must use dynamic allocation for storing messages of type 1. The memory allocated for that purpose must be freed after the message is processed.
You should have processor.h file for declarations of data structures and declarations of common functions.
test_processor.c should include the main() with the testing driver that implements the main loop of the application.
