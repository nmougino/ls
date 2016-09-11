# ls
Educational project

#### Subject options:

* -a : Include directory entries whose names begin with a dot (.).

* -l : (The lowercase letter "ell".)  List in long format.  (See below.)  If the output is
		to a terminal, a total sum for all the file sizes is output on a line before the long
		listing.

* -R : Recursively list subdirectories encountered.

* -r : Reverse the order of the sort to get reverse lexicographical order or the oldest
		entries first (or largest files last, if combined with sort by size

* -t : Sort by time modified (most recently modified first) before sorting the operands by
		lexicographical order.

#### Implemented bonuses:

* High speed

* -F : Display a slash / immediately after each pathname that is a directory, an asterisk
		\* after each that is executable, an at sign @ after each symbolic link, an
		equals sign = after each socket, a percent sign % after each whiteout, and a
		vertical bar | after each that is a FIFO.

* -f : Output is not sorted.  This option turns on the -a option.

* -n : Display user and group IDs numerically, rather than converting to a user or group name
		in a long (-l) output.  This option turns on the -l option.

* -p : Write a slash (/) after each filename if that file is a directory.

* -u : Use time of last access, instead of last modification of the file for sorting (-t) or
		long printing (-l).

* -U : Use time of file creation, instead of last modification for sorting (-t) or long output
		(-l).

#### Details:

Instead of using -t in addition of -u and -U to use them, ./ft_ls can directly use -u and -U to sort files without have to put -t.
