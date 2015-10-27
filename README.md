# LaserTanks

The Arduino directory contains the code to be built and deployed to the arduino "tanks".

The Raspberry Pi directory contains the code to be built and deployed to the raspberry Pi.

###Arduino setup
1) Download the RF24 repository zip file from this location https://github.com/TMRh20/RF24 and include it as a library for your Arduino IDE.  

2) Remove the Robot IR Remote library that comes with the Arduino IDE.  It conflicts with the library we want to use.<BR>
<B>Mac</B>: Applications/Arduino (right mouse click -->show package contents) /Contents/Java/libraries/RobotIRremote
<B>Windows</B>: C:\Program Files (x86)\Arduino\libraries\RobotIRremote
<BR>
Once you have located the folder RobotIRremote, delete it. Restart the Arduino IDE and your RobotIRremote library should be gone. 

3) Download the IRRemote library from here: https://github.com/z3t0/Arduino-IRremote and include the ZIP as a library for your Arduino IDE.

4) The tank1 and tank2 sketches should now compile and be able to be deployed to the tanks.

###Raspberry Pi setup
1) Download the RF24 github repository as a zip file from this location to your Raspberry pi, uncompress it to your Rpi.

2) Download the Laser Tanks Repository to your raspberry Pi.

3) Copy the senddata.cpp from the Laser Tanks repository under the Raspberry Pi directory above to the Examples_RPi directory created when you uncompressed the RF24 repository.

4) Modify the Make file to include compiling the senddata.cpp in addition to the other files by modifying the Makefile in the Examples_RPi directory from:

PROGRAMS = gettingstarted gettingstarted_call_response transfer pingpair_dyn

To:

PROGRAMS = gettingstarted gettingstarted_call_response transfer pingpair_dyn senddata

once you do this, you can now build the senddata executable by simple running "make" at the command line.
You can test the newly created senddata executable by running it at the command line:  senddata <tank#> <command#>

tank# can be 1 or 2

command# can be 1,2,3,4,5,6 (forward, backward, left, right, stop, fire)

5) Configure the NodeJS service.  Go to the cloned Laser tanks repository/Raspberry Pi and copy the senddata.cpp from the directory in step4 to this directory.   Modify AppServer.js to use the IP address of your raspberry pi.   Look for <REPLACE IP ADDRESS HERE> so the NodeJS AppServer will bind to your external IP address of your Pi

6) Startup the nodeJS app Server by typing "sudo nodejs AppServer.js"   You can test that the appserver is running but loading a browser window and hitting http://IP of RPi/webControlTank1.html and you can click the different buttons and it should run "senddata 1 <command#>" on the command line.

7) Now go to your computer with the leap motion installed and configured, load up a browser, and hit http://IP of RPi/lpControlTank1.html    Click the calibrate button, and identify to the leap motion where "neutral" position for your hands are.  Once done, both hands forward will identify forward, both back will identify backward, left forward right back will turn right, left back right forward will turn left, neutral will stop and one hand forward and dropping your other hand out of site will fire the cannon.

