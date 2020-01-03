while true;
do
	./data>data.in
	time ./3493<data.in>1.out
	time ./34933<data.in>2.out
	if diff 1.out 2.out;then
		echo AC
	else
		echo WA
		read p
	fi
	sleep 1
done

#/usr/bin/time -f "real %f"
