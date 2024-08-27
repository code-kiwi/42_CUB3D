if [ -z "$2" ] ; then
	echo "You have to enter the executable path as the first parameter";
	exit ;
fi

if [ -z "$1" ] ; then
	echo "You have to enter the map folder as the second parameter";
	exit ;
fi

for f in "$2"/*; do
	echo "$f"
	if [ -n "$3" ]; then
		valgrind ./"$1" "$f"
	else 
		./"$1" "$f"
	sleep 1
	fi
done
	