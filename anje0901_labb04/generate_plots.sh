#!/bin/sh

# Ser till att results_final.csv är tom
printf '%s' "$x" > results_final.csv

for i in Bubblesort Insertionsort Selectionsort; do
  K=$(grep "$i" results.csv \
    | awk '{ print $3/($2^2) }' \
    | awk '{ sum += $1 } END { print sum/8 }')

  grep "$i" results.csv \
    | awk -v var="$K" '{ printf "%d\t%.2f\t%.2f\n", $2, $3, var*$2^2 }' \
    > plotdata_${i}.csv
  grep "$i" results.csv \
    | awk -v var="$K" '{ printf "%s\t%d\t%.2f\t%.2f\n", $1, $2, $3, var*$2^2 }' \
    | sort -n -k 2,2 \
    >> results_final.csv
done

# Quicksort
K=$(grep Quicksort results.csv \
  | awk '{ print ($3*log(2))/($2*log($2)) }' \
  | awk '{ sum += $1 } END { print sum/8 }')

# log2(n) = log(n)/log(2)
grep Quicksort results.csv \
  | awk -v var="$K" '{ printf "%d\t%.2f\t%.2f\n", $2, $3, var*$2*(log($2)/log(2)) }' \
  > plotdata_Quicksort.csv

grep Quicksort results.csv \
  | awk -v var="$K" '{ printf "%s\t%d\t%.2f\t%.2f\n", $1, $2, $3, var*$2*(log($2)/log(2)) }' \
  | sort -n -k 2,2 \
  >> results_final.csv

gnuplot plot.plt
