#single execution of given task without race (when we start this script in background and foreground)
if ln ex2testNoRace ex2testNoRace.lock
then                               
	for i in `seq 0 255`;
	do
		processing=`tail -1 ex2testNoRace`
		let "processing=processing+1"
		echo $processing >> ex2testNoRace
	done
	rm ex2testNoRace.lock
else
	echo "Ignore previous message. It does not have any side affect."
	sleep 1
	bash ex2norace.sh
fi
