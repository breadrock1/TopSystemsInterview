# TopSystems interview test case

So, there is simple project to demonstrate my C/C++ skills while processing 
interview. There is no clear code because i was writing it for about a one 
hour. I just wanna save it here to dilute program languages statistic of my 
account.  

## The technical task.

If there is no ready-made example, then I can offer to complete our 
task. The task is:

Using the Qt library (Widgets) and the C++ standard library, develop 
an application that will count the number of correct and incorrect 
user responses. The correct answer is the case when the user clicked 
the mouse exactly the right number of times during the display of the number. 
For example, if the user sees the number "3" in the corresponding field, 
he must click the left mouse button three times before changing the number. 
If, after changing the number in the corresponding field, the number of clicks 
corresponded to the number shown, then the counter of correct answers increases. 
If not, then the counter of incorrect answers is increased. The change of the 
number must occur explicitly for the user, i.e. if after the number "3" the 
number "3" appears again, the user must understand that this is already a new 
number. The choice of the next number to display is random within a given range 
of numbers.

The application should have one main window divided into three parts. One part 
should have two buttons: Start and Stop. The second should have a field that 
will display the number of clicks to be made. In the third part, there are two 
counters - a counter of correct and a counter of incorrect answers. The number 
in the number field should change every 2 seconds. After pressing the Start button, 
the “Game” begins and the counters are reset. After pressing the "Stop" button, 
the "game" stops. When you close the app, a dialog should be shown that says "Come 
again." and the "I will definitely come" button. After clicking on the button, the 
application is permanently closed. Ambiguities in the problem can be interpreted 
in any way.
