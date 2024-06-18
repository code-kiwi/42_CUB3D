if [ $# -eq 2 ]; then
	for file in `ls $1/map_correct`; do
		echo $file
		if [ "$2" = "true" ]; then
			valgrind ./cub3D "$1/map_correct/$file"
		else
			./cub3D "$1/map_correct/$file"
		fi
		read -n1
	done
else
	echo "expected 2 arguments : path to test.sh and true for valgrind"
fi
