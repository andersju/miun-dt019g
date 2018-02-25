#set terminal png size 1800,1200 crop enhanced font "/home/andersju/.fonts/TTF/Merriweather-Regular.ttf,30" dashlength 2
set terminal png size 1800,1200 crop enhanced font ",30" dashlength 2
set termoption linewidth 3

set style line 1 linecolor rgb '#de181f' lw 2 pt 13 ps 4 linetype 1  # Red
set style line 2 linecolor rgb '#0060ae' lw 2 pt 5 ps 4 linetype 1  # Blue
set style line 3 linecolor rgb '#228C22' lw 2 pt 2 ps 4 linetype 1  # Forest green
set style line 4 linecolor rgb '#18ded7' lw 2 pt 10 ps 4 linetype 1  # opposite Red
set style line 5 linecolor rgb '#ae4e00' lw 2 pt 3 ps 4 linetype 1  # opposite Blue
set style line 6 linecolor rgb '#8c228c' lw 2 pt 4 ps 4 linetype 1  # opposite Forest green

#set xrange [0:40000]
#set xtics (0,5000,10000,15000,20000,25000,30000,35000,40000)
#set yrange [0:15]
#set title "Sorteringstid vs. arraystorlek"
set key top right
set ylabel "Genomsnittlig sorteringstid (ms)"
set xlabel "Arraystorlek"

set output "plot_bubblesort.png"

plot \
  'plotdata_Bubblesort.csv' using ($1):($2) title "Bubblesort" \
    with linespoints ls 2, \
  'plotdata_Bubblesort.csv' using ($1):($3) title "O(n^2)" \
    with linespoints ls 1

set output "plot_insertionsort.png"

plot \
  'plotdata_Insertionsort.csv' using ($1):($2) title "Insertionsort" \
    with linespoints ls 2, \
  'plotdata_Insertionsort.csv' using ($1):($3) title "O(n^2)" \
    with linespoints ls 1

set output "plot_quicksort.png"

plot \
  'plotdata_Quicksort.csv' using ($1):($2) title "Quicksort" \
    with linespoints ls 2, \
  'plotdata_Quicksort.csv' using ($1):($3) title "O(n*log(n))" \
    with linespoints ls 1

set output "plot_selectionsort.png"

plot \
  'plotdata_Selectionsort.csv' using ($1):($2) title "Selectionsort" \
    with linespoints ls 2, \
  'plotdata_Selectionsort.csv' using ($1):($3) title "O(n^2)" \
    with linespoints ls 1

set output "plot_alla.png"

plot \
  'plotdata_Bubblesort.csv' using ($1):($2) title "Bubblesort" \
    with linespoints ls 1, \
  'plotdata_Insertionsort.csv' using ($1):($2) title "Insertionsort" \
    with linespoints ls 2, \
  'plotdata_Quicksort.csv' using ($1):($2) title "Quicksort" \
    with linespoints ls 3, \
  'plotdata_Selectionsort.csv' using ($1):($2) title "Selectionsort" \
    with linespoints ls 4
