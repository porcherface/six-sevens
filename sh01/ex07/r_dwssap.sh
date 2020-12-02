cat /etc/passwd | grep -v '^#' | awk 'NR % 2 == 1'  | cut -d: -f1 | rev | sort -r | sed -n '$FT_LIN1E , $FT_LINE2 p , ' | tr '\n' ',' | print "."
