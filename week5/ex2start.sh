#Prepare ex2test file
#If you do not want it to make new file and want to edit existing one instead, please delete code before next block.
echo "! Script make new ex2test file. For details please read readme.txt"
rm ex2test
touch ex2test
echo 0 >> ex2test
#Start script in foreground and background
bash ex2.sh &
bash ex2.sh 

