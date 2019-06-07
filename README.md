## Table of Contents
 1. [Exam-Checker](#exam-checker)
 2. [Model](#model)
     1. [Exams](#exams)
     2. [Multiple-choice questions](#multi)
     3. [True or False](#tf)
     4. [Exceptions](#exp)
 4. [View](#gui)
 5. [Compiling and executing](#comp)

# Exam-Checker <a name="exam-checker">
**Exam-checker** is a C++ application made to aid the grading of exam papers composed by multiple choice questions and true or false questions.
    
The whole application works in Italian, since it was commissioned by an Italian University professor.
It does not have a GUI such as an application window composed by graphic elements, it is implemented entirely inside the command line.
    
It was made using a simplified version of the MVC design pattern, using only the *Model* and the *View*.
It works by asking the user how many questions of (multiple choice / true or false) there are; then it asks the user to select the score of each answer, and then it lets the user grade the test, making them select which answer the student selected for each question. Then, when the user is done inserting the answers, it tells them the final grade.
    
An essential part of this project was the ability of creating a `.txt` file where the program saves the exam: for each multiple-choice question and true or false questions it saves the values for each answer and the correct answer, respectively (the multiple-choice quesitions vary inside a range of [-2,2] points; the true or false questions can obviously only be true (V) (*True*, "vero" in Italian) or false (F)). When the `exam.txt` file is created, the user can access it at any moment, and edit any score that might have been entered uncorrectly.
    
The application, therefore, can also load already existing exams, so that the user does not need to go through the whole process of assigning again the scores and the correct answers. 
    
If needed, the user can also skip the process of creating the exam through the application: they can create any `.txt` file and, if they respect the syntax that the program needs to deserialize the file, add all the answers manually.
The syntax of the `Name of the exam.txt` file is the following:
    
    # Name of the exam
    D|N|P|P|P|P
    V|N|A
    
The name of the exam is a string, so it can contain spaces. In the immediate following lines, everything is seen as a `string`, but there mustn't be any spaces between the characters nor at the end of any line. Firstly, the program saves the multiple-choice questions, which are *Domande*, so the first character of the row **must be** a **D**. The next character is the *number* of the question: they start at 1, and increase by +1 every time a new question is created, represented by the *N* in the example above. Next, the *P*s rapresent the *points* each answer has: P can only assume values inside the [-2,2] range. The first character of true or false questions **must be** a **V**, which stands for *true*(*vero*); next there is the number of the question, just like the multiple choice questions, and the A can only be either *V* or *F* (capital letters).

After the user has a `.txt` file created following the correct syntax, when starting the application they can instruct it to load it and resume the grading without recreating the whole exam by hand.

## Model <a name="model">
    
### Exams
It is composed by *Exams*, which are implemented through the `esame` class (*exam*). Exams are seen as a collection of questions: they are implemented through two `std::vector`, one for the multiple choice questions, and one for the true or false questions. 

Inside the `esame` class you can insert the questions inside their own vectors, and calculate the grading of the test: it initially keeps the grading of the multiple-choice section and the true or false section separate, and when the user is done it adds them together, and calculates the final grade.
    
### Multiple-choice questions <a name="multi">
They are implemented through the `domanda` class (*question*). They are identified by their number (is it the first question, or the 34th?) and the score that each answer has. 

### True or false <a name="tf">
They are implemented through the `verofalso` class (*truefalse*). Each `verofalso` object is identified by its number (just like `domanda` objects) and by the fact that it can either be true (V) or false (F).

### Exceptions <a name="exp">
They are implemented through the `exp` class. They handle these cases:
    * the user has tried to load a non-existing exam 
    * the user has inserted the wrong score to a question/true or false
    * the user has selected an answer that does not exist
When an exception such as these is caught, the user is prompted to repeat the action they just performed, knowing that there was en error, communicated through a `std::cerr` message.

## View <a name="gui">
**Exam-Checker** works exclusively through terminal, but a class `gui` still needed to be created. It handles every message that the user sees on screen, except for the exceptions and their `std::cerr`.
    
When the user first opens up the application, the first message that appears on the command line asks the user if they want to create a new exam (in which case, they need to press the N key) or an old one (V key). If they decide to create a new one, the application starts the process of creating a brand new exam, asking the user to insert how many multiple-choice questions there are, and then for each question it asks the user to insert the score of the question. If the user inserts a score that is not -2, -1, 1, or 2 the applications throws an exception and asks the user to reinsert the value. 

After the user has inserted the value of each answer to every question, the application asks them how many true or false questions there are in the exam, and for each one of them it asks the user wether the question was true (V) or false (F). These values need to be upper case. If the user makes a mistake (lower case letters, or a letter that is neither V nor F), the command line shows an error message and asks them to reinsert the correct value.

After the creation of the exam there is the correction part: here the user is asked to insert the answer that the student has chosen in each and every question. If a multiple-choice question was left blank its score is 0, and the user needs to insert **5** into the command line. If a true of false was left blank, the user needs to insert a **S** into the command line.

After the process of inserting the selected answers has ended, the user is presented with the total grade of the exam, and the score expressed in /30.
    
## Compiling and execution <a name="comp">
    
**On UNIX**

Inside Terminal:
    
```
g++ exam-checker_path -o exam-checker

./exam-checker
```

**On Windows**

Inside a Unix Terminal Emulator (cygwin64):
    
```g++ -static -static-libgcc -static-libstdc++ *.cpp -o exam-checker.exe```
    
The ```cygwin1.dll``` file needs to be in the same folder as the ```.exe``` file.
