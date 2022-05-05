awk '{print $1}' md5.s |
awk '$0 !~ /\./' |
awk '$0 !/main/ && !/[_#]/' |
sort |
uniq -c |
sort -nr |
awk '{ $1=$1","; print $1,$2 }'  > instructionsCounter.csv
