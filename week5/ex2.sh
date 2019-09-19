#single execution of given task with race
for i in `seq 0 255`;
do
	processing=`tail -1 ex2test`
	let "processing=processing+1"
	echo $processing >> ex2test
done
