//Modify this file to change what commands output to your statusbar, and recompile  using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"Mem: ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},

	{"", "date '+%b %d (%a) %I:%M%p'",					5,		0},

	//the following removes all info from the upower command but XX%
	{"Int. Bat: ", "upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep percentage: | sed  's/percentage://g' | sed 's/ //g'", 15, 0},

	{"Ext. Bat: ", "upower -i /org/freedesktop/UPower/devices/battery_BAT1 | grep percentage: | sed  's/percentage://g' | sed 's/ //g'", 15, 0},

	//removes everything but X.Xh
	//note that TLI may show nothing when not depleting.
	{"TLI: ", "upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep 'time to empty' | sed  's/time to empty://g' | sed 's/ //g' | sed -r s'/ours//'g", 60, 0},


	{"TLE: ", "upower -i /org/freedesktop/UPower/devices/battery_BAT1 | grep 'time to empty' | sed  's/time to empty://g' | sed 's/ //g' | sed -r s'/ours//'g", 60, 0},

};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
