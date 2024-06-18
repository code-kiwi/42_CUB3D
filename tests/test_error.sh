if [ $# -eq 2 ]; then
	for file in `ls $1/map_error`; do
		echo $file
		if [ "$2" = "true" ]; then
			valgrind ./cub3D "$1/map_error/$file"
		else
			./cub3D "$1/map_error/$file"
		fi
		read -n1
	done
else
	echo "expected 2 arguments : path to test.sh and true for valgrind"
fi
