#Tworzymy fifo używając komendy:
#mknod fifo p
#oraz cztery skrypty:

#pisz.sh
================================
#!/bin/bash
while true;
do
echo "cos"
sleep 2
done
================================


#pisz1.sh
================================
#!/bin/bash
while true;
do
echo "napis"
sleep 1
done
================================

#czytaj.sh oraz identyczny czytaj1.sh
================================
#!/bin/bash
while true;
do
cat fifo
done
================================

#za pomocą polecenia:
#./pisz.sh | cat > fifo
#przkazujemy odczyt z pliku pisz.sh do fifo
#analogicznie dla pisz1.sh w 2. terminalu

#w 3. i 4. wywołujemy czytanie z potoku za pomocą skryptów czytaj.sh oraz czytaj1.sh


#WNIOSKI
