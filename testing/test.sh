if [ -z $1 ] || [ "$1" = -v ]; then
	echo must enter a valid list length
	exit 1
fi
make -f Makefile
P_SCRIPT=$(echo "$0" | sed -e "s/test.sh$/rand.py/")
ARG=$(python $P_SCRIPT $1)
if [ "$2" = -v ]; then
	./push_swap $ARG
	echo $ARG
fi
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l
