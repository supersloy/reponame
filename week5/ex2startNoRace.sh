#Prepare ex2testNoRace file
#If you do not want it to make new file and want to edit existing one instead, please delete code before next block.
echo "! Script make new ex2testNoRace file. For details please read readme.txt"
rm ex2testNoRace
touch ex2testNoRace
echo 0 >> ex2testNoRace
#Start script in foreground and background
bash ex2norace.sh &
bash ex2norace.sh
